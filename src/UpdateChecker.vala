//  
//  UpdateChecker.vala
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

public class UpdateChecker
{
	public signal void update_event (string[] packages, int count);
	
	private string[] old_list = new string[]{"No updates"};
	
	public UpdateChecker (int update_interval)
	{
		this.update_interval = update_interval;
	}
	
	public void* check_for_updates()
	{
		while (true)
		{
			string output = "";
			try
			{
				Process.spawn_command_line_sync ("aptitude search ~U -F %p", out output);
			}
			catch (Error e)
			{
				stderr.printf("Failed to check for updates.\n--> is \"aptitude\" correctly installed on your system?\n");
			}
			string[] packages = output.length > 0 ? output.split("\n") : new string[]{"No updates"};

			if (packages.length > 0)
			{
				if (packages[0] != "No updates")
				{
					packages.resize(packages.length -1);
				}
			}

			for (int i = 0; i < packages.length; i++)
			{
				packages[i] = packages[i]._chomp ();
			}
			
			bool is_same = true;
			for (int i = 0; i < packages.length; i++)
			{
				if (packages[i] != old_list[i])
				{
					is_same = false;
					break;
				}
			}
			if (packages.length != old_list.length)
				is_same = false;
			
			if (packages[0] != "No updates")
			{
				if (!is_same)
				{
					count = packages.length;
					update_event(packages, count);
				}
			}

			else
			{
				if (!is_same)
				{
					count = 0;
					update_event(new string[]{"No updates"}, 0);
				}
			}
			
			old_list = packages;
			
			Thread.usleep(update_interval * 1000000);
		}
	}
	[Description(nick = "update interval in seconds", blurb = "Defines how often check_for_updates() should be executed")]
	public int update_interval
	{
		get; set; default = 2 * 60;
	}

	[Description(nick = "number of available updates", blurb = "Returns the number of available updates")]
	public int count
	{
		get; private set; default = 0;
	}
}