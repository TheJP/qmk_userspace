// Copyright 2024 splitkb.com (support@splitkb.com)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "keymap_swiss_de.h"

enum layers {
    _COLEMAK = 0,
    _QWERTZ,
    _DVORAK,

    _SHIFT,
    _SYM,
    _NUM,
    _NAV,
    _FUNCTION,
    _ADJUST,

    _BASE_LAYER_START = _COLEMAK,
    _BASE_LAYER_END = _DVORAK + 1,
};

enum custom_keycodes {
    // Toggle encoder behaviour.
    JP_ENC_TOGG = SAFE_RANGE,
};

// Aliases for readability
// TODO: Swtich to PDF when done with testing.
#define QWERTZ   DF(_QWERTZ)
#define COLEMAK  DF(_COLEMAK)
#define DVORAK   DF(_DVORAK)

#define SHIFT    LM(_SHIFT, MOD_LSFT)
#define SYM      MO(_SYM)
#define NUM      MO(_NUM)
#define NAV      MO(_NAV)
#define FKEYS    MO(_FUNCTION)
#define ADJUST   TG(_ADJUST)

#define CTL_ESC  MT(MOD_LCTL, KC_ESC)
#define CTL_QUOT MT(MOD_RCTL, CH_QUOT)
#define CTL_MINS MT(MOD_RCTL, CH_MINS)
#define ALT_ENT  MT(MOD_LALT, KC_ENT)
#define NAV_ENT  LT(_NAV, KC_ENT)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: Colemak
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  Tab   |   Q  |   W  |   F  |   P  |   G  |                              |   J  |   L  |   U  |   Y  | ;  : |  Bksp  |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * | Shift  |   A  |   R  |   S  |   T  |   D  |                              |   H  |   N  |   E  |   I  |   O  |  Shift |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |Ctrl/Esc|   Z  |   X  |   C  |   V  |   B  | Nav  |F-Keys|  |Adjust|  ??? |   K  |   M  | ,  ; | .  : | /  ? | Ctrl/' |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        | LAlt | LGUI | NUM  | Sym  | Space|  | Space| Nav/ | AltGr| Menu |LClick|
 *                        |      |      |      |      |      |  |      | Enter|      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 *   ,----------------------------------.                                            ,----------------------------------.
 *   | MUTE |      |      |      |      |                                            |EncTog|      |      |      |      |
 *   `----------------------------------'                                            `----------------------------------'
 */
[_COLEMAK] = LAYOUT_split_3x6_5_hlc(
    KC_TAB ,  CH_Q  , CH_W   ,  CH_F  ,   CH_P ,  CH_G  ,                                      CH_J  ,  CH_L  ,  CH_U  ,  CH_Y  , CH_SCLN, KC_BSPC ,
    SHIFT  ,  CH_A  , CH_R   ,  CH_S  ,   CH_T ,  CH_D  ,                                      CH_H  ,  CH_N  ,  CH_E  ,  CH_I  ,  CH_O  , SHIFT   ,
    CTL_ESC,  CH_Z  , CH_X   ,  CH_C  ,   CH_V ,  CH_B  , NAV , FKEYS ,     ADJUST , KC_NO  ,  CH_K  ,  CH_M  , CH_COMM, CH_DOT , CH_SLSH, CTL_QUOT,
                               KC_LALT, KC_LGUI,  NUM   , SYM , KC_SPC,     KC_SPC , NAV_ENT, KC_RALT, KC_APP , MS_BTN1,
    KC_MUTE,  KC_NO ,  KC_NO ,  KC_NO ,  KC_NO ,                                                   JP_ENC_TOGG,  KC_NO ,  KC_NO ,  KC_NO ,  KC_NO
),

/*
 * Base Layer: QWERTZ
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  Tab   |   Q  |   W  |   E  |   R  |   T  |                              |   Z  |   U  |   I  |   O  |   P  |  Bksp  |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * | LShift |   A  |   S  |   D  |   F  |   G  |                              |   H  |   J  |   K  |   L  | ;  : | RShift |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |Ctrl/Esc|   Y  |   X  |   C  |   V  |   B  | Nav  |F-Keys|  |Adjust|  ??? |   N  |   M  | ,  ; | .  : | /  ? | Ctrl/' |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        | LAlt | LGUI | NUM  | Sym  | Space|  | Space| Enter| AltGr| Menu | ???  |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 *   ,----------------------------------.                                            ,----------------------------------.
 *   | MUTE |      |      |      |      |                                            | MUTE |      |      |      |      |
 *   `----------------------------------'                                            `----------------------------------'
 */
