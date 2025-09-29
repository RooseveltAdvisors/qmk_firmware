#include QMK_KEYBOARD_H

// Dual function key definitions adapted from ZSA Voyager jon_custom
#define DUAL_FUNC_0 LT(1, KC_Q)    // Q / Layer 1
#define DUAL_FUNC_1 LT(2, KC_W)    // W / Layer 2
#define DUAL_FUNC_2 LT(3, KC_E)    // E / Layer 3
#define DUAL_FUNC_3 LT(1, KC_R)    // R / Layer 1
#define DUAL_FUNC_4 LT(2, KC_T)    // T / Layer 2
#define DUAL_FUNC_5 LT(1, KC_A)    // A / Layer 1
#define DUAL_FUNC_6 LT(2, KC_S)    // S / Layer 2
#define DUAL_FUNC_7 LT(1, KC_G)    // G / Layer 1
#define DUAL_FUNC_8 LT(3, KC_AT)   // @ / Layer 3
#define DUAL_FUNC_9 LT(2, KC_Z)    // Z / Layer 2
#define DUAL_FUNC_10 LT(1, KC_X)   // X / Layer 1
#define DUAL_FUNC_11 LT(2, KC_B)   // B / Layer 2
#define DUAL_FUNC_12 LT(2, KC_Y)   // Y / Layer 2
#define DUAL_FUNC_13 LT(1, KC_U)   // U / Layer 1
#define DUAL_FUNC_14 LT(2, KC_I)   // I / Layer 2
#define DUAL_FUNC_15 LT(3, KC_O)   // O / Layer 3
#define DUAL_FUNC_16 LT(2, KC_P)   // P / Layer 2
#define DUAL_FUNC_17 LT(2, KC_EQUAL) // = / Layer 2
#define DUAL_FUNC_18 LT(1, KC_H)   // H / Layer 1
#define DUAL_FUNC_19 LT(2, KC_L)   // L / Layer 2
#define DUAL_FUNC_20 LT(2, KC_SCLN) // ; / Layer 2
#define DUAL_FUNC_21 LT(2, KC_N)   // N / Layer 2
#define DUAL_FUNC_22 LT(1, KC_M)   // M / Layer 1
#define DUAL_FUNC_23 LT(2, KC_COMMA) // , / Layer 2
#define DUAL_FUNC_24 LT(3, KC_DOT) // . / Layer 3
#define DUAL_FUNC_25 LT(3, KC_SLASH) // / / Layer 3

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       MEH_T(KC_TAB), DUAL_FUNC_0, DUAL_FUNC_1, DUAL_FUNC_2, DUAL_FUNC_3, DUAL_FUNC_4,    DUAL_FUNC_12, DUAL_FUNC_13, DUAL_FUNC_14, DUAL_FUNC_15, DUAL_FUNC_16, DUAL_FUNC_17,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
 ALL_T(KC_ESC), DUAL_FUNC_5, DUAL_FUNC_6, MT(MOD_LALT,KC_D), MT(MOD_LGUI,KC_F), DUAL_FUNC_7,    DUAL_FUNC_18, MT(MOD_RGUI,KC_J), MT(MOD_RALT,KC_K), DUAL_FUNC_19, DUAL_FUNC_20, MT(MOD_RSFT,KC_QUOTE),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      DUAL_FUNC_8, DUAL_FUNC_9, DUAL_FUNC_10, KC_C, KC_V, DUAL_FUNC_11,         DUAL_FUNC_21, DUAL_FUNC_22, DUAL_FUNC_23, DUAL_FUNC_24, DUAL_FUNC_25, KC_BSLS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_NO, TO(1), MT(MOD_LSFT,KC_BSPC),    MT(MOD_RCTL,KC_ENT), MEH_T(KC_SPC), KC_NO
                                      //`--------------------------'  `--------------------------'
    ),

    [1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                        KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_TAB, LGUI(KC_UP), LALT(KC_LEFT), LGUI(KC_LEFT), LGUI(KC_RIGHT), LALT(KC_RIGHT),   KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_RALT, KC_RCTL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRANSPARENT, LGUI(KC_DOWN), LGUI(KC_C), MT(MOD_LALT,KC_LBRC), KC_LGUI, KC_LBRC,   KC_PGUP, KC_PGDN, KC_HOME, KC_END, KC_RGUI, KC_RSFT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_NO, TO(2), KC_TRANSPARENT,    KC_TRANSPARENT, TO(0), KC_NO
                                      //`--------------------------'  `--------------------------'
    ),

    [2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TRANSPARENT, KC_PAUSE, KC_MPRV, KC_MNXT, KC_UNDS, KC_TRANSPARENT,      KC_TRANSPARENT, KC_VOLD, KC_VOLU, KC_MINS, KC_EQUAL, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRANSPARENT, KC_1, KC_2, KC_3, KC_4, KC_5,                             KC_6, KC_7, KC_8, KC_9, KC_0, KC_ENT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      TO(3), KC_PLUS, KC_MINS, KC_ASTR, KC_SLASH, KC_TRANSPARENT,               KC_TRANSPARENT, KC_EXLM, KC_AT, KC_DOT, KC_COMMA, KC_TRANSPARENT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_NO, KC_LGUI, KC_TRANSPARENT,    KC_TRANSPARENT, TO(0), KC_NO
                                      //`--------------------------'  `--------------------------'
    ),

    [3] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC, LGUI(KC_LBRC), LCTL(LSFT(KC_TAB)), LCTL(KC_TAB), LGUI(KC_RBRC), KC_TRANSPARENT,   KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_TRANSPARENT, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TAB, KC_HOME, KC_PGDN, LGUI(KC_C), LGUI(KC_V), KC_LALT,                KC_PGUP, KC_PGDN, KC_HOME, KC_END, KC_TRANSPARENT, KC_ENT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_GRAVE, KC_TRANSPARENT, LGUI(KC_X), KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,   KC_TRANSPARENT, KC_VOLD, KC_VOLU, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_NO, KC_LGUI, KC_TRANSPARENT,    KC_TRANSPARENT, TO(0), KC_NO
                                      //`--------------------------'  `--------------------------'
    )
};