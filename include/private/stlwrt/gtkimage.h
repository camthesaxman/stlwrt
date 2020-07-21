
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
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

#ifndef __GTK_IMAGE_H__
#define __GTK_IMAGE_H__

#include <gio/gio.h>
#include <gtkmisc.h>


G_BEGIN_DECLS

#define GTK_TYPE_IMAGE                  (gtk_image_get_type ())
#define GTK_IMAGE(obj)                  (G_TYPE_CHECK_INSTANCE_CAST ((obj), GTK_TYPE_IMAGE, GtkImage))
#define GTK_IMAGE_CLASS(klass)          (G_TYPE_CHECK_CLASS_CAST ((klass), GTK_TYPE_IMAGE, GtkImageClass))
#define GTK_IS_IMAGE(obj)               (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GTK_TYPE_IMAGE))
#define GTK_IS_IMAGE_CLASS(klass)       (G_TYPE_CHECK_CLASS_TYPE ((klass), GTK_TYPE_IMAGE))
#define GTK_IMAGE_GET_CLASS(obj)        (G_TYPE_INSTANCE_GET_CLASS ((obj), GTK_TYPE_IMAGE, GtkImageClass))


typedef struct _GtkImage       GtkImageFat;
typedef struct _GtkImage       GtkImageThin;

typedef struct _GtkImageClass  GtkImageClass;

typedef struct _GtkImagePixmapData  GtkImagePixmapData;
typedef struct _GtkImageImageData   GtkImageImageData;
typedef struct _GtkImagePixbufData  GtkImagePixbufData;
typedef struct _GtkImageStockData   GtkImageStockData;
typedef struct _GtkImageIconSetData GtkImageIconSetData;
typedef struct _GtkImageAnimationData GtkImageAnimationData;
typedef struct _GtkImageIconNameData  GtkImageIconNameData;
typedef struct _GtkImageGIconData     GtkImageGIconData;

struct _GtkImagePixmapData
{
  GdkPixmap *pixmap;
};

struct _GtkImageImageData
{
  GdkImage *image;
};

struct _GtkImagePixbufData
{
  GdkPixbuf *pixbuf;
};

struct _GtkImageStockData
{
  gchar *stock_id;
};

struct _GtkImageIconSetData
{
  GtkIconSet *icon_set;
};

struct _GtkImageAnimationData
{
  GdkPixbufAnimation *anim;
  GdkPixbufAnimationIter *iter;
  guint frame_timeout;
};

struct _GtkImageIconNameData
{
  gchar *icon_name;
  GdkPixbuf *pixbuf;
  guint theme_change_id;
};

struct _GtkImageGIconData
{
  GIcon *icon;
  GdkPixbuf *pixbuf;
  guint theme_change_id;
};

/**
 * GtkImageType:
 * @GTK_IMAGE_EMPTY: there is no image displayed by the widget
 * @GTK_IMAGE_PIXMAP: the widget contains a #GdkPixmap
 * @GTK_IMAGE_IMAGE: the widget contains a #GdkImage
 * @GTK_IMAGE_PIXBUF: the widget contains a #GdkPixbuf
 * @GTK_IMAGE_STOCK: the widget contains a stock icon name (see <xref linkend="gtk-Stock-Items"/>)
 * @GTK_IMAGE_ICON_SET: the widget contains a #GtkIconSet
 * @GTK_IMAGE_ANIMATION: the widget contains a #GdkPixbufAnimation
 * @GTK_IMAGE_ICON_NAME: the widget contains a named icon.
 *  This image type was added in GTK+ 2.6
 * @GTK_IMAGE_GICON: the widget contains a #GIcon.
 *  This image type was added in GTK+ 2.14
 *
 * Describes the image data representation used by a #GtkImage. If you
 * want to get the image from the widget, you can only get the
 * currently-stored representation. e.g.  if the
 * __gtk_image_get_storage_type() returns #GTK_IMAGE_PIXBUF, then you can
 * call __gtk_image_get_pixbuf() but not __gtk_image_get_stock().  For empty
 * images, you can request any storage type (call any of the "get"
 * functions), but they will all return %NULL values.
 */
typedef enum
{
  GTK_IMAGE_EMPTY,
  GTK_IMAGE_PIXMAP,
  GTK_IMAGE_IMAGE,
  GTK_IMAGE_PIXBUF,
  GTK_IMAGE_STOCK,
  GTK_IMAGE_ICON_SET,
  GTK_IMAGE_ANIMATION,
  GTK_IMAGE_ICON_NAME,
  GTK_IMAGE_GICON
} GtkImageType;

/**
 * GtkImage:
 *
 * This struct contain private data only and should be accessed by the functions
 * below.
 */
struct _GtkImage
{
  GtkMisc misc;

  GtkImageType  (storage_type);
  
  union
  {
    GtkImagePixmapData pixmap;
    GtkImageImageData image;
    GtkImagePixbufData pixbuf;
    GtkImageStockData stock;
    GtkImageIconSetData icon_set;
    GtkImageAnimationData anim;
    GtkImageIconNameData name;
    GtkImageGIconData gicon;
  }  (data);

