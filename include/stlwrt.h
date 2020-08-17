
/*
 * STLWRT - A fork of GTK+ 2 supporting future applications as well
 * Copyright (C) 2020 Gordon N. Squash.
 *
 * This Library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public License as
 * published by the Free Software Foundation; either version 2 of the
 * License, or (at your option) any later version.
 *
 * This Library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; see the file COPYING.  If not,
 * write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

#ifndef __STLWRT_OBJECT_H__
#define __STLWRT_OBJECT_H__

#include <glib.h>


G_BEGIN_DECLS


/* Definitions which STLWRT components use. */

#define STLWRT_DEFINE_TYPE(TN, t_n, T_P) \
         STLWRT_DEFINE_TYPE_EXTENDED (TN, t_n, T_P, 0, {})


#define STLWRT_DEFINE_TYPE_WITH_CODE(TN, t_n, T_P, _C_)	\
         _STLWRT_DEFINE_TYPE_EXTENDED_BEGIN (TN, t_n, T_P, 0) \
         {_C_;} \
         _STLWRT_DEFINE_TYPE_EXTENDED_END()


#define STLWRT_DEFINE_ABSTRACT_TYPE(TN, t_n, T_P) \
         STLWRT_DEFINE_TYPE_EXTENDED (TN, t_n, T_P, G_TYPE_FLAG_ABSTRACT, {})


#define STLWRT_DEFINE_ABSTRACT_TYPE_WITH_CODE(TN, t_n, T_P, _C_) \
         _STLWRT_DEFINE_TYPE_EXTENDED_BEGIN (TN, t_n, T_P, G_TYPE_FLAG_ABSTRACT) \
         {_C_;} \
         _STLWRT_DEFINE_TYPE_EXTENDED_END()


#define STLWRT_DEFINE_INTERFACE(TN, t_n, T_P) \
         STLWRT_DEFINE_INTERFACE_WITH_CODE(TN, t_n, T_P, ;)


#define STLWRT_DEFINE_TYPE_WITH_PRIVATE(TN, t_n, T_P) \
         STLWRT_DEFINE_TYPE_EXTENDED (TN, t_n, T_P, 0, G_ADD_PRIVATE (TN))


/* Definitions only used within this file. */

#define STLWRT_DEFINE_TYPE_EXTENDED(TN, t_n, T_P, _f_, _C_) \
         _STLWRT_DEFINE_TYPE_EXTENDED_BEGIN_PRE(TN, t_n, T_P) \
         _STLWRT_DEFINE_TYPE_EXTENDED_BEGIN_FAT (TN, t_n, T_P, _f_) \
         _STLWRT_DEFINE_TYPE_EXTENDED_BEGIN_THIN (TN, t_n, T_P, _f_) \
         {_C_;} \
         _STLWRT_DEFINE_TYPE_EXTENDED_END() \
         


#define _STLWRT_DEFINE_TYPE_EXTENDED_BEGIN_FAT(TypeName, type_name, TYPE_PARENT, flags) \
  _STLWRT_DEFINE_TYPE_EXTENDED_BEGIN_FAT_PRE(TypeName, type_name, TYPE_PARENT) \
  _STLWRT_DEFINE_TYPE_EXTENDED_BEGIN_FAT_REGISTER(TypeName, type_name, TYPE_PARENT, flags) \
  
#define _STLWRT_DEFINE_TYPE_EXTENDED_BEGIN_THIN(TypeName, type_name, TYPE_PARENT, flags) \
  _STLWRT_DEFINE_TYPE_EXTENDED_BEGIN_THIN_PRE(TypeName, type_name, TYPE_PARENT) \
  _STLWRT_DEFINE_TYPE_EXTENDED_BEGIN_THIN_REGISTER(TypeName, type_name, TYPE_PARENT, flags) \



