#include QMK_KEYBOARD_H

// Dual function key definitions adapted from ZSA Voyager jon_custom
// Note: Voyager uses layers 1-15, adapting to Piantor Pro's 0-3 layers
// Layer 0 keys - adapting complex Voyager layer assignments to 4-layer system
#define DUAL_FUNC_0 LT(3, KC_Q)    // Q / Layer 3 (was LT(13, KC_F10))
#define DUAL_FUNC_1 LT(2, KC_W)    // W / Layer 2 (was LT(5, KC_W))
#define DUAL_FUNC_2 LT(3, KC_E)    // E / Layer 3 (was LT(15, KC_F20))
#define DUAL_FUNC_3 LT(1, KC_R)    // R / Layer 1 (was LT(10, KC_F5))
#define DUAL_FUNC_4 LT(3, KC_T)    // T / Layer 3 (was LT(3, KC_F4))
#define DUAL_FUNC_5 LT(1, KC_A)    // A / Layer 1 (was LT(1, KC_F15))
#define DUAL_FUNC_6 LT(2, KC_S)    // S / Layer 2 (was LT(9, KC_7))
#define DUAL_FUNC_7 LT(3, KC_G)    // G / Layer 3 (was LT(14, KC_F10))
#define DUAL_FUNC_8 LT(3, KC_Z)    // Z / Layer 3 (was LT(15, KC_L))
#define DUAL_FUNC_9 LT(2, KC_X)    // X / Layer 2 (was LT(7, KC_2))
#define DUAL_FUNC_10 LT(2, KC_C)   // C / Layer 2 (was LT(8, KC_G))
#define DUAL_FUNC_11 LT(1, KC_B)   // B / Layer 1 (was LT(10, KC_0))
#define DUAL_FUNC_12 LT(2, KC_Y)   // Y / Layer 2 (was LT(7, KC_F5))
#define DUAL_FUNC_13 LT(3, KC_U)   // U / Layer 3 (was LT(13, KC_1))
#define DUAL_FUNC_14 LT(2, KC_I)   // I / Layer 2 (was LT(5, KC_6))
#define DUAL_FUNC_15 LT(3, KC_O)   // O / Layer 3 (was LT(3, KC_U))
#define DUAL_FUNC_16 LT(2, KC_P)   // P / Layer 2 (was LT(9, KC_F2))
#define DUAL_FUNC_17 LT(2, KC_EQUAL) // = / Layer 2 (was LT(2, KC_F8))
#define DUAL_FUNC_18 LT(3, KC_H)   // H / Layer 3 (was LT(12, KC_U))
#define DUAL_FUNC_19 LT(3, KC_L)   // L / Layer 3 (was LT(12, KC_B))
#define DUAL_FUNC_20 LT(2, KC_SCLN) // ; / Layer 2 (was LT(5, KC_O))
#define DUAL_FUNC_21 LT(2, KC_N)   // N / Layer 2 (was LT(2, KC_F5))
#define DUAL_FUNC_22 LT(2, KC_M)   // M / Layer 2 (was LT(8, KC_M))
#define DUAL_FUNC_23 LT(1, KC_COMMA) // , / Layer 1 (was LT(10, KC_F6))
#define DUAL_FUNC_24 LT(2, KC_DOT) // . / Layer 2 (was LT(2, KC_F11))
#define DUAL_FUNC_25 LT(3, KC_SLASH) // / / Layer 3 (was LT(14, KC_F22))
#define DUAL_FUNC_26 LT(2, KC_BSLS) // \ / Layer 2 (was LT(8, KC_F7))

// Layer 1 additional functions (from original Voyager)
#define DUAL_FUNC_27 LT(1, LGUI(KC_UP))      // GUI+UP tap / GUI+Shift+UP hold
#define DUAL_FUNC_28 LT(1, LALT(KC_LEFT))    // Alt+Left tap / Alt+Ctrl+Left hold
#define DUAL_FUNC_29 LT(1, LGUI(KC_LEFT))    // GUI+Left tap / GUI+Shift+Left hold
#define DUAL_FUNC_30 LT(1, LGUI(KC_RIGHT))   // GUI+Right tap / GUI+Shift+Right hold
#define DUAL_FUNC_31 LT(1, LALT(KC_RIGHT))   // Alt+Right tap / Alt+Shift+Right hold
#define DUAL_FUNC_32 LT(1, LGUI(KC_DOWN))    // GUI+Down tap / GUI+Shift+Down hold
#define DUAL_FUNC_33 LT(1, KC_C)             // C / Layer 1 (tap=Cmd+C, hold=Cmd+V in process_record_user)
#define DUAL_FUNC_34 LT(1, MT(MOD_LALT,KC_LBRC)) // Alt+[ tap / Layer 1 hold
#define DUAL_FUNC_35 LT(1, MS_BTN1)          // Mouse Button 1 tap / Layer 1 hold
#define DUAL_FUNC_36 LT(1, MS_BTN2)          // Mouse Button 2 tap / Layer 1 hold

