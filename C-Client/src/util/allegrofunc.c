//
// Created by Jesica on 9/22/2019.
//

#include "allegrofunc.h"

ALLEGRO_BITMAP *load_bitmap_at_size(ALLEGRO_BITMAP *loaded_bmp, int w, int h)
{
    ALLEGRO_BITMAP *resized_bmp, *prev_target;
    resized_bmp = al_create_bitmap(w, h);
    if (!resized_bmp) return NULL;

    prev_target = al_get_target_bitmap();
    al_set_target_bitmap(resized_bmp);

    al_draw_scaled_bitmap(loaded_bmp,
                          0, 0,                                // source origin
                          al_get_bitmap_width(loaded_bmp),     // source width
                          al_get_bitmap_height(loaded_bmp),    // source height
                          0, 0,                                // target origin
                          w, h,                                // target dimensions
                          0                                    // flags
    );

    al_set_target_bitmap(prev_target);
    free(loaded_bmp);

    return resized_bmp;
}