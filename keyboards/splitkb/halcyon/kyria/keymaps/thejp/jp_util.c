#include "jp_util.h"
#include "rgb_matrix.h"

static bool jp_caps_key_state;

void jp_set_caps_key_state(bool state) {
    jp_caps_key_state = state;
}

bool jp_get_caps_key_state(void) {
    return jp_caps_key_state;
}

rgb_t jp_adjusted_colour(hsv_t colour) {
    if (colour.v > rgb_matrix_get_val()) {
        colour.v = rgb_matrix_get_val();
    }
    return hsv_to_rgb(colour);
}

void jp_rbg_matrix_set(int index, rgb_t colour) {
    rgb_matrix_set_color(index, colour.r, colour.g, colour.b);
}