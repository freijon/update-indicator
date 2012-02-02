/* UpdateChecker.c generated by valac 0.14.0, the Vala compiler
 * generated from UpdateChecker.vala, do not modify */

/*  */
/*  UpdateChecker.vala*/
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
#include <stdio.h>
#include <gobject/gvaluecollector.h>


#define TYPE_UPDATE_CHECKER (update_checker_get_type ())
#define UPDATE_CHECKER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_UPDATE_CHECKER, UpdateChecker))
#define UPDATE_CHECKER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_UPDATE_CHECKER, UpdateCheckerClass))
#define IS_UPDATE_CHECKER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_UPDATE_CHECKER))
#define IS_UPDATE_CHECKER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_UPDATE_CHECKER))
#define UPDATE_CHECKER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_UPDATE_CHECKER, UpdateCheckerClass))

typedef struct _UpdateChecker UpdateChecker;
typedef struct _UpdateCheckerClass UpdateCheckerClass;
typedef struct _UpdateCheckerPrivate UpdateCheckerPrivate;
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))
typedef struct _ParamSpecUpdateChecker ParamSpecUpdateChecker;

struct _UpdateChecker {
	GTypeInstance parent_instance;
	volatile int ref_count;
	UpdateCheckerPrivate * priv;
};

struct _UpdateCheckerClass {
	GTypeClass parent_class;
	void (*finalize) (UpdateChecker *self);
};

struct _UpdateCheckerPrivate {
	gint interval;
	gchar** old_list;
	gint old_list_length1;
	gint _old_list_size_;
	gint package_count;
};

struct _ParamSpecUpdateChecker {
	GParamSpec parent_instance;
};


static gpointer update_checker_parent_class = NULL;

gpointer update_checker_ref (gpointer instance);
void update_checker_unref (gpointer instance);
GParamSpec* param_spec_update_checker (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void value_set_update_checker (GValue* value, gpointer v_object);
void value_take_update_checker (GValue* value, gpointer v_object);
gpointer value_get_update_checker (const GValue* value);
GType update_checker_get_type (void) G_GNUC_CONST;
#define UPDATE_CHECKER_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), TYPE_UPDATE_CHECKER, UpdateCheckerPrivate))
enum  {
	UPDATE_CHECKER_DUMMY_PROPERTY
};
UpdateChecker* update_checker_new (gint update_interval);
UpdateChecker* update_checker_construct (GType object_type, gint update_interval);
void* update_checker_check_for_updates (UpdateChecker* self);
static gchar** _vala_array_dup1 (gchar** self, int length);
void update_checker_set_count (UpdateChecker* self, gint value);
gint update_checker_get_count (UpdateChecker* self);
static gchar** _vala_array_dup2 (gchar** self, int length);
gint update_checker_get_update_interval (UpdateChecker* self);
void update_checker_set_update_interval (UpdateChecker* self, gint value);
static void g_cclosure_user_marshal_VOID__BOXED_INT_INT (GClosure * closure, GValue * return_value, guint n_param_values, const GValue * param_values, gpointer invocation_hint, gpointer marshal_data);
static void update_checker_finalize (UpdateChecker* obj);
static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func);
static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func);
static gint _vala_array_length (gpointer array);


UpdateChecker* update_checker_construct (GType object_type, gint update_interval) {
	UpdateChecker* self = NULL;
	gint _tmp0_;
	self = (UpdateChecker*) g_type_create_instance (object_type);
	_tmp0_ = update_interval;
	self->priv->interval = _tmp0_;
	return self;
}


UpdateChecker* update_checker_new (gint update_interval) {
	return update_checker_construct (TYPE_UPDATE_CHECKER, update_interval);
}


static gchar** _vala_array_dup1 (gchar** self, int length) {
	gchar** result;
	int i;
	result = g_new0 (gchar*, length + 1);
	for (i = 0; i < length; i++) {
		gchar* _tmp0_;
		_tmp0_ = g_strdup (self[i]);
		result[i] = _tmp0_;
	}
	return result;
}


