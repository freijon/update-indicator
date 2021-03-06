/* main.c generated by valac 0.14.0, the Vala compiler
 * generated from main.vala, do not modify */

/*  */
/*  main.vala*/
/*  */
/*  Author:*/
/*       Jonas Frei <freijon@gmail.com>*/
/* */
/*  Copyright (c) 2011 Jonas Frei*/
/* */
/*  This program is free software: you can redistribute it and/or modify*/
/*  it under the terms of the GNU General Public License as published by*/
/*  the Free Software Foundation, either version 3 of the License, or*/
/*  (at your option) any later version.*/
/* */
/*  This program is distributed in the hope that it will be useful,*/
/*  but WITHOUT ANY WARRANTY; without even the implied warranty of*/
/*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the*/
/*  GNU General Public License for more details.*/
/* */
/*  You should have received a copy of the GNU General Public License*/
/*  along with this program.  If not, see <http://www.gnu.org/licenses/>.*/

#include <glib.h>
#include <glib-object.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>


#define TYPE_INDICATE (indicate_get_type ())
#define INDICATE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_INDICATE, Indicate))
#define INDICATE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_INDICATE, IndicateClass))
#define IS_INDICATE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_INDICATE))
#define IS_INDICATE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_INDICATE))
#define INDICATE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_INDICATE, IndicateClass))

typedef struct _Indicate Indicate;
typedef struct _IndicateClass IndicateClass;

#define TYPE_PREFERENCES_DIALOG (preferences_dialog_get_type ())
#define PREFERENCES_DIALOG(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_PREFERENCES_DIALOG, PreferencesDialog))
#define PREFERENCES_DIALOG_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_PREFERENCES_DIALOG, PreferencesDialogClass))
#define IS_PREFERENCES_DIALOG(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_PREFERENCES_DIALOG))
#define IS_PREFERENCES_DIALOG_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_PREFERENCES_DIALOG))
#define PREFERENCES_DIALOG_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_PREFERENCES_DIALOG, PreferencesDialogClass))

typedef struct _PreferencesDialog PreferencesDialog;
typedef struct _PreferencesDialogClass PreferencesDialogClass;
#define _preferences_dialog_unref0(var) ((var == NULL) ? NULL : (var = (preferences_dialog_unref (var), NULL)))
#define _indicate_unref0(var) ((var == NULL) ? NULL : (var = (indicate_unref (var), NULL)))



gint _vala_main (gchar** args, int args_length1);
Indicate* indicate_new (void);
Indicate* indicate_construct (GType object_type);
gpointer indicate_ref (gpointer instance);
void indicate_unref (gpointer instance);
GParamSpec* param_spec_indicate (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void value_set_indicate (GValue* value, gpointer v_object);
void value_take_indicate (GValue* value, gpointer v_object);
gpointer value_get_indicate (const GValue* value);
GType indicate_get_type (void) G_GNUC_CONST;
static gboolean _vala_string_array_contains (gchar** stack, int stack_length, gchar* needle);
PreferencesDialog* preferences_dialog_new (void);
PreferencesDialog* preferences_dialog_construct (GType object_type);
gpointer preferences_dialog_ref (gpointer instance);
void preferences_dialog_unref (gpointer instance);
GParamSpec* param_spec_preferences_dialog (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void value_set_preferences_dialog (GValue* value, gpointer v_object);
void value_take_preferences_dialog (GValue* value, gpointer v_object);
gpointer value_get_preferences_dialog (const GValue* value);
GType preferences_dialog_get_type (void) G_GNUC_CONST;
void indicate_on_preferences_update (Indicate* self, PreferencesDialog* sender);
static void _indicate_on_preferences_update_preferences_dialog_preferences_update (PreferencesDialog* _sender, gpointer self);
void preferences_dialog_show (PreferencesDialog* self);


static gboolean _vala_string_array_contains (gchar** stack, int stack_length, gchar* needle) {
	int i;
	for (i = 0; i < stack_length; i++) {
		if (g_strcmp0 (stack[i], needle) == 0) {
			return TRUE;
		}
	}
	return FALSE;
}


static void _indicate_on_preferences_update_preferences_dialog_preferences_update (PreferencesDialog* _sender, gpointer self) {
	indicate_on_preferences_update (self, _sender);
}


gint _vala_main (gchar** args, int args_length1) {
	gint result = 0;
	Indicate* _tmp0_;
	Indicate* app;
	gchar** _tmp1_;
	gint _tmp1__length1;
	gtk_init (&args_length1, &args);
	_tmp0_ = indicate_new ();
	app = _tmp0_;
	_tmp1_ = args;
	_tmp1__length1 = args_length1;
	if (_vala_string_array_contains (_tmp1_, _tmp1__length1, "--with-preferences")) {
		PreferencesDialog* _tmp2_;
		PreferencesDialog* dialog;
		PreferencesDialog* _tmp3_;
		Indicate* _tmp4_;
		PreferencesDialog* _tmp5_;
		_tmp2_ = preferences_dialog_new ();
		dialog = _tmp2_;
		_tmp3_ = dialog;
		_tmp4_ = app;
		g_signal_connect (_tmp3_, "preferences-update", (GCallback) _indicate_on_preferences_update_preferences_dialog_preferences_update, _tmp4_);
		_tmp5_ = dialog;
		preferences_dialog_show (_tmp5_);
		_preferences_dialog_unref0 (dialog);
	}
	gtk_main ();
	result = 0;
	_indicate_unref0 (app);
	return result;
}


int main (int argc, char ** argv) {
	g_type_init ();
	return _vala_main (argv, argc);
}



