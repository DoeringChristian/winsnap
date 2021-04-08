#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <gtk/gtk.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <cairo.h>
#include <unistd.h>
typedef __useconds_t useconds_t;
#include <xdo.h>
#include "dlist.h"
#include "zone.h"

struct mainwindow{
    GtkWidget *window;
    GtkWidget *da_area;
    struct xdo *xdo;
    Window moving;
    struct dlist layout;
    gboolean supports_alpha;
};

struct mainwindow *mainwindow_init(struct mainwindow *self);
void mainwindow_free(struct mainwindow *self);

void mainwindow_draw(GtkWidget *widget, cairo_t *cr, gpointer data);
void mainwindow_close(GtkWidget *widget, gpointer *data);
int mainwindow_reorder(void *data);
int mainwindow_getpos(void *data);
void mainwindow_changed(GtkWidget *widget, GdkScreen *old_screen, gpointer data);

#endif //MAINWINDOW_H
