#pragma once

#include "color.h"

void jp_set_caps_key_state(bool state);
bool jp_get_caps_key_state(void);

rgb_t jp_adjusted_colour(hsv_t colour);
void jp_rbg_matrix_set(int index, rgb_t colour);