static gchar** _vala_array_dup2 (gchar** self, int length) {
	gchar** result;
	int i;
	result = g_new0 (gchar*, length + 1);
	for (i = 0; i < length; i++) {
		gchar* _tmp0_;
		_tmp0_ = g_strdup (self[i]);
		result[i] = _tmp0_;
	}
	return result;
}


void* update_checker_check_for_updates (UpdateChecker* self) {
	void* result = NULL;
	GError * _inner_error_ = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	while (TRUE) {
		gchar* _tmp0_;
		gchar* output;
		gchar** _tmp3_ = NULL;
		gint _tmp3__length1 = 0;
		gint __tmp3__size_ = 0;
		const gchar* _tmp4_;
		gint _tmp5_;
		gint _tmp6_;
		gchar** _tmp12_;
		gint _tmp12__length1;
		gchar** _tmp13_;
		gint _tmp13__length1;
		gchar** packages;
		gint packages_length1;
		gint _packages_size_;
		gchar** _tmp14_;
		gint _tmp14__length1;
		gboolean is_same;
		gchar** _tmp43_;
		gint _tmp43__length1;
		gchar** _tmp44_;
		gint _tmp44__length1;
		gchar** _tmp45_;
		gint _tmp45__length1;
		const gchar* _tmp46_;
		gchar** _tmp56_;
		gint _tmp56__length1;
		gchar** _tmp57_;
		gint _tmp57__length1;
		gint _tmp58_;
		gint _tmp59_;
		_tmp0_ = g_strdup ("");
		output = _tmp0_;
		{
			gchar* _tmp1_ = NULL;
			g_spawn_command_line_sync ("aptitude search ~U -F %p", &_tmp1_, NULL, NULL, &_inner_error_);
			_g_free0 (output);
			output = _tmp1_;
			if (_inner_error_ != NULL) {
				goto __catch20_g_error;
			}
		}
		goto __finally20;
		__catch20_g_error:
		{
			GError* e = NULL;
			FILE* _tmp2_;
			e = _inner_error_;
			_inner_error_ = NULL;
			_tmp2_ = stderr;
			fprintf (_tmp2_, "Failed to check for updates.\n" \
"--> is \"aptitude\" correctly installed on your system?\n");
			_g_error_free0 (e);
		}
		__finally20:
		if (_inner_error_ != NULL) {
			_g_free0 (output);
			g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
			return NULL;
		}
		_tmp4_ = output;
		_tmp5_ = strlen (_tmp4_);
		_tmp6_ = _tmp5_;
		if (_tmp6_ > 0) {
			const gchar* _tmp7_;
			gchar** _tmp8_;
			gchar** _tmp9_ = NULL;
			_tmp7_ = output;
			_tmp9_ = _tmp8_ = g_strsplit (_tmp7_, "\n", 0);
			_tmp3_ = (_vala_array_free (_tmp3_, _tmp3__length1, (GDestroyNotify) g_free), NULL);
			_tmp3_ = _tmp9_;
			_tmp3__length1 = _vala_array_length (_tmp8_);
			__tmp3__size_ = _tmp3__length1;
		} else {
			gchar* _tmp10_;
			gchar** _tmp11_ = NULL;
			_tmp10_ = g_strdup ("No updates");
			_tmp11_ = g_new0 (gchar*, 1 + 1);
			_tmp11_[0] = _tmp10_;
			_tmp3_ = (_vala_array_free (_tmp3_, _tmp3__length1, (GDestroyNotify) g_free), NULL);
			_tmp3_ = _tmp11_;
			_tmp3__length1 = 1;
			__tmp3__size_ = _tmp3__length1;
		}
		_tmp12_ = _tmp3_;
		_tmp12__length1 = _tmp3__length1;
		_tmp13_ = (_tmp12_ != NULL) ? _vala_array_dup1 (_tmp12_, _tmp12__length1) : ((gpointer) _tmp12_);
		_tmp13__length1 = _tmp12__length1;
		packages = _tmp13_;
		packages_length1 = _tmp13__length1;
		_packages_size_ = packages_length1;
		_tmp14_ = packages;
		_tmp14__length1 = packages_length1;
		if (_tmp14__length1 > 0) {
			gchar** _tmp15_;
			gint _tmp15__length1;
			const gchar* _tmp16_;
			_tmp15_ = packages;
			_tmp15__length1 = packages_length1;
			_tmp16_ = _tmp15_[0];
			if (g_strcmp0 (_tmp16_, "No updates") != 0) {
				gchar** _tmp17_;
				gint _tmp17__length1;
				gint _tmp18_ = 0;
				_tmp17_ = packages;
				_tmp17__length1 = packages_length1;
				_tmp18_ = _tmp17__length1 - 1;
				packages = g_renew (gchar*, packages, _tmp17__length1 - 1);
				(_tmp18_ > packages_length1) ? memset (packages + packages_length1, 0, sizeof (gchar*) * (_tmp18_ - packages_length1)) : NULL;
				packages_length1 = _tmp18_;
				_packages_size_ = _tmp18_;
			}
		}
		{
			gint i;
			i = 0;
			{
				gboolean _tmp19_;
				_tmp19_ = TRUE;
				while (TRUE) {
					gboolean _tmp20_;
					gint _tmp22_;
					gchar** _tmp23_;
					gint _tmp23__length1;
					gchar** _tmp24_;
					gint _tmp24__length1;
					gint _tmp25_;
					gchar** _tmp26_;
					gint _tmp26__length1;
					gint _tmp27_;
					const gchar* _tmp28_;
					const gchar* _tmp29_ = NULL;
					gchar* _tmp30_;
					gchar* _tmp31_;
					_tmp20_ = _tmp19_;
					if (!_tmp20_) {
						gint _tmp21_;
						_tmp21_ = i;
						i = _tmp21_ + 1;
					}
					_tmp19_ = FALSE;
					_tmp22_ = i;
					_tmp23_ = packages;
					_tmp23__length1 = packages_length1;
					if (!(_tmp22_ < _tmp23__length1)) {
						break;
					}
					_tmp24_ = packages;
					_tmp24__length1 = packages_length1;
					_tmp25_ = i;
					_tmp26_ = packages;
					_tmp26__length1 = packages_length1;
					_tmp27_ = i;
					_tmp28_ = _tmp26_[_tmp27_];
					_tmp29_ = g_strchomp (_tmp28_);
					_tmp30_ = g_strdup (_tmp29_);
					_g_free0 (_tmp24_[_tmp25_]);
					_tmp24_[_tmp25_] = _tmp30_;
					_tmp31_ = _tmp24_[_tmp25_];
				}
			}
		}
		is_same = TRUE;
		{
			gint i;
			i = 0;
			{
				gboolean _tmp32_;
				_tmp32_ = TRUE;
				while (TRUE) {
					gboolean _tmp33_;
					gint _tmp35_;
					gchar** _tmp36_;
					gint _tmp36__length1;
					gchar** _tmp37_;
					gint _tmp37__length1;
					gint _tmp38_;
					const gchar* _tmp39_;
					gchar** _tmp40_;
					gint _tmp40__length1;
					gint _tmp41_;
					const gchar* _tmp42_;
					_tmp33_ = _tmp32_;
					if (!_tmp33_) {
						gint _tmp34_;
						_tmp34_ = i;
						i = _tmp34_ + 1;
					}
					_tmp32_ = FALSE;
					_tmp35_ = i;
					_tmp36_ = packages;
					_tmp36__length1 = packages_length1;
					if (!(_tmp35_ < _tmp36__length1)) {
						break;
					}
					_tmp37_ = packages;
					_tmp37__length1 = packages_length1;
					_tmp38_ = i;
					_tmp39_ = _tmp37_[_tmp38_];
					_tmp40_ = self->priv->old_list;
					_tmp40__length1 = self->priv->old_list_length1;
					_tmp41_ = i;
					_tmp42_ = _tmp40_[_tmp41_];
					if (g_strcmp0 (_tmp39_, _tmp42_) != 0) {
						is_same = FALSE;
						break;
					}
				}
			}
		}
		_tmp43_ = packages;
		_tmp43__length1 = packages_length1;
		_tmp44_ = self->priv->old_list;
		_tmp44__length1 = self->priv->old_list_length1;
		if (_tmp43__length1 != _tmp44__length1) {
			is_same = FALSE;
		}
		_tmp45_ = packages;
		_tmp45__length1 = packages_length1;
		_tmp46_ = _tmp45_[0];
		if (g_strcmp0 (_tmp46_, "No updates") != 0) {
			gboolean _tmp47_;
			_tmp47_ = is_same;
			if (!_tmp47_) {
				gchar** _tmp48_;
				gint _tmp48__length1;
				gchar** _tmp49_;
				gint _tmp49__length1;
				gint _tmp50_;
				gint _tmp51_;
				_tmp48_ = packages;
				_tmp48__length1 = packages_length1;
				update_checker_set_count (self, _tmp48__length1);
				_tmp49_ = packages;
				_tmp49__length1 = packages_length1;
				_tmp50_ = update_checker_get_count (self);
				_tmp51_ = _tmp50_;
				g_signal_emit_by_name (self, "update-event", _tmp49_, _tmp49__length1, _tmp51_);
			}
		} else {
			gboolean _tmp52_;
			_tmp52_ = is_same;
			if (!_tmp52_) {
				gchar* _tmp53_;
				gchar** _tmp54_ = NULL;
				gchar** _tmp55_;
				gint _tmp55__length1;
				update_checker_set_count (self, 0);
				_tmp53_ = g_strdup ("No updates");
				_tmp54_ = g_new0 (gchar*, 1 + 1);
				_tmp54_[0] = _tmp53_;
				_tmp55_ = _tmp54_;
				_tmp55__length1 = 1;
				g_signal_emit_by_name (self, "update-event", _tmp55_, 1, 0);
				_tmp55_ = (_vala_array_free (_tmp55_, _tmp55__length1, (GDestroyNotify) g_free), NULL);
			}
		}
		_tmp56_ = packages;
		_tmp56__length1 = packages_length1;
		_tmp57_ = (_tmp56_ != NULL) ? _vala_array_dup2 (_tmp56_, _tmp56__length1) : ((gpointer) _tmp56_);
		_tmp57__length1 = _tmp56__length1;
		self->priv->old_list = (_vala_array_free (self->priv->old_list, self->priv->old_list_length1, (GDestroyNotify) g_free), NULL);
		self->priv->old_list = _tmp57_;
		self->priv->old_list_length1 = _tmp57__length1;
		self->priv->_old_list_size_ = self->priv->old_list_length1;
		_tmp58_ = update_checker_get_update_interval (self);
		_tmp59_ = _tmp58_;
		g_usleep ((gulong) (_tmp59_ * 1000000));
		packages = (_vala_array_free (packages, packages_length1, (GDestroyNotify) g_free), NULL);
		_tmp3_ = (_vala_array_free (_tmp3_, _tmp3__length1, (GDestroyNotify) g_free), NULL);
		_g_free0 (output);
	}
	return result;
}


