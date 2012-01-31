/* Preferences.c generated by valac 0.14.0, the Vala compiler
 * generated from Preferences.vala, do not modify */

/*  */
/*  Preferences.vala*/
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
#include <gtk/gtk.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <float.h>
#include <math.h>
#include <gobject/gvaluecollector.h>


#define TYPE_PREFERENCES_DIALOG (preferences_dialog_get_type ())
#define PREFERENCES_DIALOG(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_PREFERENCES_DIALOG, PreferencesDialog))
#define PREFERENCES_DIALOG_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_PREFERENCES_DIALOG, PreferencesDialogClass))
#define IS_PREFERENCES_DIALOG(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_PREFERENCES_DIALOG))
#define IS_PREFERENCES_DIALOG_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_PREFERENCES_DIALOG))
#define PREFERENCES_DIALOG_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_PREFERENCES_DIALOG, PreferencesDialogClass))

typedef struct _PreferencesDialog PreferencesDialog;
typedef struct _PreferencesDialogClass PreferencesDialogClass;
typedef struct _PreferencesDialogPrivate PreferencesDialogPrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))

#define GCONF_INTERFACE_TYPE_KEY (gconf_interface_key_get_type ())
typedef struct _ParamSpecPreferencesDialog ParamSpecPreferencesDialog;

struct _PreferencesDialog {
	GTypeInstance parent_instance;
	volatile int ref_count;
	PreferencesDialogPrivate * priv;
};

struct _PreferencesDialogClass {
	GTypeClass parent_class;
	void (*finalize) (PreferencesDialog *self);
};

struct _PreferencesDialogPrivate {
	GtkBuilder* builder;
	GtkDialog* dialog;
	GtkAdjustment* adjustment;
	GtkLabel* interval_label;
	GtkSwitch* checkbutton_autopopup;
	GtkSwitch* checkbutton_notify;
	GtkSwitch* checkbutton_passive_icon;
};

typedef enum  {
	GCONF_INTERFACE_KEY_CHECK_INTERVAL,
	GCONF_INTERFACE_KEY_NOTIFY,
	GCONF_INTERFACE_KEY_MANAGER_POPUP,
	GCONF_INTERFACE_KEY_SHOW_PASSIVE_ICON
} GConfInterfaceKey;

struct _ParamSpecPreferencesDialog {
	GParamSpec parent_instance;
};


static gpointer preferences_dialog_parent_class = NULL;

