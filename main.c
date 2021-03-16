#include <gtk-4.0/gtk/gtk.h>
#include "libs/yttWidgets.h"

int main(int argc, char **argv) {
    yttWidget_t yttWidget;
    GtkBuilder *builder;

    gtk_init();
    builder = gtk_builder_new_from_file("glade/main.glade");
    yttWidget.windowMain = GTK_WIDGET(gtk_builder_get_object(builder, "windowMain"));
    yttWidget.entryUrl = GTK_WIDGET(gtk_builder_get_object(builder, "entryUrl"));
    yttWidget.buttonSave = GTK_WIDGET(gtk_builder_get_object(builder, "buttonSave"));
    yttWidget.progressDownload = GTK_WIDGET(gtk_builder_get_object(builder, "progressDownload"));
    yttWidget.imageVideo = GTK_WIDGET(gtk_builder_get_object(builder, "imageVideo"));

    // g_signal_connect(builder, "activate", G_CALLBACK(activate), NULL);
    g_object_unref(builder);
    gtk_widget_show(yttWidget.windowMain);
    // gtk_main();

    return 0;
}

// void on_windowMain_destroy()
// {
//     gtk_main_quit();
// }