gint update_checker_get_update_interval (UpdateChecker* self) {
	gint result;
	gint _tmp0_;
	g_return_val_if_fail (self != NULL, 0);
	_tmp0_ = self->priv->interval;
	result = _tmp0_;
	return result;
}


void update_checker_set_update_interval (UpdateChecker* self, gint value) {
	gint _tmp0_;
	g_return_if_fail (self != NULL);
	_tmp0_ = value;
	self->priv->interval = _tmp0_;
}


gint update_checker_get_count (UpdateChecker* self) {
	gint result;
	gint _tmp0_;
	g_return_val_if_fail (self != NULL, 0);
	_tmp0_ = self->priv->package_count;
	result = _tmp0_;
	return result;
}


void update_checker_set_count (UpdateChecker* self, gint value) {
	gint _tmp0_;
	g_return_if_fail (self != NULL);
	_tmp0_ = value;
	self->priv->package_count = _tmp0_;
}


static void g_cclosure_user_marshal_VOID__BOXED_INT_INT (GClosure * closure, GValue * return_value, guint n_param_values, const GValue * param_values, gpointer invocation_hint, gpointer marshal_data) {
	typedef void (*GMarshalFunc_VOID__BOXED_INT_INT) (gpointer data1, gpointer arg_1, gint arg_2, gint arg_3, gpointer data2);
	register GMarshalFunc_VOID__BOXED_INT_INT callback;
	register GCClosure * cc;
	register gpointer data1;
	register gpointer data2;
	cc = (GCClosure *) closure;
	g_return_if_fail (n_param_values == 4);
	if (G_CCLOSURE_SWAP_DATA (closure)) {
		data1 = closure->data;
		data2 = param_values->data[0].v_pointer;
	} else {
		data1 = param_values->data[0].v_pointer;
		data2 = closure->data;
	}
	callback = (GMarshalFunc_VOID__BOXED_INT_INT) (marshal_data ? marshal_data : cc->callback);
	callback (data1, g_value_get_boxed (param_values + 1), g_value_get_int (param_values + 2), g_value_get_int (param_values + 3), data2);
}