[_QWERTZ] = LAYOUT_split_3x6_5_hlc(
    KC_TAB  , CH_Q ,  CH_W   , CH_E   ,   CH_R ,   CH_T ,                                     CH_Z,   CH_U ,  CH_I ,   CH_O ,    CH_P , KC_BSPC,
    KC_LSFT , CH_A ,  CH_S   , CH_D   ,   CH_F ,   CH_G ,                                     CH_H,   CH_J ,  CH_K ,   CH_L , CH_SCLN , KC_RSFT,
    CTL_ESC , CH_Y ,  CH_X   , CH_C   ,   CH_V ,   CH_B , NAV , FKEYS ,     ADJUST , CH_RBRC, CH_N,   CH_M ,CH_COMM, CH_DOT , CH_SLSH , CTL_QUOT,
                               KC_LALT, KC_LGUI,   NUM  , SYM , KC_SPC,     KC_SPC , KC_ENT , KC_RALT, KC_APP, CH_RBRC,
    KC_MUTE, KC_NO,  KC_NO, KC_NO, KC_NO,                                                             KC_MUTE, KC_NO, KC_NO, KC_NO, KC_NO
),

// TODO: Didn't touch Dvorak yet
/*
 * Base Layer: Dvorak
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  Tab   | '    | , <  | . >  |   P  |   Y  |                              |   F  |   G  |   C  |   R  |   L  |  Bksp  |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |Ctrl/Esc|   A  |   O  |   E  |   U  |   I  |                              |   D  |   H  |   T  |   N  |   S  |Ctrl/- _|
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LShift | ; :  |   Q  |   J  |   K  |   X  | [ {  |CapsLk|  |F-keys|  ] } |   B  |   M  |   W  |   V  |   Z  | RShift |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |Adjust| LGUI | LAlt/| Space| Nav  |  | Sym  | Space| AltGr| RGUI | Menu |
 *                        |      |      | Enter|      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 *   ,----------------------------------.                                            ,----------------------------------.
 *   | MUTE |      |      |      |      |                                            | MUTE |      |      |      |      |
 *   `----------------------------------'                                            `----------------------------------'
 */
[_DVORAK] = LAYOUT_split_3x6_5_hlc(
    KC_TAB  ,KC_QUOTE,KC_COMM,  KC_DOT,   KC_P ,   KC_Y ,                                        KC_F,   KC_G ,  KC_C ,   KC_R ,  KC_L , KC_BSPC,
    CTL_ESC , KC_A ,  KC_O   ,  KC_E  ,   KC_U ,   KC_I ,                                        KC_D,   KC_H ,  KC_T ,   KC_N ,  KC_S , CTL_MINS,
    KC_LSFT ,KC_SCLN, KC_Q   ,  KC_J  ,   KC_K ,   KC_X , KC_LBRC,KC_CAPS,     FKEYS  , KC_RBRC, KC_B,   KC_M ,  KC_W ,   KC_V ,  KC_Z , KC_RSFT,
                                ADJUST, KC_LGUI, ALT_ENT, KC_SPC , NAV   ,     SYM    , KC_SPC ,KC_RALT, KC_RGUI, KC_APP,
    KC_MUTE, KC_NO,  KC_NO, KC_NO, KC_NO,                                                                KC_MUTE, KC_NO, KC_NO, KC_NO, KC_NO
),

/*
 * Base Layer: Shift
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              |      |      |      |      | ;  : | S(Del) |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |                              |      |      |      |      |      | RShift |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |Ctrl/Esc|      |      |      |      |      |      |      |  |      |      |      |      | ,  ; | .  : | /  ? | Ctrl/' |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 *   ,----------------------------------.                                            ,----------------------------------.
 *   |      |      |      |      |      |                                            |      |      |      |      |      |
 *   `----------------------------------'                                            `----------------------------------'
 */
[_SHIFT] = LAYOUT_split_3x6_5_hlc(
    _______, _______, _______, _______, _______, _______,                                         _______, _______, _______, _______, CH_COLN, KC_DEL  ,
    _______, _______, _______, _______, _______, _______,                                         _______, _______, _______, _______, _______, _______ ,
    CTL_ESC, _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, CH_SCLN, CH_COLN, CH_QUES, CTL_QUOT,
                               _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,                                                           _______, _______, _______, _______, _______
),