  /* Only used with GTK_IMAGE_PIXMAP, GTK_IMAGE_IMAGE */
  GdkBitmap * (mask);

  /* Only used with GTK_IMAGE_STOCK, GTK_IMAGE_ICON_SET, GTK_IMAGE_ICON_NAME */
  GtkIconSize  (icon_size);
};

struct _GtkImageClass
{
  GtkMiscClass parent_class;

  /* Padding for future expansion */
  void (*_gtk_reserved1) (void);
  void (*_gtk_reserved2) (void);
  void (*_gtk_reserved3) (void);
  void (*_gtk_reserved4) (void);
};

#ifdef G_OS_WIN32
/* Reserve old names for DLL ABI backward compatibility */
#define gtk_image_new_from_file gtk_image_new_from_file_utf8
#define gtk_image_set_from_file gtk_image_set_from_file_utf8
#endif

GType      _T2_gtk_image_get_type (void) G_GNUC_CONST;
GType      _3T_gtk_image_get_type (void) G_GNUC_CONST;
/* Supplied in the STLWRT public libraries */
GType      gtk_image_get_type (void) G_GNUC_CONST;

GtkWidget* __gtk_image_new                (void);
GtkWidget* __gtk_image_new_from_pixmap    (GdkPixmap       *pixmap,
                                         GdkBitmap       *mask);
GtkWidget* __gtk_image_new_from_image     (GdkImage        *image,
                                         GdkBitmap       *mask);
GtkWidget* __gtk_image_new_from_file      (const gchar     *filename);
GtkWidget* __gtk_image_new_from_pixbuf    (GdkPixbuf       *pixbuf);
GtkWidget* __gtk_image_new_from_stock     (const gchar     *stock_id,
                                         GtkIconSize      size);
GtkWidget* __gtk_image_new_from_icon_set  (GtkIconSet      *icon_set,
                                         GtkIconSize      size);
GtkWidget* __gtk_image_new_from_animation (GdkPixbufAnimation *animation);
GtkWidget* __gtk_image_new_from_icon_name (const gchar     *icon_name,
					 GtkIconSize      size);
GtkWidget* __gtk_image_new_from_gicon     (GIcon           *icon,
					 GtkIconSize      size);

void __gtk_image_clear              (GtkImage        *image);
void __gtk_image_set_from_pixmap    (GtkImage        *image,
                                   GdkPixmap       *pixmap,
                                   GdkBitmap       *mask);
void __gtk_image_set_from_image     (GtkImage        *image,
                                   GdkImage        *gdk_image,
                                   GdkBitmap       *mask);
void __gtk_image_set_from_file      (GtkImage        *image,
                                   const gchar     *filename);
void __gtk_image_set_from_pixbuf    (GtkImage        *image,
                                   GdkPixbuf       *pixbuf);
void __gtk_image_set_from_stock     (GtkImage        *image,
                                   const gchar     *stock_id,
                                   GtkIconSize      size);
void __gtk_image_set_from_icon_set  (GtkImage        *image,
                                   GtkIconSet      *icon_set,
                                   GtkIconSize      size);
void __gtk_image_set_from_animation (GtkImage           *image,
                                   GdkPixbufAnimation *animation);
void __gtk_image_set_from_icon_name (GtkImage        *image,
				   const gchar     *icon_name,
				   GtkIconSize      size);
void __gtk_image_set_from_gicon     (GtkImage        *image,
				   GIcon           *icon,
				   GtkIconSize      size);
void __gtk_image_set_pixel_size     (GtkImage        *image,
				   gint             pixel_size);

GtkImageType __gtk_image_get_storage_type (GtkImage   *image);

void       __gtk_image_get_pixmap   (GtkImage         *image,
                                   GdkPixmap       **pixmap,
                                   GdkBitmap       **mask);
void       __gtk_image_get_image    (GtkImage         *image,
                                   GdkImage        **gdk_image,
                                   GdkBitmap       **mask);
GdkPixbuf* __gtk_image_get_pixbuf   (GtkImage         *image);
void       __gtk_image_get_stock    (GtkImage         *image,
                                   gchar           **stock_id,
                                   GtkIconSize      *size);
void       __gtk_image_get_icon_set (GtkImage         *image,
                                   GtkIconSet      **icon_set,
                                   GtkIconSize      *size);
GdkPixbufAnimation* __gtk_image_get_animation (GtkImage *image);
void       __gtk_image_get_icon_name (GtkImage              *image,
				    const gchar          **icon_name,
				    GtkIconSize           *size);
void       __gtk_image_get_gicon     (GtkImage              *image,
				    GIcon                **gicon,
				    GtkIconSize           *size);
gint       __gtk_image_get_pixel_size (GtkImage             *image);

#ifndef GTK_DISABLE_DEPRECATED
/* These three are deprecated */

void       __gtk_image_set      (GtkImage   *image,
			       GdkImage   *val,
			       GdkBitmap  *mask);
void       __gtk_image_get      (GtkImage   *image,
			       GdkImage  **val,
			       GdkBitmap **mask);
#endif /* GTK_DISABLE_DEPRECATED */

G_END_DECLS

#endif /* __GTK_IMAGE_H__ */