gpointer preferences_dialog_ref (gpointer instance);
void preferences_dialog_unref (gpointer instance);
GParamSpec* param_spec_preferences_dialog (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void value_set_preferences_dialog (GValue* value, gpointer v_object);
void value_take_preferences_dialog (GValue* value, gpointer v_object);
gpointer value_get_preferences_dialog (const GValue* value);
GType preferences_dialog_get_type (void) G_GNUC_CONST;
#define PREFERENCES_DIALOG_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), TYPE_PREFERENCES_DIALOG, PreferencesDialogPrivate))
enum  {
	PREFERENCES_DIALOG_DUMMY_PROPERTY
};
#define PREFERENCES_DIALOG_UI_FILE "/usr/share/update-indicator/ui/UpdateIndicator.glade"
PreferencesDialog* preferences_dialog_new (void);
PreferencesDialog* preferences_dialog_construct (GType object_type);
static void preferences_dialog_update_from_gconf (PreferencesDialog* self);
void preferences_dialog_show (PreferencesDialog* self);
GType gconf_interface_key_get_type (void) G_GNUC_CONST;
gint gconf_interface_get_int (GConfInterfaceKey key);
gboolean gconf_interface_get_bool (GConfInterfaceKey key);
void preferences_dialog_on_interval_changed (GtkAdjustment* sender, PreferencesDialog* self);
void preferences_dialog_on_ok_clicked (GtkButton* sender, PreferencesDialog* self);
void gconf_interface_set_int (GConfInterfaceKey key, gint value);
void gconf_interface_set_bool (GConfInterfaceKey key, gboolean value);
static void preferences_dialog_finalize (PreferencesDialog* obj);


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


PreferencesDialog* preferences_dialog_construct (GType object_type) {
	PreferencesDialog* self = NULL;
	GError * _inner_error_ = NULL;
	self = (PreferencesDialog*) g_type_create_instance (object_type);
	{
		GtkBuilder* _tmp0_;
		GtkBuilder* _tmp1_;
		GtkBuilder* _tmp2_;
		GtkBuilder* _tmp3_;
		GObject* _tmp4_ = NULL;
		GtkDialog* _tmp5_;
		GtkBuilder* _tmp6_;
		GObject* _tmp7_ = NULL;
		GtkAdjustment* _tmp8_;
		GtkBuilder* _tmp9_;
		GObject* _tmp10_ = NULL;
		GtkLabel* _tmp11_;
		GtkBuilder* _tmp12_;
		GObject* _tmp13_ = NULL;
		GtkLabel* _tmp14_;
		GtkBuilder* _tmp15_;
		GObject* _tmp16_ = NULL;
		GtkGrid* _tmp17_;
		GtkGrid* grid;
		GtkSwitch* _tmp18_;
		GtkSwitch* _tmp19_;
		GtkSwitch* _tmp20_;
		GtkSwitch* _tmp21_;
		GtkSwitch* _tmp22_;
		GtkSwitch* _tmp23_;
		GtkGrid* _tmp24_;
		GtkSwitch* _tmp25_;
		GtkGrid* _tmp26_;
		GtkSwitch* _tmp27_;
		GtkGrid* _tmp28_;
		GtkSwitch* _tmp29_;
		GtkDialog* _tmp30_;
		_tmp0_ = gtk_builder_new ();
		_g_object_unref0 (self->priv->builder);
		self->priv->builder = _tmp0_;
		_tmp1_ = self->priv->builder;
		gtk_builder_add_from_file (_tmp1_, PREFERENCES_DIALOG_UI_FILE, &_inner_error_);
		if (_inner_error_ != NULL) {
			goto __catch14_g_error;
		}
		_tmp2_ = self->priv->builder;
		gtk_builder_connect_signals (_tmp2_, self);
		_tmp3_ = self->priv->builder;
		_tmp4_ = gtk_builder_get_object (_tmp3_, "preferences_dialog");
		_tmp5_ = _g_object_ref0 (GTK_IS_DIALOG (_tmp4_) ? ((GtkDialog*) _tmp4_) : NULL);
		_g_object_unref0 (self->priv->dialog);
		self->priv->dialog = _tmp5_;
		_tmp6_ = self->priv->builder;
		_tmp7_ = gtk_builder_get_object (_tmp6_, "interval_adjustment");
		_tmp8_ = _g_object_ref0 (GTK_IS_ADJUSTMENT (_tmp7_) ? ((GtkAdjustment*) _tmp7_) : NULL);
		_g_object_unref0 (self->priv->adjustment);
		self->priv->adjustment = _tmp8_;
		_tmp9_ = self->priv->builder;
		_tmp10_ = gtk_builder_get_object (_tmp9_, "interval_label");
		_tmp11_ = _g_object_ref0 (GTK_IS_LABEL (_tmp10_) ? ((GtkLabel*) _tmp10_) : NULL);
		_g_object_unref0 (self->priv->interval_label);
		self->priv->interval_label = _tmp11_;
		_tmp12_ = self->priv->builder;
		_tmp13_ = gtk_builder_get_object (_tmp12_, "interval_label");
		_tmp14_ = _g_object_ref0 (GTK_IS_LABEL (_tmp13_) ? ((GtkLabel*) _tmp13_) : NULL);
		_g_object_unref0 (self->priv->interval_label);
		self->priv->interval_label = _tmp14_;
		_tmp15_ = self->priv->builder;
		_tmp16_ = gtk_builder_get_object (_tmp15_, "grid1");
		_tmp17_ = _g_object_ref0 (GTK_IS_GRID (_tmp16_) ? ((GtkGrid*) _tmp16_) : NULL);
		grid = _tmp17_;
		_tmp18_ = (GtkSwitch*) gtk_switch_new ();
		_tmp19_ = g_object_ref_sink (_tmp18_);
		_g_object_unref0 (self->priv->checkbutton_autopopup);
		self->priv->checkbutton_autopopup = _tmp19_;
		_tmp20_ = (GtkSwitch*) gtk_switch_new ();
		_tmp21_ = g_object_ref_sink (_tmp20_);
		_g_object_unref0 (self->priv->checkbutton_notify);
		self->priv->checkbutton_notify = _tmp21_;
		_tmp22_ = (GtkSwitch*) gtk_switch_new ();
		_tmp23_ = g_object_ref_sink (_tmp22_);
		_g_object_unref0 (self->priv->checkbutton_passive_icon);
		self->priv->checkbutton_passive_icon = _tmp23_;
		_tmp24_ = grid;
		_tmp25_ = self->priv->checkbutton_autopopup;
		gtk_grid_attach (_tmp24_, (GtkWidget*) _tmp25_, 1, 0, 1, 1);
		_tmp26_ = grid;
		_tmp27_ = self->priv->checkbutton_notify;
		gtk_grid_attach (_tmp26_, (GtkWidget*) _tmp27_, 1, 1, 1, 1);
		_tmp28_ = grid;
		_tmp29_ = self->priv->checkbutton_passive_icon;
		gtk_grid_attach (_tmp28_, (GtkWidget*) _tmp29_, 1, 2, 1, 1);
		_tmp30_ = self->priv->dialog;
		gtk_widget_show_all ((GtkWidget*) _tmp30_);
		_g_object_unref0 (grid);
	}
	goto __finally14;
	__catch14_g_error:
	{
		GError* e = NULL;
		FILE* _tmp31_;
		GError* _tmp32_;
		const gchar* _tmp33_;
		e = _inner_error_;
		_inner_error_ = NULL;
		_tmp31_ = stderr;
		_tmp32_ = e;
		_tmp33_ = _tmp32_->message;
		fprintf (_tmp31_, "Could not load UI: %s\n", _tmp33_);
		_g_error_free0 (e);
	}
	__finally14:
	if (_inner_error_ != NULL) {
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return NULL;
	}
	preferences_dialog_update_from_gconf (self);
	return self;
}


PreferencesDialog* preferences_dialog_new (void) {
	return preferences_dialog_construct (TYPE_PREFERENCES_DIALOG);
}


void preferences_dialog_show (PreferencesDialog* self) {
	GError * _inner_error_ = NULL;
	g_return_if_fail (self != NULL);
	{
		GtkDialog* _tmp0_;
		GtkDialog* _tmp1_;
		_tmp0_ = self->priv->dialog;
		gtk_dialog_run (_tmp0_);
		_tmp1_ = self->priv->dialog;
		gtk_widget_hide ((GtkWidget*) _tmp1_);
	}
	goto __finally15;
	__catch15_g_error:
	{
		GError* e = NULL;
		FILE* _tmp2_;
		GError* _tmp3_;
		const gchar* _tmp4_;
		e = _inner_error_;
		_inner_error_ = NULL;
		_tmp2_ = stderr;
		_tmp3_ = e;
		_tmp4_ = _tmp3_->message;
		fprintf (_tmp2_, "Could not show UI: %s\n", _tmp4_);
		_g_error_free0 (e);
	}
	__finally15:
	if (_inner_error_ != NULL) {
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return;
	}
}


static void preferences_dialog_update_from_gconf (PreferencesDialog* self) {
	gint _tmp0_ = 0;
	GtkSwitch* _tmp9_;
	gboolean _tmp10_ = FALSE;
	GtkSwitch* _tmp11_;
	gboolean _tmp12_ = FALSE;
	GtkSwitch* _tmp13_;
	gboolean _tmp14_ = FALSE;
	g_return_if_fail (self != NULL);
	_tmp0_ = gconf_interface_get_int (GCONF_INTERFACE_KEY_CHECK_INTERVAL);
	switch (_tmp0_) {
		case 10:
		{
			GtkAdjustment* _tmp1_;
			_tmp1_ = self->priv->adjustment;
			gtk_adjustment_set_value (_tmp1_, (gdouble) 0);
			break;
		}
		case 30:
		{
			GtkAdjustment* _tmp2_;
			_tmp2_ = self->priv->adjustment;
			gtk_adjustment_set_value (_tmp2_, (gdouble) 1);
			break;
		}
		case 60:
		{
			GtkAdjustment* _tmp3_;
			_tmp3_ = self->priv->adjustment;
			gtk_adjustment_set_value (_tmp3_, (gdouble) 2);
			break;
		}
		case 2 * 60:
		{
			GtkAdjustment* _tmp4_;
			_tmp4_ = self->priv->adjustment;
			gtk_adjustment_set_value (_tmp4_, (gdouble) 3);
			break;
		}
		case 5 * 60:
		{
			GtkAdjustment* _tmp5_;
			_tmp5_ = self->priv->adjustment;
			gtk_adjustment_set_value (_tmp5_, (gdouble) 4);
			break;
		}
		case 10 * 60:
		{
			GtkAdjustment* _tmp6_;
			_tmp6_ = self->priv->adjustment;
			gtk_adjustment_set_value (_tmp6_, (gdouble) 5);
			break;
		}
		case 20 * 60:
		{
			GtkAdjustment* _tmp7_;
			_tmp7_ = self->priv->adjustment;
			gtk_adjustment_set_value (_tmp7_, (gdouble) 6);
			break;
		}
		case 30 * 60:
		{
			GtkAdjustment* _tmp8_;
			_tmp8_ = self->priv->adjustment;
			gtk_adjustment_set_value (_tmp8_, (gdouble) 7);
			break;
		}
		default:
		break;
	}
	_tmp9_ = self->priv->checkbutton_autopopup;
	_tmp10_ = gconf_interface_get_bool (GCONF_INTERFACE_KEY_MANAGER_POPUP);
	gtk_switch_set_active (_tmp9_, !_tmp10_);
	_tmp11_ = self->priv->checkbutton_notify;
	_tmp12_ = gconf_interface_get_bool (GCONF_INTERFACE_KEY_NOTIFY);
	gtk_switch_set_active (_tmp11_, _tmp12_);
	_tmp13_ = self->priv->checkbutton_passive_icon;
	_tmp14_ = gconf_interface_get_bool (GCONF_INTERFACE_KEY_SHOW_PASSIVE_ICON);
	gtk_switch_set_active (_tmp13_, _tmp14_);
}


void preferences_dialog_on_interval_changed (GtkAdjustment* sender, PreferencesDialog* self) {
	GtkAdjustment* _tmp0_;
	gdouble _tmp1_;
	gdouble _tmp2_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (sender != NULL);
	_tmp0_ = sender;
	_tmp1_ = gtk_adjustment_get_value (_tmp0_);
	_tmp2_ = _tmp1_;
	if (_tmp2_ >= ((gdouble) 7)) {
		GtkLabel* _tmp3_;
		_tmp3_ = self->priv->interval_label;
		gtk_label_set_label (_tmp3_, "30 minutes");
	} else {
		GtkAdjustment* _tmp4_;
		gdouble _tmp5_;
		gdouble _tmp6_;
		_tmp4_ = sender;
		_tmp5_ = gtk_adjustment_get_value (_tmp4_);
		_tmp6_ = _tmp5_;
		if (_tmp6_ >= ((gdouble) 6)) {
			GtkLabel* _tmp7_;
			_tmp7_ = self->priv->interval_label;
			gtk_label_set_label (_tmp7_, "20 minutes");
		} else {
			GtkAdjustment* _tmp8_;
			gdouble _tmp9_;
			gdouble _tmp10_;
			_tmp8_ = sender;
			_tmp9_ = gtk_adjustment_get_value (_tmp8_);
			_tmp10_ = _tmp9_;
			if (_tmp10_ >= ((gdouble) 5)) {
				GtkLabel* _tmp11_;
				_tmp11_ = self->priv->interval_label;
				gtk_label_set_label (_tmp11_, "10 minutes");
			} else {
				GtkAdjustment* _tmp12_;
				gdouble _tmp13_;
				gdouble _tmp14_;
				_tmp12_ = sender;
				_tmp13_ = gtk_adjustment_get_value (_tmp12_);
				_tmp14_ = _tmp13_;
				if (_tmp14_ >= ((gdouble) 4)) {
					GtkLabel* _tmp15_;
					_tmp15_ = self->priv->interval_label;
					gtk_label_set_label (_tmp15_, "5 minutes");
				} else {
					GtkAdjustment* _tmp16_;
					gdouble _tmp17_;
					gdouble _tmp18_;
					_tmp16_ = sender;
					_tmp17_ = gtk_adjustment_get_value (_tmp16_);
					_tmp18_ = _tmp17_;
					if (_tmp18_ >= ((gdouble) 3)) {
						GtkLabel* _tmp19_;
						_tmp19_ = self->priv->interval_label;
						gtk_label_set_label (_tmp19_, "2 minutes");
					} else {
						GtkAdjustment* _tmp20_;
						gdouble _tmp21_;
						gdouble _tmp22_;
						_tmp20_ = sender;
						_tmp21_ = gtk_adjustment_get_value (_tmp20_);
						_tmp22_ = _tmp21_;
						if (_tmp22_ >= ((gdouble) 2)) {
							GtkLabel* _tmp23_;
							_tmp23_ = self->priv->interval_label;
							gtk_label_set_label (_tmp23_, "1 minute");
						} else {
							GtkAdjustment* _tmp24_;
							gdouble _tmp25_;
							gdouble _tmp26_;
							_tmp24_ = sender;
							_tmp25_ = gtk_adjustment_get_value (_tmp24_);
							_tmp26_ = _tmp25_;
							if (_tmp26_ >= ((gdouble) 1)) {
								GtkLabel* _tmp27_;
								_tmp27_ = self->priv->interval_label;
								gtk_label_set_label (_tmp27_, "30 seconds");
							} else {
								GtkAdjustment* _tmp28_;
								gdouble _tmp29_;
								gdouble _tmp30_;
								_tmp28_ = sender;
								_tmp29_ = gtk_adjustment_get_value (_tmp28_);
								_tmp30_ = _tmp29_;
								if (_tmp30_ >= ((gdouble) 0)) {
									GtkLabel* _tmp31_;
									_tmp31_ = self->priv->interval_label;
									gtk_label_set_label (_tmp31_, "10 seconds");
								}
							}
						}
					}
				}
			}
		}
	}
}


void preferences_dialog_on_ok_clicked (GtkButton* sender, PreferencesDialog* self) {
	GtkAdjustment* _tmp0_;
	gdouble _tmp1_;
	gdouble _tmp2_;
	GtkSwitch* _tmp3_;
	gboolean _tmp4_;
	gboolean _tmp5_;
	GtkSwitch* _tmp6_;
	gboolean _tmp7_;
	gboolean _tmp8_;
	GtkSwitch* _tmp9_;
	gboolean _tmp10_;
	gboolean _tmp11_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (sender != NULL);
	_tmp0_ = self->priv->adjustment;
	_tmp1_ = gtk_adjustment_get_value (_tmp0_);
	_tmp2_ = _tmp1_;
	switch ((gint) _tmp2_) {
		case 0:
		{
			gconf_interface_set_int (GCONF_INTERFACE_KEY_CHECK_INTERVAL, 10);
			break;
		}
		case 1:
		{
			gconf_interface_set_int (GCONF_INTERFACE_KEY_CHECK_INTERVAL, 30);
			break;
		}
		case 2:
		{
			gconf_interface_set_int (GCONF_INTERFACE_KEY_CHECK_INTERVAL, 60);
			break;
		}
		case 3:
		{
			gconf_interface_set_int (GCONF_INTERFACE_KEY_CHECK_INTERVAL, 2 * 60);
			break;
		}
		case 4:
		{
			gconf_interface_set_int (GCONF_INTERFACE_KEY_CHECK_INTERVAL, 5 * 60);
			break;
		}
		case 5:
		{
			gconf_interface_set_int (GCONF_INTERFACE_KEY_CHECK_INTERVAL, 10 * 60);
			break;
		}
		case 6:
		{
			gconf_interface_set_int (GCONF_INTERFACE_KEY_CHECK_INTERVAL, 20 * 60);
			break;
		}
		case 7:
		{
			gconf_interface_set_int (GCONF_INTERFACE_KEY_CHECK_INTERVAL, 30 * 60);
			break;
		}
		default:
		break;
	}
	_tmp3_ = self->priv->checkbutton_autopopup;
	_tmp4_ = gtk_switch_get_active (_tmp3_);
	_tmp5_ = _tmp4_;
	gconf_interface_set_bool (GCONF_INTERFACE_KEY_MANAGER_POPUP, !_tmp5_);
	_tmp6_ = self->priv->checkbutton_notify;
	_tmp7_ = gtk_switch_get_active (_tmp6_);
	_tmp8_ = _tmp7_;
	gconf_interface_set_bool (GCONF_INTERFACE_KEY_NOTIFY, _tmp8_);
	_tmp9_ = self->priv->checkbutton_passive_icon;
	_tmp10_ = gtk_switch_get_active (_tmp9_);
	_tmp11_ = _tmp10_;
	gconf_interface_set_bool (GCONF_INTERFACE_KEY_SHOW_PASSIVE_ICON, _tmp11_);
	g_signal_emit_by_name (self, "preferences-update");
}


static void value_preferences_dialog_init (GValue* value) {
	value->data[0].v_pointer = NULL;
}


static void value_preferences_dialog_free_value (GValue* value) {
	if (value->data[0].v_pointer) {
		preferences_dialog_unref (value->data[0].v_pointer);
	}
}


static void value_preferences_dialog_copy_value (const GValue* src_value, GValue* dest_value) {
	if (src_value->data[0].v_pointer) {
		dest_value->data[0].v_pointer = preferences_dialog_ref (src_value->data[0].v_pointer);
	} else {
		dest_value->data[0].v_pointer = NULL;
	}
}


static gpointer value_preferences_dialog_peek_pointer (const GValue* value) {
	return value->data[0].v_pointer;
}


static gchar* value_preferences_dialog_collect_value (GValue* value, guint n_collect_values, GTypeCValue* collect_values, guint collect_flags) {
	if (collect_values[0].v_pointer) {
		PreferencesDialog* object;
		object = collect_values[0].v_pointer;
		if (object->parent_instance.g_class == NULL) {
			return g_strconcat ("invalid unclassed object pointer for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		} else if (!g_value_type_compatible (G_TYPE_FROM_INSTANCE (object), G_VALUE_TYPE (value))) {
			return g_strconcat ("invalid object type `", g_type_name (G_TYPE_FROM_INSTANCE (object)), "' for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		}
		value->data[0].v_pointer = preferences_dialog_ref (object);
	} else {
		value->data[0].v_pointer = NULL;
	}
	return NULL;
}


static gchar* value_preferences_dialog_lcopy_value (const GValue* value, guint n_collect_values, GTypeCValue* collect_values, guint collect_flags) {
	PreferencesDialog** object_p;
	object_p = collect_values[0].v_pointer;
	if (!object_p) {
		return g_strdup_printf ("value location for `%s' passed as NULL", G_VALUE_TYPE_NAME (value));
	}
	if (!value->data[0].v_pointer) {
		*object_p = NULL;
	} else if (collect_flags & G_VALUE_NOCOPY_CONTENTS) {
		*object_p = value->data[0].v_pointer;
	} else {
		*object_p = preferences_dialog_ref (value->data[0].v_pointer);
	}
	return NULL;
}


GParamSpec* param_spec_preferences_dialog (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags) {
	ParamSpecPreferencesDialog* spec;
	g_return_val_if_fail (g_type_is_a (object_type, TYPE_PREFERENCES_DIALOG), NULL);
	spec = g_param_spec_internal (G_TYPE_PARAM_OBJECT, name, nick, blurb, flags);
	G_PARAM_SPEC (spec)->value_type = object_type;
	return G_PARAM_SPEC (spec);
}


gpointer value_get_preferences_dialog (const GValue* value) {
	g_return_val_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, TYPE_PREFERENCES_DIALOG), NULL);
	return value->data[0].v_pointer;
}


void value_set_preferences_dialog (GValue* value, gpointer v_object) {
	PreferencesDialog* old;
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, TYPE_PREFERENCES_DIALOG));
	old = value->data[0].v_pointer;
	if (v_object) {
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, TYPE_PREFERENCES_DIALOG));
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
		value->data[0].v_pointer = v_object;
		preferences_dialog_ref (value->data[0].v_pointer);
	} else {
		value->data[0].v_pointer = NULL;
	}
	if (old) {
		preferences_dialog_unref (old);
	}
}