/*
 * Sym Layer: Symbols (missing: ç, ¬, ´)
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |    ~   |   !  |   @  |   #  |   %  |   $  |                              |   _  |   &  |   *  |      |   `  |   "    |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * | LShift |   ^  |   <  |   [  |   (  |   {  |                              |   }  |   )  |   ]  |   >  |   =  | RShift |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |   \  |  :   |  ;   |   ä  |   ö  |      |      |  |      |      |   ü  |   |  | ,  ; | .  : | /  ? | Ctrl/' |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 *   ,----------------------------------.                                            ,----------------------------------.
 *   |      |      |      |      |      |                                            |      |      |      |      |      |
 *   `----------------------------------'                                            `----------------------------------'
 */
[_SYM] = LAYOUT_split_3x6_5_hlc(
    CH_TILD, CH_EXLM, CH_AT  , CH_HASH, CH_PERC, CH_DLR ,                                            CH_UNDS, CH_AMPR, CH_ASTR, _______, CH_GRV , CH_DQUO,
    KC_LSFT, CH_CIRC, CH_LABK, CH_LBRC, CH_LPRN, CH_LCBR,                                            CH_RCBR, CH_RPRN, CH_RBRC, CH_RABK, CH_EQL , KC_RSFT,
    _______, CH_BSLS, CH_COLN, CH_SCLN, CH_ADIA, CH_ODIA, _______, _______,    _______, JP_ENC_TOGG, CH_UDIA, CH_PIPE, CH_COMM, CH_DOT , CH_SLSH, CH_QUOT,
                               _______, _______, _______, _______, _______,    _______,   _______  , _______, _______, MS_BTN2,
    _______, _______, _______, _______, _______,                                                              _______, _______, _______, _______, _______
),

/*
 * Num Layer: Numbers
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |   §  |  °   |  £   |  €   |  $   |                              |   +  |  7   |  8   |  9   |  %   |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        | C(¨) |  ¨   |      |  =   | C(§) |                              |   -  |  4   |  5   |  6   |  *   |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |   \  |      |      |      |      |      |      |  |      |      |   0  |  1   |  2   |  3   |  /   |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 *   ,----------------------------------.                                            ,----------------------------------.
 *   |      |      |      |      |      |                                            |      |      |      |      |      |
 *   `----------------------------------'                                            `----------------------------------'
 */
 // Used to comment in some IDEs: C(§) == C(CH_SECT)
 // Used to open terminal in some IDEs: C(¨) == C(CH_DIAE)
[_NUM] = LAYOUT_split_3x6_5_hlc(
    _______,   CH_SECT , CH_DEG , CH_PND , CH_EURO,   CH_DLR  ,                                        CH_PLUS,   CH_7 ,   CH_8 ,   CH_9 , CH_PERC, _______,
    _______, C(CH_DIAE), CH_DIAE, _______, CH_EQL , C(CH_SECT),                                        CH_MINS,   CH_4 ,   CH_5 ,   CH_6 , CH_ASTR, _______,
    _______,   CH_BSLS , _______, _______, _______,   _______ , _______, _______,    _______, _______,   CH_0 ,   CH_1 ,   CH_2 ,   CH_3 , CH_SLSH, _______,
                                  _______, _______,   _______ , _______, _______,    _______, _______, _______, _______, MS_BTN3,
    _______,   _______ , _______, _______, _______,                                                             _______, _______, _______, _______, _______
),

/*
 * Nav Layer: Media, navigation
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              | Home | PgUp |   ↑  | PgDn | VolUp| Delete |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  GUI |  Alt | Shift| Ctrl |      |                              | End  |  ←   |   ↓  |   →  | VolDn| Insert |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        | Pause|M Prev|M Play|M Next|      |      |ScLck |  |      |      |      | ←GUI |      | GUI→ |VolMut| PrtSc  |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 *   ,----------------------------------.                                            ,----------------------------------.
 *   |      |      |      |      |      |                                            |      |      |      |      |      |
 *   `----------------------------------'                                            `----------------------------------'
 */