// Layer 2 additional functions
#define DUAL_FUNC_37 LT(2, KC_PAUSE)         // Pause tap / Media Play/Pause hold
#define DUAL_FUNC_38 LT(2, KC_BSPC)          // Backspace tap / GUI+Backspace hold

// Layer 3 additional functions
#define DUAL_FUNC_39 LT(3, KC_ESC)           // Escape tap / Alt+Ctrl+Escape hold
#define DUAL_FUNC_40 LT(3, KC_TAB)           // Tab tap / Ctrl+Tab hold
#define DUAL_FUNC_41 LT(3, KC_HOME)          // Home tap / End hold
#define DUAL_FUNC_42 LT(3, KC_PGDN)          // Page Down tap / Page Up hold
#define DUAL_FUNC_43 LT(3, KC_GRAVE)         // Grave tap / Ctrl+Grave hold

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       MEH_T(KC_TAB), DUAL_FUNC_0, DUAL_FUNC_1, DUAL_FUNC_2, DUAL_FUNC_3, DUAL_FUNC_4,    DUAL_FUNC_12, DUAL_FUNC_13, DUAL_FUNC_14, DUAL_FUNC_15, DUAL_FUNC_16, DUAL_FUNC_17,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
 ALL_T(KC_ESC), DUAL_FUNC_5, DUAL_FUNC_6, MT(MOD_LALT,KC_D), MT(MOD_LGUI,KC_F), DUAL_FUNC_7,    DUAL_FUNC_18, MT(MOD_RGUI,KC_J), MT(MOD_RALT,KC_K), DUAL_FUNC_19, DUAL_FUNC_20, MT(MOD_RSFT,KC_QUOTE),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      DUAL_FUNC_8, DUAL_FUNC_9, DUAL_FUNC_10, KC_C, KC_V, DUAL_FUNC_11,         DUAL_FUNC_21, DUAL_FUNC_22, DUAL_FUNC_23, DUAL_FUNC_24, DUAL_FUNC_25, DUAL_FUNC_26,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_NO, TO(1), MT(MOD_LSFT,KC_BSPC),    MT(MOD_RCTL,KC_ENT), MEH_T(KC_SPC), KC_NO
                                      //`--------------------------'  `--------------------------'
    ),

    [1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB, DUAL_FUNC_27, DUAL_FUNC_28, DUAL_FUNC_29, DUAL_FUNC_30, DUAL_FUNC_31,   KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_RALT, KC_RCTL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRANSPARENT, DUAL_FUNC_32, DUAL_FUNC_33, DUAL_FUNC_34, DUAL_FUNC_35, DUAL_FUNC_36,   MS_LEFT, MS_DOWN, MS_UP, MS_RGHT, KC_RGUI, KC_RSFT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRANSPARENT, KC_LCTL, MT(MOD_LALT,KC_LBRC), MS_BTN1, MS_BTN2, MS_BTN3,   MS_WHLL, MS_WHLD, MS_WHLU, MS_WHLR, KC_TRANSPARENT, TO(3),
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_NO, TO(2), KC_TRANSPARENT,    KC_TRANSPARENT, TO(0), KC_NO
                                      //`--------------------------'  `--------------------------'
    ),

    [2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB, DUAL_FUNC_37, KC_MPRV, KC_MNXT, KC_UNDS, KC_TRANSPARENT,      KC_TRANSPARENT, KC_VOLD, KC_VOLU, KC_MINS, KC_EQUAL, DUAL_FUNC_38,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5,                             KC_6, KC_7, KC_8, KC_9, KC_0, KC_ENT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      TO(3), KC_PLUS, KC_MINS, KC_ASTR, KC_SLASH, KC_B,               KC_N, KC_BRID, KC_BRIU, KC_DOT, KC_COMMA, KC_TRANSPARENT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_NO, KC_LGUI, KC_TRANSPARENT,    KC_TRANSPARENT, TO(0), KC_NO
                                      //`--------------------------'  `--------------------------'
    ),

    [3] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       DUAL_FUNC_39, LGUI(KC_LBRC), LCTL(LSFT(KC_TAB)), LCTL(KC_TAB), LGUI(KC_RBRC), KC_TRANSPARENT,   MS_LEFT, MS_DOWN, MS_UP, MS_RGHT, KC_TRANSPARENT, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      DUAL_FUNC_40, DUAL_FUNC_41, DUAL_FUNC_42, LGUI(KC_C), LGUI(KC_V), KC_LALT,                KC_PGUP, KC_PGDN, KC_HOME, KC_END, KC_TRANSPARENT, KC_ENT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      DUAL_FUNC_43, KC_TRANSPARENT, LGUI(KC_X), MS_BTN1, MS_BTN2, KC_TRANSPARENT,   MS_WHLL, MS_WHLD, MS_WHLU, MS_WHLR, KC_TRANSPARENT, KC_TRANSPARENT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_NO, KC_LGUI, KC_TRANSPARENT,    KC_TRANSPARENT, TO(0), KC_NO
                                      //`--------------------------'  `--------------------------'
    )
};

