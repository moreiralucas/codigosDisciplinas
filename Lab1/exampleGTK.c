//g++ exampleGTK.c -o executavel `pkg-config --cflags --libs gtk+-3.0`

/* Primeiro Exemplo - Alo Mundo - alo.c */
#include <gtk/gtk.h>
int main(int argc, char **argv)
{

GtkWidget *janela;
gtk_init(&argc, &argv);
janela = gtk_window_new(GTK_WINDOW_TOPLEVEL);
gtk_window_set_title(GTK_WINDOW (janela), "Alo Mundo");
gtk_widget_show(janela);
gtk_main();
return 0;

}
/* Fim do Primeiro Exemplo */