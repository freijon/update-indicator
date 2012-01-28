//  
//  main.vala
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

 int main (string[] args) {
	
	Gtk.init(ref args);
	
	var app = new Indicate();
	
	if ("--with-preferences" in args)
	{
		var dialog = new PreferencesDialog();
		dialog.preferences_update.connect(app.on_preferences_update);
		dialog.show ();
	}
	
	Gtk.main();
	return 0;
}
