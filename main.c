#include <gtk-4.0/gtk/gtk.h>
#include "libs/yttGObject.h"

void activate(GtkApplication *app, gpointer data);
void printUrl(GtkWidget *widget, gpointer data);

int main(int argc, char **argv) {
    int status;
    GtkApplication *app;
    
    app = gtk_application_new("ytt", G_APPLICATION_FLAGS_NONE);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);

    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    return status;
}

void activate(GtkApplication *app, gpointer data) {
    yttGObject_t yttGObject;
    GtkBuilder *builder = gtk_builder_new_from_file("glade/main.glade");
    yttGObject.windowMain = gtk_builder_get_object(builder, "windowMain");
    gtk_window_set_application(GTK_WINDOW(yttGObject.windowMain), app);
    g_signal_connect(yttGObject.windowMain, "destroy", G_CALLBACK(gtk_window_destroy), yttGObject.windowMain);
    yttGObject.entryUrl = gtk_builder_get_object(builder, "entryUrl");
    g_signal_connect(yttGObject.entryUrl, "changed", G_CALLBACK(printUrl), NULL);
    // yttGObject.buttonSave = GTK_WIDGET(gtk_builder_get_object(builder, "buttonSave"));
    yttGObject.progressDownload = gtk_builder_get_object(builder, "progressDownload");
    yttGObject.imageVideo = gtk_builder_get_object(builder, "imageVideo");

    g_object_unref(builder);
}

void printUrl(GtkWidget *widget, gpointer data) {
    g_print("prntUrl\n");
}
