/* STLWRT - A fork of GTK+ 2 supporting future applications as well
 * Copyright (C) 1995-1997 Peter Mattis, Spencer Kimball and Josh MacDonald
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	 See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

/*
 * TODO:
 *
 * Look into whether this header file is even necessary anymore!
 *
 */

#ifndef __GTK_TYPE_UTILS_H__
#define __GTK_TYPE_UTILS_H__

/* enum types generated by glib-mkenums
 */
#include <gtktypebuiltins.h>

G_BEGIN_DECLS

/* urg */
#define GTK_TYPE_IDENTIFIER (gtk_identifier_get_type ())
STLWRT_DECLARE_GET_FTYPE_FUNCTIONS(gtk_identifier)

/* --- typedefs --- */
/* here we come with some necessary forward declarations for structures and
 * provide some fundamental function signatures
 */
typedef struct _GtkArg	       	     GtkArg;
typedef struct _GObject   	     GObject; /* object forward declaration */
#if !defined (GTK_DISABLE_DEPRECATED) || defined (STLWRT_COMPILATION)
typedef gboolean (*GtkFunction)	    (gpointer      data);
typedef void (*GtkCallbackMarshal)  (GObject    *object,
				     gpointer      data,
				     guint         n_args,
				     GtkArg       *args);
#endif

/* This used to be defined in gtkitemfactory.h, but moved over here after
 * the complete deprecation of that header
 */
typedef gchar * (*GtkTranslateFunc) (const gchar  *path,
				     gpointer      func_data);

G_END_DECLS

#endif /* __GTK_TYPE_UTILS_H__ */
