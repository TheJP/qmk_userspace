// !!! DO NOT ADD #pragma once !!! //

RGB_MATRIX_EFFECT(THEJP)
RGB_MATRIX_EFFECT(THEJP_UNDERGLOW)
RGB_MATRIX_EFFECT(OFF)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS
#include "jp_util.h"
#include "caps_word.h"

static bool jp_custom_effect(effect_params_t* params, rgb_t rgb_upper) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);
    rgb_t rgb_green = jp_adjusted_colour((hsv_t){HSV_GREEN});
    rgb_t rgb_purple = jp_adjusted_colour((hsv_t){195, 255, 130});

    for (uint8_t i = led_min; i < led_max; i++) {
        if (HAS_ANY_FLAGS(g_led_config.flags[i], LED_FLAG_UNDERGLOW)) {
            jp_rbg_matrix_set(i, jp_get_caps_key_state() ? rgb_purple : rgb_green);
        } else if (HAS_ANY_FLAGS(g_led_config.flags[i], (LED_FLAG_MODIFIER | LED_FLAG_KEYLIGHT | LED_FLAG_INDICATOR))) {
            jp_rbg_matrix_set(i, rgb_upper);
        }
    }

    return rgb_matrix_check_finished_leds(led_max);
}

static bool THEJP(effect_params_t* params) {
    rgb_t rgb_default = jp_adjusted_colour(rgb_matrix_get_hsv());
    return jp_custom_effect(params, rgb_default);
}

static bool THEJP_UNDERGLOW(effect_params_t* params) {
    return jp_custom_effect(params, (rgb_t){RGB_OFF});
}

static bool OFF(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);
    for (uint8_t i = led_min; i < led_max; i++) {
        if (HAS_ANY_FLAGS(g_led_config.flags[i], LED_FLAG_ALL)) {
            rgb_matrix_set_color(i, HSV_OFF);
        }
    }
    return rgb_matrix_check_finished_leds(led_max);
}

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS