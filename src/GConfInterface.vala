//  
//  GConfInterface.vala
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

using GConf;

public class GConfInterface
{
	
	private const string GCONF_APP_PATH = "/apps/indicator-updatemanager";
	private const string CHECK_INTERVAL = GCONF_APP_PATH + "/check_interval";
	private const string UPDATE_TOOL = GCONF_APP_PATH + "/tool";
//	private const string AUTOSTART = GCONF_APP_PATH + "/autostart";
	private const string NOTIFY = GCONF_APP_PATH + "/notification";
	private const string MANAGER_POPUP = "/apps/update-notifier/auto_launch";
	private const string SHOW_PASSIVE_ICON = GCONF_APP_PATH + "/show_passive_icon";
	private const string SHOW_NUMBER_OF_UPDATES = GCONF_APP_PATH + "/show_number";
	
	public enum Key
	{
		CHECK_INTERVAL,
		UPDATE_TOOL,
		NOTIFY,
		MANAGER_POPUP,
		SHOW_PASSIVE_ICON,
		SHOW_NUMBER_OF_UPDATES
	}
	
	public static bool get_bool (Key key)
	{
		GConf.Client client = GConf.Client.get_default ();
		bool output = true;
		switch (key)
		{
			case Key.NOTIFY:
				try {
					output = client.get_bool (NOTIFY);
				} catch (GLib.Error e) {
				}
				break;
			case Key.MANAGER_POPUP:
				try {
					output = client.get_bool (MANAGER_POPUP);
				} catch (GLib.Error e) {
				}
				break;
			case Key.SHOW_PASSIVE_ICON:
				try {
					output = client.get_bool (SHOW_PASSIVE_ICON);
				} catch (GLib.Error e) {
				}
				break;
			case Key.SHOW_NUMBER_OF_UPDATES:
				try {
					output = client.get_bool (SHOW_NUMBER_OF_UPDATES);
				} catch (GLib.Error e) {
				}
				break;
		}
		return output;
	}
	
	public static int get_int (Key key)
	{
		GConf.Client client = GConf.Client.get_default ();
		int output = 0;
		switch (key)
		{
			case Key.CHECK_INTERVAL:
				output = 2 * 60;
				try {
					output = client.get_int (CHECK_INTERVAL);
				} catch (GLib.Error e) {
				}
				break;
			case Key.UPDATE_TOOL:
				output = 0;
				try {
					output = client.get_int (UPDATE_TOOL);
				} catch (GLib.Error e) {
				}
				break;
		}
		return output;
	}
	
	public static void set_bool (Key key, bool value)
	{
		GConf.Client client = GConf.Client.get_default ();
		switch (key)
		{
			case Key.NOTIFY:
				try {
					client.set_bool (NOTIFY, value);
				} catch (GLib.Error e) {
					stderr.printf("Error: Failed to save setting \"NOTIFY\": %s\n", e.message);
				}
				break;
			case Key.MANAGER_POPUP:
				try {
					client.set_bool (MANAGER_POPUP, value);
				} catch (GLib.Error e) {
					stderr.printf("Error: Failed to save setting \"MANAGER_POPUP\": %s\n", e.message);
				}
				break;
			case Key.SHOW_PASSIVE_ICON:
				try {
					client.set_bool (SHOW_PASSIVE_ICON, value);
				} catch (GLib.Error e) {
					stderr.printf("Error: Failed to save setting \"SHOW_PASSIVE_ICON\": %s\n", e.message);
				}
				break;
			case Key.SHOW_NUMBER_OF_UPDATES:
				try {
					client.set_bool (SHOW_NUMBER_OF_UPDATES, value);
				} catch (GLib.Error e) {
					stderr.printf("Error: Failed to save setting \"SHOW_NUMBER_OF_UPDATES\": %s\n", e.message);
				}
				break;
		}
	}
	
	public static void set_int (Key key, int value)
	{
		GConf.Client client = GConf.Client.get_default ();
		switch (key)
		{
			case Key.CHECK_INTERVAL:
				try {
					client.set_int (CHECK_INTERVAL, value);
				} catch (GLib.Error e) {
					stderr.printf("Error: Failed to save setting \"CHECK_INTERVAL\": %s\n", e.message);
				}
				break;
			case Key.UPDATE_TOOL:
				try {
					client.set_int (UPDATE_TOOL, value);
				} catch (GLib.Error e) {
					stderr.printf("Error: Failed to save setting \"UPDATE_TOOL\": %s\n", e.message);
				}
				break;
		}
	}
}