#define _STLWRT_DEFINE_TYPE_EXTENDED_BEGIN_PRE(TypeName, type_name, TYPE_PARENT) \
\
static void     type_name##_init              (TypeName        *self); \
static void     type_name##_class_init        (TypeName##Class *klass); \
static gpointer type_name##_parent_class = NULL; \
static gint     TypeName##_private_offset; \
\
_STLWRT_DEFINE_TYPE_EXTENDED_CLASS_INIT(TypeName, type_name) \
\
G_GNUC_UNUSED \
static inline gpointer \
type_name##_get_instance_private (TypeName *self) \
{ \
  return (G_STRUCT_MEMBER_P (self, TypeName##_private_offset)) + sizeof(TypeName##Props); \
} \
 \
G_GNUC_UNUSED \
static inline gpointer \
##type_name##_get_instance_props (TypeName *self) \
{ \
  if (gtk_major_version <= 2) \
    return self->parent; \
  else \
    return (G_STRUCT_MEMBER_P (self, TypeName##_private_offset)); \
} \


#define _STLWRT_DEFINE_TYPE_EXTENDED_BEGIN_FAT_PRE(TypeName, type_name, TYPE_PARENT) \
GType \
_T2_##type_name##_get_type (void) \
{ \
  static GType g_define_type_id = 0;
  /* Prelude goes here */

/* Added for _STLWRT_DEFINE_TYPE_EXTENDED_WITH_PRELUDE */
#define _STLWRT_DEFINE_TYPE_EXTENDED_BEGIN_FAT_REGISTER(TypeName, type_name, TYPE_PARENT, flags) \
  if (g_define_type_id == 0)  \
    { \
      g_define_type_id = g_type_register_static_simple (TYPE_PARENT, \
                                     g_intern_static_string (#TypeName), \
                                     sizeof (TypeName##Class), \
                                     (GClassInitFunc)(void (*)(void)) type_name##_class_intern_init, \
                                     sizeof (TypeName##Fat), \
                                     (GInstanceInitFunc)(void (*)(void)) type_name##_init, \
                                     (GTypeFlags) flags); \
      { \
        /* custom code follows */


#define _STLWRT_DEFINE_TYPE_EXTENDED_BEGIN_THIN_PRE(TypeName, type_name, TYPE_PARENT) \
GType \
_3T_##type_name##_get_type (void) \
{ \
  static GType g_define_type_id = 0;
  /* Prelude goes here */

/* Added for _STLWRT_DEFINE_TYPE_EXTENDED_WITH_PRELUDE */
#define _STLWRT_DEFINE_TYPE_EXTENDED_BEGIN_THIN_REGISTER(TypeName, type_name, TYPE_PARENT, flags) \
  if (g_define_type_id == 0)  \
    { \
      g_define_type_id = g_type_register_static_simple (TYPE_PARENT, \
                                     g_intern_static_string (#TypeName), \
                                     sizeof (TypeName##Class), \
                                     (GClassInitFunc)(void (*)(void)) type_name##_class_intern_init, \
                                     sizeof (TypeName##Thin), \
                                     (GInstanceInitFunc)(void (*)(void)) type_name##_init, \
                                     (GTypeFlags) flags); \
      { \
        /* custom code follows */


#define _STLWRT_DEFINE_TYPE_EXTENDED_END()	\
      } /* following custom code */	\
    }					\
  return g_define_type_id;	\
} /* closes __type_name##_get_type() */


#define _STLWRT_DEFINE_TYPE_EXTENDED_CLASS_INIT(TypeName, type_name) \
static void     type_name##_class_intern_init (gpointer klass) \
{ \
  type_name##_parent_class = g_type_class_peek_parent (klass); \
  if (TypeName##_private_offset != 0) \
    g_type_class_adjust_private_offset (klass, &TypeName##_private_offset); \
  type_name##_class_init ((TypeName##Class*) klass); \
}


G_END_DECLS

#endif  /* __STLWRT_OBJECT_H__ */