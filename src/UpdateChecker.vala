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
	
	private int interval = 2 * 60;
	private string package_list = "";
	private int package_count = 0;
	
	public UpdateChecker (int update_interval)
	{
		interval = update_interval;
	}
	
	public void* check_for_updates()
	{
		while (true)
		{
			string output = "";
			try
			{
				Process.spawn_command_line_sync ("apt-get upgrade -s", out output);
			}
			catch (Error e)
			{
				stderr.printf("Failed to check for updates.\n");
			}
			
			string[] output_lines = output.split("\n");
			string packages = "";
			bool look_for_packages = false;
			
			foreach (string line in output_lines)
			{
				if (line.contains ("newly installed"))
				{
					break;
				}
				
				if (line == "The following packages will be upgraded:")
				{
					look_for_packages = true;
					continue;
				}
				if (look_for_packages)
				{
					packages += (line._chug() + " ");
				}
			}
			
			packages._chomp();
			
			if (packages != "")
			{
				if (packages != package_list)
				{
					string[] update_list = packages.split(" ");
					count = update_list.length;
					update_event(update_list, update_list.length);
				}
				
			}
			else
			{
				if (packages != package_list)
				{
					count = 0;
					update_event(new string[]{"No updates"}, 0);
				}
			}
			package_list = packages;
			
			Thread.usleep(update_interval * 1000000);
		}
	}
	
	public int update_interval
	{
		set { interval = value; }
		get { return interval; }
	}
	
	public int count
	{
		set { package_count = value; }
		get { return package_count; }
	}
}