// Chordal Hold handedness matrix - implements "opposite hands" rule
// 'L' = left hand, 'R' = right hand, '*' = exempt from rule
// This enables Chordal Hold to prevent accidental modifiers during same-hand rolls
const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM = LAYOUT_split_3x6_3(
//  Left hand                                                Right hand
    'L', 'L', 'L', 'L', 'L', 'L',                          'R', 'R', 'R', 'R', 'R', 'R',
    'L', 'L', 'L', 'L', 'L', 'L',                          'R', 'R', 'R', 'R', 'R', 'R',
    'L', 'L', 'L', 'L', 'L', 'L',                          'R', 'R', 'R', 'R', 'R', 'R',
                   'L', 'L', 'L',                          'R', 'R', 'R'
);

// Process dual function keys with proper hold behaviors
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case DUAL_FUNC_0: // Q tap / PGDN hold
            if (record->tap.count > 0) {
                if (record->event.pressed) {
                    register_code16(KC_Q);
                } else {
                    unregister_code16(KC_Q);
                }
            } else {
                if (record->event.pressed) {
                    register_code16(KC_PGDN);
                } else {
                    unregister_code16(KC_PGDN);
                }
            }
            return false;
        case DUAL_FUNC_1: // W tap / PAGE_UP hold
            if (record->tap.count > 0) {
                if (record->event.pressed) {
                    register_code16(KC_W);
                } else {
                    unregister_code16(KC_W);
                }
            } else {
                if (record->event.pressed) {
                    register_code16(KC_PAGE_UP);
                } else {
                    unregister_code16(KC_PAGE_UP);
                }
            }
            return false;
        case DUAL_FUNC_2: // E tap / LGUI(KC_LEFT) hold
            if (record->tap.count > 0) {
                if (record->event.pressed) {
                    register_code16(KC_E);
                } else {
                    unregister_code16(KC_E);
                }
            } else {
                if (record->event.pressed) {
                    register_code16(LGUI(KC_LEFT));
                } else {
                    unregister_code16(LGUI(KC_LEFT));
                }
            }
            return false;
        case DUAL_FUNC_3: // R tap / LGUI(KC_RIGHT) hold
            if (record->tap.count > 0) {
                if (record->event.pressed) {
                    register_code16(KC_R);
                } else {
                    unregister_code16(KC_R);
                }
            } else {
                if (record->event.pressed) {
                    register_code16(LGUI(KC_RIGHT));
                } else {
                    unregister_code16(LGUI(KC_RIGHT));
                }
            }
            return false;
        case DUAL_FUNC_4: // T tap / LGUI(KC_T) hold
            if (record->tap.count > 0) {
                if (record->event.pressed) {
                    register_code16(KC_T);
                } else {
                    unregister_code16(KC_T);
                }
            } else {
                if (record->event.pressed) {
                    register_code16(LGUI(KC_T));
                } else {
                    unregister_code16(LGUI(KC_T));
                }
            }
            return false;
        case DUAL_FUNC_5: // A tap / LALT(KC_TAB) hold
            if (record->tap.count > 0) {
                if (record->event.pressed) {
                    register_code16(KC_A);
                } else {
                    unregister_code16(KC_A);
                }
            } else {
                if (record->event.pressed) {
                    register_code16(LALT(KC_TAB));
                } else {
                    unregister_code16(LALT(KC_TAB));
                }
            }
            return false;
        case DUAL_FUNC_6: // S tap / LGUI(KC_TAB) hold
            if (record->tap.count > 0) {
                if (record->event.pressed) {
                    register_code16(KC_S);
                } else {
                    unregister_code16(KC_S);
                }
            } else {
                if (record->event.pressed) {
                    register_code16(LGUI(KC_TAB));
                } else {
                    unregister_code16(LGUI(KC_TAB));
                }
            }
            return false;
        case DUAL_FUNC_7: // G tap / LALT(KC_LEFT) hold
            if (record->tap.count > 0) {
                if (record->event.pressed) {
                    register_code16(KC_G);
                } else {
                    unregister_code16(KC_G);
                }
            } else {
                if (record->event.pressed) {
                    register_code16(LALT(KC_LEFT));
                } else {
                    unregister_code16(LALT(KC_LEFT));
                }
            }
            return false;
        case DUAL_FUNC_8: // @ tap / # hold (bottom leftmost position)
            if (record->tap.count > 0) {
                if (record->event.pressed) {
                    register_code16(KC_AT);
                } else {
                    unregister_code16(KC_AT);
                }
            } else {
                if (record->event.pressed) {
                    register_code16(KC_HASH);
                } else {
                    unregister_code16(KC_HASH);
                }
            }
            return false;
        case DUAL_FUNC_9: // Z tap / LGUI(KC_GRAVE) hold (from Voyager DUAL_FUNC_9)
            if (record->tap.count > 0) {
                if (record->event.pressed) {
                    register_code16(KC_Z);
                } else {
                    unregister_code16(KC_Z);
                }
            } else {
                if (record->event.pressed) {
                    register_code16(LGUI(KC_GRAVE));
                } else {
                    unregister_code16(LGUI(KC_GRAVE));
                }
            }
            return false;
        case DUAL_FUNC_10: // X tap / LCTL(KC_TAB) hold (from Voyager DUAL_FUNC_10)
            if (record->tap.count > 0) {
                if (record->event.pressed) {
                    register_code16(KC_X);
                } else {
                    unregister_code16(KC_X);
                }
            } else {
                if (record->event.pressed) {
                    register_code16(LCTL(KC_TAB));
                } else {
                    unregister_code16(LCTL(KC_TAB));
                }
            }
            return false;
        case DUAL_FUNC_11: // B tap / KC_AMPR hold
            if (record->tap.count > 0) {
                if (record->event.pressed) {
                    register_code16(KC_B);
                } else {
                    unregister_code16(KC_B);
                }
            } else {
                if (record->event.pressed) {
                    register_code16(KC_AMPR);
                } else {
                    unregister_code16(KC_AMPR);
                }
            }
            return false;
        case DUAL_FUNC_12: // Y tap / KC_0 hold
            if (record->tap.count > 0) {
                if (record->event.pressed) {
                    register_code16(KC_Y);
                } else {
                    unregister_code16(KC_Y);
                }
            } else {
                if (record->event.pressed) {
                    register_code16(KC_0);
                } else {
                    unregister_code16(KC_0);
                }
            }
            return false;
        case DUAL_FUNC_13: // U tap / KC_CIRC hold
            if (record->tap.count > 0) {
                if (record->event.pressed) {
                    register_code16(KC_U);
                } else {
                    unregister_code16(KC_U);
                }
            } else {
                if (record->event.pressed) {
                    register_code16(KC_CIRC);
                } else {
                    unregister_code16(KC_CIRC);
                }
            }
            return false;
        case DUAL_FUNC_14: // I tap / KC_DLR hold
            if (record->tap.count > 0) {
                if (record->event.pressed) {
                    register_code16(KC_I);
                } else {
                    unregister_code16(KC_I);
                }
            } else {
                if (record->event.pressed) {
                    register_code16(KC_DLR);
                } else {
                    unregister_code16(KC_DLR);
                }
            }
            return false;
        case DUAL_FUNC_15: // O tap / KC_LBRC hold
            if (record->tap.count > 0) {
                if (record->event.pressed) {
                    register_code16(KC_O);
                } else {
                    unregister_code16(KC_O);
                }
            } else {
                if (record->event.pressed) {
                    register_code16(KC_LBRC);
                } else {
                    unregister_code16(KC_LBRC);
                }
            }
            return false;
        case DUAL_FUNC_16: // P tap / KC_RBRC hold
            if (record->tap.count > 0) {
                if (record->event.pressed) {
                    register_code16(KC_P);
                } else {
                    unregister_code16(KC_P);
                }
            } else {
                if (record->event.pressed) {
                    register_code16(KC_RBRC);
                } else {
                    unregister_code16(KC_RBRC);
                }
            }
            return false;
        case DUAL_FUNC_17: // = tap / KC_PLUS hold
            if (record->tap.count > 0) {
                if (record->event.pressed) {
                    register_code16(KC_EQUAL);
                } else {
                    unregister_code16(KC_EQUAL);
                }
            } else {
                if (record->event.pressed) {
                    register_code16(KC_PLUS);
                } else {
                    unregister_code16(KC_PLUS);
                }
            }
            return false;
        case DUAL_FUNC_18: // H tap / RALT(KC_RIGHT) hold
            if (record->tap.count > 0) {
                if (record->event.pressed) {
                    register_code16(KC_H);
                } else {
                    unregister_code16(KC_H);
                }
            } else {
                if (record->event.pressed) {
                    register_code16(RALT(KC_RIGHT));
                } else {
                    unregister_code16(RALT(KC_RIGHT));
                }
            }
            return false;
        case DUAL_FUNC_19: // L tap / KC_PERC hold
            if (record->tap.count > 0) {
                if (record->event.pressed) {
                    register_code16(KC_L);
                } else {
                    unregister_code16(KC_L);
                }
            } else {
                if (record->event.pressed) {
                    register_code16(KC_PERC);
                } else {
                    unregister_code16(KC_PERC);
                }
            }
            return false;
        case DUAL_FUNC_20: // ; tap / KC_COLN hold
            if (record->tap.count > 0) {
                if (record->event.pressed) {
                    register_code16(KC_SCLN);
                } else {
                    unregister_code16(KC_SCLN);
                }
            } else {
                if (record->event.pressed) {
                    register_code16(KC_COLN);
                } else {
                    unregister_code16(KC_COLN);
                }
            }
            return false;
        case DUAL_FUNC_21: // N tap / KC_LPRN hold
            if (record->tap.count > 0) {
                if (record->event.pressed) {
                    register_code16(KC_N);
                } else {
                    unregister_code16(KC_N);
                }
            } else {
                if (record->event.pressed) {
                    register_code16(KC_LPRN);
                } else {
                    unregister_code16(KC_LPRN);
                }
            }
            return false;
        case DUAL_FUNC_22: // M tap / KC_RPRN hold
            if (record->tap.count > 0) {
                if (record->event.pressed) {
                    register_code16(KC_M);
                } else {
                    unregister_code16(KC_M);
                }
            } else {
                if (record->event.pressed) {
                    register_code16(KC_RPRN);
                } else {
                    unregister_code16(KC_RPRN);
                }
            }
            return false;
        case DUAL_FUNC_23: // , tap / KC_MINUS hold
            if (record->tap.count > 0) {
                if (record->event.pressed) {
                    register_code16(KC_COMMA);
                } else {
                    unregister_code16(KC_COMMA);
                }
            } else {
                if (record->event.pressed) {
                    register_code16(KC_MINUS);
                } else {
                    unregister_code16(KC_MINUS);
                }
            }
            return false;
        case DUAL_FUNC_24: // . tap / KC_GRAVE hold
            if (record->tap.count > 0) {
                if (record->event.pressed) {
                    register_code16(KC_DOT);
                } else {
                    unregister_code16(KC_DOT);
                }
            } else {
                if (record->event.pressed) {
                    register_code16(KC_GRAVE);
                } else {
                    unregister_code16(KC_GRAVE);
                }
            }
            return false;
        case DUAL_FUNC_25: // / tap / KC_BSLS hold
            if (record->tap.count > 0) {
                if (record->event.pressed) {
                    register_code16(KC_SLASH);
                } else {
                    unregister_code16(KC_SLASH);
                }
            } else {
                if (record->event.pressed) {
                    register_code16(KC_BSLS);
                } else {
                    unregister_code16(KC_BSLS);
                }
            }
            return false;
        case DUAL_FUNC_26: // * tap / ! hold (from Voyager line 580+)
            if (record->tap.count > 0) {
                if (record->event.pressed) {
                    register_code16(KC_ASTR);
                } else {
                    unregister_code16(KC_ASTR);
                }
            } else {
                if (record->event.pressed) {
                    register_code16(KC_EXLM);
                } else {
                    unregister_code16(KC_EXLM);
                }
            }
            return false;
        case DUAL_FUNC_33: // C tap LGUI(KC_C) / hold LGUI(KC_V) (from Voyager DUAL_FUNC_33)
            if (record->tap.count > 0) {
                if (record->event.pressed) {
                    register_code16(LGUI(KC_C));
                } else {
                    unregister_code16(LGUI(KC_C));
                }
            } else {
                if (record->event.pressed) {
                    register_code16(LGUI(KC_V));
                } else {
                    unregister_code16(LGUI(KC_V));
                }
            }
            return false;
    }
    return true;
}