[_NAV] = LAYOUT_split_3x6_5_hlc(
    _______, _______ , _______, _______, _______, _______,                                        KC_HOME,     KC_PGUP , KC_UP  ,     KC_PGDN , KC_VOLU, KC_DEL,
    _______, KC_LGUI , KC_LALT, KC_LSFT, KC_LCTL, _______,                                        KC_END ,     KC_LEFT , KC_DOWN,     KC_RGHT , KC_VOLD, KC_INS,
    _______, KC_PAUSE, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______, _______,    _______, _______, _______, LCG(KC_LEFT), _______, LCG(KC_RGHT), KC_MUTE, KC_PSCR,
                                _______, _______, _______, _______, _______,    _______, _______, _______,     _______ , _______,
    _______, _______ , _______, _______, _______,                                                              _______ , _______,     _______ , _______, _______
),

/*
 * Function Layer: Function keys
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              |  F12 |  F7  |  F8  |  F9  |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  GUI |  Alt | Shift| Ctrl |      |                              |  F11 |  F4  |  F5  |  F6  |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |      |  |      |      |  F10 |  F1  |  F2  |  F3  |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 *   ,----------------------------------.                                            ,----------------------------------.
 *   |      |      |      |      |      |                                            |      |      |      |      |      |
 *   `----------------------------------'                                            `----------------------------------'
 */
[_FUNCTION] = LAYOUT_split_3x6_5_hlc(
    _______, _______, _______, _______, _______, _______,                                        KC_F12 ,  KC_F7 ,  KC_F8 ,  KC_F9 , _______, _______,
    _______, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, _______,                                        KC_F11 ,  KC_F4 ,  KC_F5 ,  KC_F6 , _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______,    _______, _______, KC_F10 ,  KC_F1 ,  KC_F2 ,  KC_F3 , _______, _______,
                               _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,                                                          _______, _______, _______, _______, _______
),

/*
 * Adjust Layer: Default layer settings, RGB
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |QWERTZ|      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |      |Dvorak|      |      |                              | TOG  | SAI  | HUI  | VAI  | MOD  |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |Colmak|      |      |      |      |  |      |      |      | SAD  | HUD  | VAD  | RMOD |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 *   ,----------------------------------.                                            ,----------------------------------.
 *   |      |      |      |      |      |                                            |      |      |      |      |      |
 *   `----------------------------------'                                            `----------------------------------'
 */
[_ADJUST] = LAYOUT_split_3x6_5_hlc(
    _______, _______, _______, QWERTZ , _______, _______,                                       _______, _______, _______, _______, _______, _______,
    _______, _______, _______, DVORAK , _______, _______,                                       RM_TOGG, RM_SATU, RM_HUEU, RM_VALU, RM_NEXT, _______,
    _______, _______, _______, COLEMAK, _______, _______,_______, _______,    _______, _______, _______, RM_SATD, RM_HUED, RM_VALD, RM_PREV, _______,
                               _______, _______, _______,_______, _______,    _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,                                                         _______, _______, _______, _______, _______
),

// /*
//  * Halcyon Layer template
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  *   ,----------------------------------.                                            ,----------------------------------.
//  *   |      |      |      |      |      |                                            |      |      |      |      |      |
//  *   `----------------------------------'                                            `----------------------------------'
//  */
//     [_LAYERINDEX] = LAYOUT_split_3x6_5_hlc(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//
//       _______, _______, _______, _______, _______,                                                       _______, _______, _______, _______, _______
//     ),
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_COLEMAK  ] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(MS_WHLU, MS_WHLD), ENCODER_CCW_CW(MS_WHLL, MS_WHLR) },
    [_QWERTZ   ] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
    [_DVORAK   ] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
    [_SHIFT    ] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
    [_NAV      ] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
    [_SYM      ] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
    [_NUM      ] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
    [_FUNCTION ] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
    [_ADJUST   ] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
};
// MS_WHLU == QK_MOUSE_WHEEL_UP
// MS_WHLD == QK_MOUSE_WHEEL_DOWN
// MS_WHLL == QK_MOUSE_WHEEL_LEFT
// MS_WHLR == QK_MOUSE_WHEEL_RIGHT
#endif

enum encoder_modes {
    ENC_SCROLL = 0,
    ENC_MOUSE,
    ENC_VOLUME,

    ENC_END,
    ENC_START = 0,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static enum encoder_modes encoder = ENC_SCROLL;
    uint8_t mod_state = get_mods();

