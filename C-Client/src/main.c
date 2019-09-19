//
// Created by José Acuña on 17/09/2019.
//

#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <unistd.h>

int main (int argc, char **argv){
    ALLEGRO_DISPLAY *display = NULL;

    if (!al_init()){
        al_show_native_message_box(NULL, NULL, NULL, "failed to init allegro!", NULL, 0);
        return -1;
    }
    display = al_create_display(600, 600);
    if (!display){
        al_show_native_message_box(NULL, NULL, NULL, "failed to init display!", NULL, 0);
        return -1;
    }

    sleep(5);

    al_destroy_display(display);
    return 0;
}