static void value_update_checker_init (GValue* value) {
	value->data[0].v_pointer = NULL;
}


static void value_update_checker_free_value (GValue* value) {
	if (value->data[0].v_pointer) {
		update_checker_unref (value->data[0].v_pointer);
	}
}


static void value_update_checker_copy_value (const GValue* src_value, GValue* dest_value) {
	if (src_value->data[0].v_pointer) {
		dest_value->data[0].v_pointer = update_checker_ref (src_value->data[0].v_pointer);
	} else {
		dest_value->data[0].v_pointer = NULL;
	}
}


static gpointer value_update_checker_peek_pointer (const GValue* value) {
	return value->data[0].v_pointer;
}


static gchar* value_update_checker_collect_value (GValue* value, guint n_collect_values, GTypeCValue* collect_values, guint collect_flags) {
	if (collect_values[0].v_pointer) {
		UpdateChecker* object;
		object = collect_values[0].v_pointer;
		if (object->parent_instance.g_class == NULL) {
			return g_strconcat ("invalid unclassed object pointer for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		} else if (!g_value_type_compatible (G_TYPE_FROM_INSTANCE (object), G_VALUE_TYPE (value))) {
			return g_strconcat ("invalid object type `", g_type_name (G_TYPE_FROM_INSTANCE (object)), "' for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		}
		value->data[0].v_pointer = update_checker_ref (object);
	} else {
		value->data[0].v_pointer = NULL;
	}
	return NULL;
}


static gchar* value_update_checker_lcopy_value (const GValue* value, guint n_collect_values, GTypeCValue* collect_values, guint collect_flags) {
	UpdateChecker** object_p;
	object_p = collect_values[0].v_pointer;
	if (!object_p) {
		return g_strdup_printf ("value location for `%s' passed as NULL", G_VALUE_TYPE_NAME (value));
	}
	if (!value->data[0].v_pointer) {
		*object_p = NULL;
	} else if (collect_flags & G_VALUE_NOCOPY_CONTENTS) {
		*object_p = value->data[0].v_pointer;
	} else {
		*object_p = update_checker_ref (value->data[0].v_pointer);
	}
	return NULL;
}


GParamSpec* param_spec_update_checker (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags) {
	ParamSpecUpdateChecker* spec;
	g_return_val_if_fail (g_type_is_a (object_type, TYPE_UPDATE_CHECKER), NULL);
	spec = g_param_spec_internal (G_TYPE_PARAM_OBJECT, name, nick, blurb, flags);
	G_PARAM_SPEC (spec)->value_type = object_type;
	return G_PARAM_SPEC (spec);
}


gpointer value_get_update_checker (const GValue* value) {
	g_return_val_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, TYPE_UPDATE_CHECKER), NULL);
	return value->data[0].v_pointer;
}


void value_set_update_checker (GValue* value, gpointer v_object) {
	UpdateChecker* old;
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, TYPE_UPDATE_CHECKER));
	old = value->data[0].v_pointer;
	if (v_object) {
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, TYPE_UPDATE_CHECKER));
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
		value->data[0].v_pointer = v_object;
		update_checker_ref (value->data[0].v_pointer);
	} else {
		value->data[0].v_pointer = NULL;
	}
	if (old) {
		update_checker_unref (old);
	}
}