void value_take_preferences_dialog (GValue* value, gpointer v_object) {
	PreferencesDialog* old;
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, TYPE_PREFERENCES_DIALOG));
	old = value->data[0].v_pointer;
	if (v_object) {
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, TYPE_PREFERENCES_DIALOG));
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
		value->data[0].v_pointer = v_object;
	} else {
		value->data[0].v_pointer = NULL;
	}
	if (old) {
		preferences_dialog_unref (old);
	}
}


static void preferences_dialog_class_init (PreferencesDialogClass * klass) {
	preferences_dialog_parent_class = g_type_class_peek_parent (klass);
	PREFERENCES_DIALOG_CLASS (klass)->finalize = preferences_dialog_finalize;
	g_type_class_add_private (klass, sizeof (PreferencesDialogPrivate));
	g_signal_new ("preferences_update", TYPE_PREFERENCES_DIALOG, G_SIGNAL_RUN_LAST, 0, NULL, NULL, g_cclosure_marshal_VOID__VOID, G_TYPE_NONE, 0);
}


static void preferences_dialog_instance_init (PreferencesDialog * self) {
	self->priv = PREFERENCES_DIALOG_GET_PRIVATE (self);
	self->ref_count = 1;
}


static void preferences_dialog_finalize (PreferencesDialog* obj) {
	PreferencesDialog * self;
	self = PREFERENCES_DIALOG (obj);
	_g_object_unref0 (self->priv->builder);
	_g_object_unref0 (self->priv->dialog);
	_g_object_unref0 (self->priv->adjustment);
	_g_object_unref0 (self->priv->interval_label);
	_g_object_unref0 (self->priv->checkbutton_autopopup);
	_g_object_unref0 (self->priv->checkbutton_notify);
	_g_object_unref0 (self->priv->checkbutton_passive_icon);
}


