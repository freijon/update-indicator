//  
//  Preferences.vala
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

public class PreferencesDialog
{
	private const string UI_FILE = "/home/jonas/Projects/Vala/update-indicator/src/UpdateIndicator.glade";
	
	private Builder builder;
	
	private Gtk.Dialog dialog;
	private Gtk.Adjustment adjustment;
	private Gtk.Label interval_label;
	private Gtk.Switch checkbutton_autopopup;
	private Gtk.Switch checkbutton_notify;
	private Gtk.Switch checkbutton_passive_icon;
	
	public signal void preferences_update();
	
	public PreferencesDialog()
	{
		try
		{
			builder = new Builder ();
			builder.add_from_file (UI_FILE);
			builder.connect_signals (this);
			
			dialog = builder.get_object ("preferences_dialog") as Gtk.Dialog;
			adjustment = builder.get_object ("interval_adjustment") as Gtk.Adjustment;
			interval_label = builder.get_object ("interval_label") as Gtk.Label;
			interval_label = builder.get_object ("interval_label") as Gtk.Label;
			var grid = builder.get_object ("grid1") as Gtk.Grid;
			checkbutton_autopopup = new Gtk.Switch();
			checkbutton_notify = new Gtk.Switch();
			checkbutton_passive_icon = new Gtk.Switch();

			grid.attach (checkbutton_autopopup, 1, 0, 1, 1);
			grid.attach (checkbutton_notify, 1, 1, 1, 1);
			grid.attach (checkbutton_passive_icon, 1, 2, 1, 1);

			dialog.show_all();
		}
		catch (GLib.Error e)
		{
			stderr.printf ("Could not load UI: %s\n", e.message);
		}
		
		update_from_gconf();
	}
	
	public void show ()
	{
		try
		{
			dialog.run ();
			dialog.hide ();
		}
		catch (Error e)
		{
			stderr.printf ("Could not show UI: %s\n", e.message);
		}
	}
	
	private void update_from_gconf ()
	{
		switch (GConfInterface.get_int (GConfInterface.Key.CHECK_INTERVAL))
		{
		case 10:
			adjustment.value = 0;
			break;
		case 30:
			adjustment.value = 1;
			break;
		case 60:
			adjustment.value = 2;
			break;
		case 2 * 60:
			adjustment.value = 3;
			break;
		case 5 * 60:
			adjustment.value = 4;
			break;
		case 10 * 60:
			adjustment.value = 5;
			break;
		case 20 * 60:
			adjustment.value = 6;
			break;
		case 30 * 60:
			adjustment.value = 7;
			break;
		}
		checkbutton_autopopup.active = !GConfInterface.get_bool (GConfInterface.Key.MANAGER_POPUP);
		checkbutton_notify.active = GConfInterface.get_bool (GConfInterface.Key.NOTIFY);
		checkbutton_passive_icon.active = GConfInterface.get_bool (GConfInterface.Key.SHOW_PASSIVE_ICON);
	}
	
	[CCode (instance_pos = -1)]
	public void on_interval_changed (Gtk.Adjustment sender)
	{
		if (sender.value >= 7) {
			interval_label.label = "30 minutes";
		} else if (sender.value >= 6) {
			interval_label.label = "20 minutes";
		} else if (sender.value >= 5) {
			interval_label.label = "10 minutes";
		} else if (sender.value >= 4) {
			interval_label.label = "5 minutes";
		} else if (sender.value >= 3) {
			interval_label.label = "2 minutes";
		} else if (sender.value >= 2) {
			interval_label.label = "1 minute";
		} else if (sender.value >= 1) {
			interval_label.label = "30 seconds";
		} else if (sender.value >= 0) {
			interval_label.label = "10 seconds";
		}
	}
	
	[CCode (instance_pos = -1)]
	public void on_ok_clicked (Gtk.Button sender)
	{
		switch ((int)adjustment.value)
		{
		case 0:
			GConfInterface.set_int (GConfInterface.Key.CHECK_INTERVAL, 10);
			break;
		case 1:
			GConfInterface.set_int (GConfInterface.Key.CHECK_INTERVAL, 30);
			break;
		case 2:
			GConfInterface.set_int (GConfInterface.Key.CHECK_INTERVAL, 60);
			break;
		case 3:
			GConfInterface.set_int (GConfInterface.Key.CHECK_INTERVAL, 2 * 60);
			break;
		case 4:
			GConfInterface.set_int (GConfInterface.Key.CHECK_INTERVAL, 5 * 60);
			break;
		case 5:
			GConfInterface.set_int (GConfInterface.Key.CHECK_INTERVAL, 10 * 60);
			break;
		case 6:
			GConfInterface.set_int (GConfInterface.Key.CHECK_INTERVAL, 20 * 60);
			break;
		case 7:
			GConfInterface.set_int (GConfInterface.Key.CHECK_INTERVAL, 30 * 60);
			break;
		}
		
//		client.set_bool (UPDATE_TOOL, combobox_tool.active);
//		client.set_bool (AUTOSTART, checkbutton_autostart.active);
		GConfInterface.set_bool (GConfInterface.Key.MANAGER_POPUP, !checkbutton_autopopup.active);
		GConfInterface.set_bool (GConfInterface.Key.NOTIFY, checkbutton_notify.active);
		GConfInterface.set_bool (GConfInterface.Key.SHOW_PASSIVE_ICON, checkbutton_passive_icon.active);
		
		preferences_update();
	}
}