void value_take_update_checker (GValue* value, gpointer v_object) {
	UpdateChecker* old;
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, TYPE_UPDATE_CHECKER));
	old = value->data[0].v_pointer;
	if (v_object) {
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, TYPE_UPDATE_CHECKER));
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
		value->data[0].v_pointer = v_object;
	} else {
		value->data[0].v_pointer = NULL;
	}
	if (old) {
		update_checker_unref (old);
	}
}


static void update_checker_class_init (UpdateCheckerClass * klass) {
	update_checker_parent_class = g_type_class_peek_parent (klass);
	UPDATE_CHECKER_CLASS (klass)->finalize = update_checker_finalize;
	g_type_class_add_private (klass, sizeof (UpdateCheckerPrivate));
	g_signal_new ("update_event", TYPE_UPDATE_CHECKER, G_SIGNAL_RUN_LAST, 0, NULL, NULL, g_cclosure_user_marshal_VOID__BOXED_INT_INT, G_TYPE_NONE, 3, G_TYPE_STRV, G_TYPE_INT, G_TYPE_INT);
}


static void update_checker_instance_init (UpdateChecker * self) {
	gchar* _tmp0_;
	gchar** _tmp1_ = NULL;
	self->priv = UPDATE_CHECKER_GET_PRIVATE (self);
	self->priv->interval = 2 * 60;
	_tmp0_ = g_strdup ("No updates");
	_tmp1_ = g_new0 (gchar*, 1 + 1);
	_tmp1_[0] = _tmp0_;
	self->priv->old_list = _tmp1_;
	self->priv->old_list_length1 = 1;
	self->priv->_old_list_size_ = self->priv->old_list_length1;
	self->priv->package_count = 0;
	self->ref_count = 1;
}