    switch (keycode) {
        case QK_MOUSE_WHEEL_UP:
        case QK_MOUSE_WHEEL_DOWN:
        case QK_MOUSE_WHEEL_LEFT:
        case QK_MOUSE_WHEEL_RIGHT:
        {
            switch (encoder) {
                case ENC_SCROLL:
                    break;
                case ENC_MOUSE:
                    keycode += QK_MOUSE_CURSOR_UP - QK_MOUSE_WHEEL_UP;
                    break;
                case ENC_VOLUME:
                    if (keycode == QK_MOUSE_WHEEL_LEFT || keycode == QK_MOUSE_WHEEL_RIGHT) {
                        keycode -= QK_MOUSE_WHEEL_LEFT - KC_AUDIO_VOL_UP;
                    }
                    break;
                default:
                    break;
            }

            bool speed_up = false;
            // 3x scrolling if _SYM key is pressed.
            if (record->event.pressed && layer_state_is(_SYM)) {
                tap_code(keycode);
                tap_code(keycode);
                tap_code(keycode);
                speed_up = true;
            }
            // 3x scrolling if _NUM key is pressed (6x scrolling if both are pressed).
            if (record->event.pressed && layer_state_is(_NUM)) {
                tap_code(keycode);
                tap_code(keycode);
                tap_code(keycode);
                speed_up = true;
            }
            if (record->event.pressed && !speed_up) {
                tap_code(keycode);
            }
            return false;
        }
        case JP_ENC_TOGG:
            if (record->event.pressed) {
                encoder += 1;
                if (encoder >= ENC_END) {
                    encoder = ENC_START;
                }
            }
            return false;
        case CH_CIRC:
        case CH_DIAE:
        case CH_GRV:
        case CH_ACUT:
        case CH_TILD:
            if (record->event.pressed) {
                tap_code16(keycode);
                tap_code16(KC_SPC);
            }
            return false;
        case CH_ADIA:
        case CH_ODIA:
        case CH_UDIA:
            if ((mod_state & MOD_MASK_SHIFT) && layer_state_is(_SYM)) {
                if (record->event.pressed) {
                    clear_mods();
                    tap_code(CH_DIAE);
                    if (keycode == CH_ADIA) tap_code16(S(CH_A));
                    else if (keycode == CH_ODIA) tap_code16(S(CH_O));
                    else if (keycode == CH_UDIA) tap_code16(S(CH_U));
                    set_mods(mod_state);
                }
                return false;
            }
            return true;
    }

    return true;
}

static rgb_t adjusted_colour(hsv_t colour) {
    if (colour.v > rgb_matrix_get_val()) {
        colour.v = rgb_matrix_get_val();
    }
    return hsv_to_rgb(colour);
}

static void jp_rbg_matrix_set(int index, rgb_t colour) {
    rgb_matrix_set_color(index, colour.r, colour.g, colour.b);
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    rgb_t rgb_green = adjusted_colour((hsv_t){HSV_GREEN});
    rgb_t rgb_blue = adjusted_colour((hsv_t){HSV_BLUE});
    rgb_t rgb_purple = adjusted_colour((hsv_t){195, 255, 130});

    uint8_t layer = get_highest_layer(layer_state);
    if (layer < _BASE_LAYER_END) {
        return false;
    }

    for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
        for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
            uint8_t index = g_led_config.matrix_co[row][col];
            if (index < led_min || index >= led_max || index == NO_LED) {
                continue;
            }
            
            uint16_t key = keymap_key_to_keycode(layer, (keypos_t){col,row});
            switch (key) {
                case KC_NO:
                case KC_TRNS:
                    break;
                case CH_1 ... CH_0:
                case KC_F1 ... KC_F12:
                case KC_RIGHT:
                case KC_LEFT:
                case KC_DOWN:
                case KC_UP:
                case KC_LGUI:
                case KC_LALT:
                case KC_LSFT:
                case KC_LCTL:
                    jp_rbg_matrix_set(index, rgb_green);
                    break;
                case KC_HOME:
                case KC_PAGE_UP:
                case KC_END:
                case KC_PAGE_DOWN:
                    jp_rbg_matrix_set(index, rgb_purple);
                    break;
                default:
                    jp_rbg_matrix_set(index, rgb_blue);
                    break;
            }
        }
    }

    return false;
}
