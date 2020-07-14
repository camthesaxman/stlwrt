
/* GtkToolPalette -- A tool palette with categories and DnD support
 * Copyright (C) 2008  Openismus GmbH
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 * Authors:
 *      Mathias Hasselmann
 */

#ifndef __GTK_TOOL_ITEM_GROUP_H__
#define __GTK_TOOL_ITEM_GROUP_H__

#if !defined (__GTK_H_INSIDE__) && !defined (STLWRT_COMPILATION)
#error "Only <gtk.h> can be included directly."
#endif

#include <gtkcontainer.h>
#include <gtktoolitem.h>

G_BEGIN_DECLS

#define GTK_TYPE_TOOL_ITEM_GROUP           (gtk_tool_item_group_get_type ())
#define GTK_TOOL_ITEM_GROUP(obj)           (G_TYPE_CHECK_INSTANCE_CAST (obj, GTK_TYPE_TOOL_ITEM_GROUP, GtkToolItemGroup))
#define GTK_TOOL_ITEM_GROUP_CLASS(cls)     (G_TYPE_CHECK_CLASS_CAST (cls, GTK_TYPE_TOOL_ITEM_GROUP, GtkToolItemGroupClass))
#define GTK_IS_TOOL_ITEM_GROUP(obj)        (G_TYPE_CHECK_INSTANCE_TYPE (obj, GTK_TYPE_TOOL_ITEM_GROUP))
#define GTK_IS_TOOL_ITEM_GROUP_CLASS(obj)  (G_TYPE_CHECK_CLASS_TYPE (obj, GTK_TYPE_TOOL_ITEM_GROUP))
#define GTK_TOOL_ITEM_GROUP_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), GTK_TYPE_TOOL_ITEM_GROUP, GtkToolItemGroupClass))

typedef struct _GtkToolItemGroup        GtkToolItemGroupFat;
typedef struct _GtkToolItemGroup        GtkToolItemGroupSkinny;
typedef struct _GtkToolItemGroupClass   GtkToolItemGroupClassFat;
typedef struct _GtkToolItemGroupClass   GtkToolItemGroupClassSkinny;
typedef struct _GtkToolItemGroupPrivate GtkToolItemGroupPrivate;

/**
 * GtkToolItemGroup:
 *
 * This should not be accessed directly. Use the accessor functions below.
 */
struct _GtkToolItemGroup
{
  GtkContainer parent_instance;
  GtkToolItemGroupPrivate *priv;
};

struct _GtkToolItemGroupClass
{
  GtkContainerClass parent_class;
};

GType                 _T2_gtk_tool_item_group_get_type          (void) G_GNUC_CONST;
GType                 _3T_gtk_tool_item_group_get_type          (void) G_GNUC_CONST;
/* Supplied in the STLWRT public libraries */
GType                 gtk_tool_item_group_get_type          (void) G_GNUC_CONST;
GtkWidget*            __gtk_tool_item_group_new               (const gchar        *label);

void                  __gtk_tool_item_group_set_label         (GtkToolItemGroup   *group,
                                                             const gchar        *label);
void                  __gtk_tool_item_group_set_label_widget  (GtkToolItemGroup   *group,
                                                             GtkWidget          *label_widget);
void                  __gtk_tool_item_group_set_collapsed      (GtkToolItemGroup  *group,
                                                             gboolean            collapsed);
void                  __gtk_tool_item_group_set_ellipsize     (GtkToolItemGroup   *group,
                                                             PangoEllipsizeMode  ellipsize);
void                  __gtk_tool_item_group_set_header_relief (GtkToolItemGroup   *group,
                                                             GtkReliefStyle      style);

const gchar *         __gtk_tool_item_group_get_label         (GtkToolItemGroup   *group);
GtkWidget            *__gtk_tool_item_group_get_label_widget  (GtkToolItemGroup   *group);
gboolean              __gtk_tool_item_group_get_collapsed     (GtkToolItemGroup   *group);
PangoEllipsizeMode    __gtk_tool_item_group_get_ellipsize     (GtkToolItemGroup   *group);
GtkReliefStyle        __gtk_tool_item_group_get_header_relief (GtkToolItemGroup   *group);

void                  __gtk_tool_item_group_insert            (GtkToolItemGroup   *group,
                                                             GtkToolItem        *item,
                                                             gint                position);
void                  __gtk_tool_item_group_set_item_position (GtkToolItemGroup   *group,
                                                             GtkToolItem        *item,
                                                             gint                position);
gint                  __gtk_tool_item_group_get_item_position (GtkToolItemGroup   *group,
                                                             GtkToolItem        *item);

guint                 __gtk_tool_item_group_get_n_items       (GtkToolItemGroup   *group);
GtkToolItem*          __gtk_tool_item_group_get_nth_item      (GtkToolItemGroup   *group,
                                                             guint               index);
GtkToolItem*          __gtk_tool_item_group_get_drop_item     (GtkToolItemGroup   *group,
                                                             gint                x,
                                                             gint                y);

G_END_DECLS

#endif /* __GTK_TOOL_ITEM_GROUP_H__ */
