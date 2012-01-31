//  
//  Indicate.vala
//  
//  Author:
//       Jonas Frei <freijon@gmail.com>
// 
//  Copyright (c) 2011 Jonas Frei
// 
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
// 
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
// 
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>.

using Gtk;
using AppIndicator;
using Notify;

public class Indicate
{
	unowned Thread<void*> thread;
	private Indicator indicator;
	
	private Gtk.Menu menu;
	private Gtk.MenuItem how_many;
	
	private UpdateChecker checker;
	
	private const string ACTIVE_ICON = "/usr/local/share/update_indicator/software-update-available.png";
	private const string PASSIVE_ICON = "/usr/local/share/update_indicator/no-update-available.png";
	private const string GLADE_FILE = "/usr/local/share/update_indicator/UpdateIndicator.glade";
		
	public Indicate()
	{
		int check_interval = GConfInterface.get_int (GConfInterface.Key.CHECK_INTERVAL);
		
		indicator = new Indicator ("update-notifier", "update-indicator", AppIndicator.IndicatorCategory.APPLICATION_STATUS);
		set_icon(PASSIVE_ICON);
		indicator.set_status (GConfInterface.get_bool (GConfInterface.Key.SHOW_PASSIVE_ICON) ? AppIndicator.IndicatorStatus.ACTIVE : AppIndicator.IndicatorStatus.PASSIVE);
		
		checker = new UpdateChecker(check_interval);
		checker.update_event.connect(on_update);
		
		build_menu();
		
		if (Thread.supported())
		{
			try
			{
			thread = Thread.create<void*> (checker.check_for_updates, false);
			}
			catch (ThreadError e)
			{
				stderr.printf("Couldn't create thread\n");
			}
			
		}
		
		else
		{
			stderr.printf("Threading not supported. Aborting...\n");
			Gtk.main_quit();
		}
		
		Notify.init("Update Indicator");
		
	}
	
	private void build_menu()
	{
		menu = new Gtk.Menu ();
		
		how_many = new Gtk.MenuItem.with_label ("No updates available");
		how_many.sensitive = false;
		
		var menu_execute = new Gtk.ImageMenuItem.from_stock (Gtk.Stock.EXECUTE, null);
		menu_execute.activate.connect (on_execute_clicked);
		
		var menu_refresh = new Gtk.ImageMenuItem.from_stock (Gtk.Stock.REFRESH, null);
		menu_refresh.activate.connect (on_refresh_clicked);
		
		var menu_preferences = new Gtk.ImageMenuItem.from_stock (Gtk.Stock.PREFERENCES, null);
		menu_preferences.activate.connect (on_preferences_clicked);
		
		var menu_about = new Gtk.ImageMenuItem.from_stock (Gtk.Stock.ABOUT, null);
		menu_about.activate.connect (on_about_clicked);
		
		var menu_quit = new Gtk.ImageMenuItem.from_stock (Gtk.Stock.QUIT, null);
		menu_quit.activate.connect (Gtk.main_quit);
		
		menu.add (how_many);
		menu.add (new Gtk.SeparatorMenuItem());
		menu.add (menu_execute);
		menu.add (menu_refresh);
		menu.add (menu_preferences);
		menu.add (new Gtk.SeparatorMenuItem());
		menu.add (menu_about);
		menu.add (menu_quit);
		
		menu.show_all ();
		indicator.set_menu (menu);
	}
	
	private void on_update (UpdateChecker sender, string[] packages, int count)
	{
		if (how_many.get_submenu() != null)
		{
			how_many.submenu = new Gtk.Menu();
		}
		
		if (count > 0)
		{
			set_icon(ACTIVE_ICON);
			indicator.set_status (AppIndicator.IndicatorStatus.ACTIVE);
			
			how_many.label = count.to_string() + (count == 1 ? " update" : " updates");
			how_many.sensitive = true;
			
			var submenu_how_many = new Gtk.Menu();
			foreach (string package in packages)
			{
				submenu_how_many.add (new Gtk.MenuItem.with_label(package));
			}
			how_many.submenu = submenu_how_many;
			submenu_how_many.show_all ();
			
			if (GConfInterface.get_bool (GConfInterface.Key.NOTIFY))
			{
				string package_list = "";
				
				foreach (string package in packages)
				{
					package_list += ("- " + package + (package == packages[count - 1] ? "" : "\n"));
				}
				
				var notify = new Notification (count.to_string() + " new " + (count == 1 ? "update" : "updates") +
					" available", package_list, ACTIVE_ICON);
				try
				{
					notify.show ();
				}
				catch (GLib.Error e)
				{
					stderr.printf("Could not show notification: %s\n", e.message);
				}
			}
		}
		else
		{
			set_icon(PASSIVE_ICON);
			indicator.set_status (GConfInterface.get_bool (GConfInterface.Key.SHOW_PASSIVE_ICON) ? AppIndicator.IndicatorStatus.ACTIVE : AppIndicator.IndicatorStatus.PASSIVE);
			how_many.label = "No updates available";
			how_many.sensitive = false;
			if (GConfInterface.get_bool (GConfInterface.Key.NOTIFY))
			{
				var notify = new Notification ("Updates installed", "Your system is now up-to-date", PASSIVE_ICON);
				try
				{
					notify.show ();
				}
				catch (GLib.Error e)
				{
					stderr.printf("Could not show notification: %s\n", e.message);
				}
			}
		}
	}
	
	private void set_icon(string icon)
	{
		indicator.set_icon(icon);
	}
	
	private void on_execute_clicked (Gtk.Widget sender)
	{
		try 
		{
			Process.spawn_command_line_async ("update-manager");
		}
		catch (GLib.Error e)
		{
			stderr.printf("Failed to start \"update-manager\"\n");
		}
	}
	
	private void on_refresh_clicked (Gtk.Widget sender)
	{
		try
		{
			Process.spawn_command_line_async ("gksu apt-get update");
		}
		catch (GLib.Error e)
		{
			stderr.printf("Failed to refresh package list\n");
		}
	}
	
	private void on_preferences_clicked (Gtk.Widget sender)
	{
		var dialog = new PreferencesDialog();
		dialog.preferences_update.connect(on_preferences_update);
		dialog.show ();
	}
	
	public void on_preferences_update (PreferencesDialog sender)
	{
		checker.update_interval = GConfInterface.get_int (GConfInterface.Key.CHECK_INTERVAL);
		if (checker.count == 0)
		{
			if (GConfInterface.get_bool (GConfInterface.Key.SHOW_PASSIVE_ICON))
			{
				indicator.set_status (AppIndicator.IndicatorStatus.ACTIVE);
			}
			else
			{
				indicator.set_status (AppIndicator.IndicatorStatus.PASSIVE);
			}
		}
	}
	
	private void on_about_clicked (Gtk.Widget sender)
	{
		try
		{
			var builder = new Gtk.Builder();
			builder.add_from_file (GLADE_FILE);
			Gtk.Dialog dialog = builder.get_object ("about_dialog") as Gtk.Dialog;
			dialog.run ();
			dialog.hide ();
		}
		catch (Error e)
		{
			stderr.printf("Error: Couldn't load about dialog: %s'\n", e.message);
		}
	}
}
