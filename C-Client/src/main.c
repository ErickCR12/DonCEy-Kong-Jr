//
// Created by José Acuña on 17/09/2019.
//

#include <allegro5/allegro.h>


int main()
{
    ALLEGRO_DISPLAY * display;
    ALLEGRO_EVENT_QUEUE *queue;
    ALLEGRO_TIMER *timer;

    al_init();
    display = al_create_display(640, 480);
    queue = al_create_event_queue();
    timer = al_create_timer(1.0 / 60.0);

    al_install_keyboard();
    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_display_event_source(display));
    al_register_event_source(queue, al_get_timer_event_source(timer));

    bool running = true;
    while (running) {


        ALLEGRO_EVENT event;
        al_wait_for_event(queue, &event);
        if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            running = false;

        if (event.type == ALLEGRO_EVENT_TIMER) {
            al_flip_display();
        }
    }

    al_destroy_display(display);
    al_uninstall_keyboard();
    al_destroy_timer(timer);

    return 0;
}