static void update_checker_finalize (UpdateChecker* obj) {
	UpdateChecker * self;
	self = UPDATE_CHECKER (obj);
	self->priv->old_list = (_vala_array_free (self->priv->old_list, self->priv->old_list_length1, (GDestroyNotify) g_free), NULL);
}


GType update_checker_get_type (void) {
	static volatile gsize update_checker_type_id__volatile = 0;
	if (g_once_init_enter (&update_checker_type_id__volatile)) {
		static const GTypeValueTable g_define_type_value_table = { value_update_checker_init, value_update_checker_free_value, value_update_checker_copy_value, value_update_checker_peek_pointer, "p", value_update_checker_collect_value, "p", value_update_checker_lcopy_value };
		static const GTypeInfo g_define_type_info = { sizeof (UpdateCheckerClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) update_checker_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (UpdateChecker), 0, (GInstanceInitFunc) update_checker_instance_init, &g_define_type_value_table };
		static const GTypeFundamentalInfo g_define_type_fundamental_info = { (G_TYPE_FLAG_CLASSED | G_TYPE_FLAG_INSTANTIATABLE | G_TYPE_FLAG_DERIVABLE | G_TYPE_FLAG_DEEP_DERIVABLE) };
		GType update_checker_type_id;
		update_checker_type_id = g_type_register_fundamental (g_type_fundamental_next (), "UpdateChecker", &g_define_type_info, &g_define_type_fundamental_info, 0);
		g_once_init_leave (&update_checker_type_id__volatile, update_checker_type_id);
	}
	return update_checker_type_id__volatile;
}


gpointer update_checker_ref (gpointer instance) {
	UpdateChecker* self;
	self = instance;
	g_atomic_int_inc (&self->ref_count);
	return instance;
}


void update_checker_unref (gpointer instance) {
	UpdateChecker* self;
	self = instance;
	if (g_atomic_int_dec_and_test (&self->ref_count)) {
		UPDATE_CHECKER_GET_CLASS (self)->finalize (self);
		g_type_free_instance ((GTypeInstance *) self);
	}
}


static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func) {
	if ((array != NULL) && (destroy_func != NULL)) {
		int i;
		for (i = 0; i < array_length; i = i + 1) {
			if (((gpointer*) array)[i] != NULL) {
				destroy_func (((gpointer*) array)[i]);
			}
		}
	}
}


static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func) {
	_vala_array_destroy (array, array_length, destroy_func);
	g_free (array);
}


static gint _vala_array_length (gpointer array) {
	int length;
	length = 0;
	if (array) {
		while (((gpointer*) array)[length]) {
			length++;
		}
	}
	return length;
}



