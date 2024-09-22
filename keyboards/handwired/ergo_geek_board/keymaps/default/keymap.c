// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "quantum/keymap_extras/keymap_swedish.h"



enum custom_layers {
    _BASE,     // Base Layer: Swedish QWERTY
    _EXTRA,     //
    _SYMBOLS,  // Symbols Layer: accessed via Layer Tap
    _NUMBERS,   // Numbers Layer or other layer as needed
    _DWM           //
};

enum combos {
  DWM_CLOSE_APP,
  DWM_2,
  DWM_TERMINAL,
  DWM_BROWSER,
  DWM_DMENU,
  DWM_FULLSCREEN,
  DWM_CONSOLE,

};

const uint16_t PROGMEM dwm_combo_jq[] = {KC_J, KC_Q, COMBO_END};
const uint16_t PROGMEM dwm_combo_js[] = {KC_J, KC_S, COMBO_END};
const uint16_t PROGMEM dwm_combo_jd[] = {KC_J, KC_D, COMBO_END};
const uint16_t PROGMEM dwm_combo_jr[] = {KC_J, KC_R, COMBO_END};
const uint16_t PROGMEM dwm_combo_jc[] = {KC_J, KC_C, COMBO_END};
const uint16_t PROGMEM dwm_combo_jf[] = {KC_J, KC_F, COMBO_END};
const uint16_t PROGMEM dwm_combo_jv[] = {KC_J, KC_V, COMBO_END};

combo_t key_combos[] = {
  [DWM_CLOSE_APP] = COMBO(dwm_combo_jq, LALT(KC_Q)),
  [DWM_2] = COMBO(dwm_combo_js, LALT(SE_2)),
  [DWM_TERMINAL] = COMBO(dwm_combo_jd, LALT(SE_3)),
  [DWM_BROWSER] = COMBO(dwm_combo_jr, LALT(SE_4)),
  [DWM_DMENU] = COMBO(dwm_combo_jc, LALT(SE_D)),
  [DWM_FULLSCREEN] = COMBO(dwm_combo_jf, LALT(SE_F)),
  [DWM_CONSOLE] = COMBO(dwm_combo_jv, LALT(KC_ENT)),

};


const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 *              ┌───┐                                          ┌───┐
 *          ┌───┤ E │                                          │ I ├───┐
 *          │ W ├───┼───┬───┐                          ┌───┬───┼───┤ O │
 *  ┌───┬───┼───┤ D │ R │ T │                          │ Y │ U │ K │───┼───┬───┐
 *  │TAB│ Q │ S ├───┼───┼───┤                          ├───┼───┼───┤ L │ P │ å │
 *  ├───┼───┼───┤ C │ F │ G │                          │ H │ J │ , │───┼───┼───┤
 *  │ESC│ A │ X ├───┼───┼───┤                          ├───┼───┼───┤ . │ ; │ Ö │
 *  ├───┼───┼───┤   │ V │ B │                          │ N │ M │   ├───┼───┼───┤
 *  │   │ Z │   ├───┴───┴───┘                          └───┴───┴───┤   │ C │ Ö │
 *  └───┴───┴───┘                                                  └───┴───┴───┘
 *                  ┌───┬───┐  ┌───┬───┐    ┌───┬───┐  ┌───┬───┐
 *                  │<- │-> │  │BAC│DEL│    │BAC│DEL│  │BAC│DEL│
 *                  └───┴───┘  └───┴───┘    └───┴───┘  └───┴───┘
 *
 */


    [_BASE] = LAYOUT_6x4(
        // Left half
        KC_TAB,  SE_Q,    KC_W,  KC_E, KC_R, KC_T,
        KC_ESC,  KC_A,    KC_S,  KC_D, LT(_EXTRA, KC_F), KC_G,
        KC_Z, KC_TRNS,    KC_X,  KC_C, KC_V, KC_B,

        KC_LEFT, LT(_SYMBOLS, KC_RIGHT), KC_TRNS, KC_TRNS, MT(MOD_LCTL, KC_BSPC), MT(MOD_LSFT, KC_DEL),

        // Right half
        KC_Y,  KC_U,    KC_I,    KC_O,  KC_P,  KC_S,
        KC_H,  KC_J,    KC_K,    KC_L,  SE_SCLN,  SE_UNDS,
        KC_N, KC_M,    KC_COMM,  KC_DOT, SE_SLSH, SE_QUOT,

        MT(MOD_LALT, KC_ENT), MT(MOD_LCTL, KC_SPC),  KC_DOT , KC_DOT , LT(_SYMBOLS, KC_UP), KC_DOWN
    ),


    [_EXTRA] = LAYOUT_6x4(
        // Left half
        _______,  _______,    _______,  _______, _______, _______,
        _______,  _______,    _______,  _______, _______, _______,
        _______, _______,    _______,  _______, _______, _______,

        KC_LEFT, LT(_SYMBOLS, KC_RIGHT), KC_TRNS, KC_TRNS, MT(MOD_LCTL, KC_BSPC), MT(MOD_LSFT, KC_DEL),

        // Right half
        _______,  _______,    _______,  _______, _______, _______,
        _______,  _______,    _______,  _______, SE_ADIA, SE_ARNG,
        _______, _______,    _______,  _______, _______, SE_ODIA,

        KC_ENT, KC_SPC,  KC_DOT , KC_DOT , LT(_SYMBOLS, KC_UP), KC_DOWN
    ),


    [_SYMBOLS] = LAYOUT_6x4(
        // Left half
        SE_ASTR,  KC_1,    KC_2,  KC_3, KC_4, KC_5,
        KC_ESC,  SE_HASH,    SE_LBRC,  SE_LPRN, SE_LCBR, SE_DLR,
        SE_CIRC, KC_TRNS,    SE_TILD,  SE_EQL, SE_EXLM, SE_GRV,

        SE_LABK, LT(_SYMBOLS, KC_RIGHT), SE_PERC, KC_TRNS, MT(MOD_LCTL, KC_BSPC), MT(MOD_LSFT, KC_DEL),

        // Right half
        KC_6,  KC_7,    KC_8,    KC_9,  KC_0,  KC_MINUS,
        SE_AMPR,  SE_RCBR,    SE_RPRN,    SE_RBRC,  SE_COLN, SE_DQUO,
        SE_AT, SE_QUES,    SE_PLUS,  SE_PIPE, SE_BSLS, _______,

        KC_ENT, KC_SPC,  KC_NO , KC_NO , LT(_SYMBOLS, KC_UP), SE_RABK
    ),

};