GType preferences_dialog_get_type (void) {
	static volatile gsize preferences_dialog_type_id__volatile = 0;
	if (g_once_init_enter (&preferences_dialog_type_id__volatile)) {
		static const GTypeValueTable g_define_type_value_table = { value_preferences_dialog_init, value_preferences_dialog_free_value, value_preferences_dialog_copy_value, value_preferences_dialog_peek_pointer, "p", value_preferences_dialog_collect_value, "p", value_preferences_dialog_lcopy_value };
		static const GTypeInfo g_define_type_info = { sizeof (PreferencesDialogClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) preferences_dialog_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (PreferencesDialog), 0, (GInstanceInitFunc) preferences_dialog_instance_init, &g_define_type_value_table };
		static const GTypeFundamentalInfo g_define_type_fundamental_info = { (G_TYPE_FLAG_CLASSED | G_TYPE_FLAG_INSTANTIATABLE | G_TYPE_FLAG_DERIVABLE | G_TYPE_FLAG_DEEP_DERIVABLE) };
		GType preferences_dialog_type_id;
		preferences_dialog_type_id = g_type_register_fundamental (g_type_fundamental_next (), "PreferencesDialog", &g_define_type_info, &g_define_type_fundamental_info, 0);
		g_once_init_leave (&preferences_dialog_type_id__volatile, preferences_dialog_type_id);
	}
	return preferences_dialog_type_id__volatile;
}


gpointer preferences_dialog_ref (gpointer instance) {
	PreferencesDialog* self;
	self = instance;
	g_atomic_int_inc (&self->ref_count);
	return instance;
}


void preferences_dialog_unref (gpointer instance) {
	PreferencesDialog* self;
	self = instance;
	if (g_atomic_int_dec_and_test (&self->ref_count)) {
		PREFERENCES_DIALOG_GET_CLASS (self)->finalize (self);
		g_type_free_instance ((GTypeInstance *) self);
	}
}



