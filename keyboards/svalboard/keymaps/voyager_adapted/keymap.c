#include QMK_KEYBOARD_H
#include "svalboard.h"

// Custom dual-function keys - same behavior as Piantor Pro voyager_adapted
// LT(0, key) enables tap/hold detection; process_record_user defines actual behavior
#define DUAL_FUNC_C    LT(0, KC_F20)    // C tap / Ctrl+C hold
#define DUAL_FUNC_V    LT(0, KC_F21)    // V tap / Ctrl+A hold
#define DUAL_FUNC_QUOT LT(0, KC_F22)    // ' tap / " hold
#define DUAL_FUNC_AT   LT(0, KC_F23)    // @ tap / # hold

// Dual-function keys matching Piantor Pro voyager_adapted
// LT(1, KC_xxx) - layer never activates (process_record_user returns false for all)
#define DUAL_FUNC_A     LT(1, KC_A)      // A tap / Alt+Tab hold
#define DUAL_FUNC_S     LT(1, KC_S)      // S tap / Cmd+Tab hold
#define DUAL_FUNC_L     LT(1, KC_L)      // L tap / % hold
#define DUAL_FUNC_SCLN  LT(1, KC_SCLN)   // ; tap / : hold
#define DUAL_FUNC_B     LT(1, KC_B)      // B tap / & hold
#define DUAL_FUNC_N     LT(1, KC_N)      // N tap / ( hold
#define DUAL_FUNC_M     LT(1, KC_M)      // M tap / ) hold
#define DUAL_FUNC_X     LT(1, KC_X)      // X tap / Ctrl+Tab hold
#define DUAL_FUNC_DOT   LT(1, KC_DOT)    // . tap / ` hold
#define DUAL_FUNC_Z     LT(1, KC_Z)      // Z tap / Cmd+` hold
#define DUAL_FUNC_SLSH  LT(1, KC_SLASH)  // / tap / \ hold
#define DUAL_FUNC_Q     LT(1, KC_Q)      // Q tap / PgDn hold
#define DUAL_FUNC_W     LT(1, KC_W)      // W tap / PgUp hold
#define DUAL_FUNC_E     LT(1, KC_E)      // E tap / Cmd+Left hold
#define DUAL_FUNC_R     LT(1, KC_R)      // R tap / Cmd+Right hold
#define DUAL_FUNC_T     LT(1, KC_T)      // T tap / Cmd+T hold
#define DUAL_FUNC_G     LT(1, KC_G)      // G tap / Alt+Left hold
#define DUAL_FUNC_H     LT(1, KC_H)      // H tap / Alt+Right hold
#define DUAL_FUNC_Y     LT(1, KC_Y)      // Y tap / 0 hold
#define DUAL_FUNC_U     LT(1, KC_U)      // U tap / ^ hold
#define DUAL_FUNC_I     LT(1, KC_I)      // I tap / $ hold
#define DUAL_FUNC_O     LT(1, KC_O)      // O tap / [ hold
#define DUAL_FUNC_P     LT(1, KC_P)      // P tap / ] hold
#define DUAL_FUNC_EQL   LT(1, KC_EQUAL)  // = tap / + hold
#define DUAL_FUNC_COMMA LT(1, KC_COMMA)  // , tap / - hold
#define DUAL_FUNC_ASTR  LT(0, KC_F24)    // * tap / ! hold
#define DUAL_FUNC_BTN   LT(0, KC_F14)   // left click tap / right click hold (LT thumb UpperOuter)
#define DUAL_FUNC_COPY  LT(0, KC_F13)   // Cmd+C tap / Cmd+V hold (RT thumb UpperOuter)

// ---------------------------------------------------------------------------
// LAYOUT argument order:
//   R1–R4 (right fingers, index→pinky), L1–L4 (left fingers, index→pinky),
//   RT (right thumb), LT (left thumb)
// Each finger group: Center | North | East | South | West | Double
//   Center = home row, North = top row, South = bottom row
//   East  = inner lateral (toward keyboard center)
//   West  = outer lateral (away from keyboard center)
// Each thumb group: Down | Inner/Pad | Up | UpperOuter | LowerOuter | DoubleDown
//
// chordal_hold_layout is defined in svalboard.c:
//   R1-R4 = 'R', L1-L4 = 'L', both thumb clusters = '*' (exempt)
// ---------------------------------------------------------------------------

const uint16_t PROGMEM keymaps[DYNAMIC_KEYMAP_LAYER_COUNT][MATRIX_ROWS][MATRIX_COLS] = {

    // =========================================================================
    // LAYER 0 - Alpha (QWERTY + all Piantor Pro dual-function hold behaviors)
    //
    // Left hand:
    //   L4: A(Alt+Tab)  Q(PgDn)   @(#)   Z(Cmd+`)  Hyper(Esc)
    //   L3: S(Cmd+Tab)  W(PgUp)   B(&)   X(^Tab)   Del
    //   L2: D(Alt)      E(Cmd+←)  T(⌘T)  C(^C)     `
    //   L1: F(Gui)      R(Cmd+→)  G(⌥←)  V(^A)     MEH
    //
    // Right hand:
    //   R1: J(Gui)  U(^)    =(+)   M())   H(⌥→)
    //   R2: K(Alt)  I($)    :      ,(-)   Y(0)
    //   R3: L(%)    O([)    —      .(`)   N(()
    //   R4: ;(:)    P(])    '(")   /(\)   *(!)

    //
    // Thumbs:
    //   LT: TO(1) Down | BTN1/BTN2 UpperOuter | Shift/Bspc LowerOuter
    //   RT: MEH/Spc Down | CmdC/CmdV UpperOuter | Ctrl/Enter LowerOuter
    // =========================================================================
    [0] = LAYOUT(
        /*          Center                North           East               South            West                Double */
        /*R1*/      MT(MOD_RGUI,KC_J),    DUAL_FUNC_U,    DUAL_FUNC_EQL,     DUAL_FUNC_M,     DUAL_FUNC_H,        KC_NO,
        /*R2*/      MT(MOD_RALT,KC_K),    DUAL_FUNC_I,    KC_COLN,           DUAL_FUNC_COMMA, DUAL_FUNC_Y,        KC_NO,
        /*R3*/      DUAL_FUNC_L,          DUAL_FUNC_O,    KC_NO,             DUAL_FUNC_DOT,   DUAL_FUNC_N,        KC_NO,
        /*R4*/      DUAL_FUNC_SCLN,       DUAL_FUNC_P,    DUAL_FUNC_QUOT,    DUAL_FUNC_SLSH,  DUAL_FUNC_ASTR,     KC_NO,
        /*L1*/      MT(MOD_LGUI,KC_F),    DUAL_FUNC_R,    DUAL_FUNC_G,       DUAL_FUNC_V,     MEH_T(KC_TAB),      KC_NO,
        /*L2*/      MT(MOD_LALT,KC_D),    DUAL_FUNC_E,    DUAL_FUNC_T,       DUAL_FUNC_C,     KC_GRAVE,           KC_NO,
        /*L3*/      DUAL_FUNC_S,          DUAL_FUNC_W,    DUAL_FUNC_B,       DUAL_FUNC_X,     KC_DELETE,          KC_NO,
        /*L4*/      DUAL_FUNC_A,          DUAL_FUNC_Q,    DUAL_FUNC_AT,      DUAL_FUNC_Z,     ALL_T(KC_ESC),      KC_NO,
        /*          Down                    Inner/Pad   Up      UpperOuter  LowerOuter              DoubleDown */
        /*RT*/      MEH_T(KC_SPC),          KC_NO,      KC_NO,  DUAL_FUNC_COPY, MT(MOD_RCTL,KC_ENT),    KC_NO,
        /*LT*/      TO(1),                  KC_NO,      KC_NO,  DUAL_FUNC_BTN, MT(MOD_LSFT,KC_BSPC),   KC_NO
    ),

    // =========================================================================
    // LAYER 1 - Navigation / Mouse
    //
    // Right side uses compass directions intuitively:
    //   R1 arrows:  N=Up  E=Right  S=Down  W=Left
    //   R2 mouse:   N=Up  E=Right  S=Down  W=Left  C=Btn1
    //   R3 scroll:  N=Up  E=Right  S=Down  W=Left  C=Btn2
    //   R4 mods:    C=RCtrl  N=RGui  E=RShift  S=RAlt  W=Layer3
    //
    // Left side navigation commands:
    //   L1: Cmd+Right/Up/Down | Cmd+V  | Cmd+Left | Btn3
    //   L2: Alt+Left/Right    | Cmd+C  | Cmd+Tab  | Btn2
    //   L3: Ctrl+Tab variants | Cmd+X  | Alt+Tab
    //   L4: misc
    // =========================================================================
    [1] = LAYOUT(
        /*          Center          North       East        South       West        Double */
        /*R1*/      KC_TRNS,        KC_UP,      KC_RIGHT,   KC_DOWN,    KC_LEFT,    KC_NO,
        /*R2*/      MS_BTN1,        MS_UP,      MS_RGHT,    MS_DOWN,    MS_LEFT,    KC_NO,
        /*R3*/      MS_BTN2,        MS_WHLU,    MS_WHLR,    MS_WHLD,    MS_WHLL,    KC_NO,
        /*R4*/      KC_RCTL,        KC_RGUI,    KC_RSFT,    KC_RALT,    TO(3),      KC_NO,
        /*L1*/      LGUI(KC_RIGHT), LGUI(KC_UP),    LGUI(KC_V),     MS_BTN3,        LGUI(KC_LEFT),      KC_NO,
        /*L2*/      LALT(KC_LEFT),  LGUI(KC_C),     LALT(KC_RIGHT), MS_BTN2,        LGUI(KC_TAB),       KC_NO,
        /*L3*/      LCTL(LSFT(KC_TAB)), LGUI(KC_X), LCTL(KC_TAB),   KC_TRNS,        LALT(KC_TAB),       KC_NO,
        /*L4*/      KC_TRNS,        KC_TAB,         KC_LCTL,        KC_TRNS,        KC_TRNS,            KC_NO,
        /*          Down    Inner/Pad   Up      UpperOuter  LowerOuter  DoubleDown */
        /*RT*/      TO(0),  KC_NO,      KC_NO,  KC_NO,      KC_TRNS,    KC_NO,
        /*LT*/      TO(2),  KC_NO,      KC_NO,  KC_NO,      KC_TRNS,    KC_NO
    ),

    // =========================================================================
    // LAYER 2 - Numbers / Media
    //
    // Numbers at center positions (1-4 left, 6-0 right), shifted symbols north
    // Left north positions: ! @ # $    right north: ^ & * ( )
    // South positions: page nav (left), media/brightness (right)
    // =========================================================================
    [2] = LAYOUT(
        /*          Center  North           East        South       West        Double */
        /*R1*/      KC_7,   KC_VOLU,        KC_CIRC,    KC_VOLD,    KC_6,       KC_NO,
        /*R2*/      KC_8,   KC_MNXT,        KC_RBRC,    KC_MPRV,    KC_UNDS,    KC_NO,
        /*R3*/      KC_9,   KC_BRIU,        KC_BSPC,    KC_BRID,    KC_TRNS,    KC_NO,
        /*R4*/      KC_0,   KC_ENT,         KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_NO,
        /*L1*/      KC_4,   KC_DLR,         KC_5,       KC_END,     KC_PERC,    KC_NO,
        /*L2*/      KC_3,   KC_HASH,        KC_MINUS,   KC_PGDN,    KC_PLUS,    KC_NO,
        /*L3*/      KC_2,   KC_AT,          KC_DOT,     KC_PGUP,    KC_TRNS,    KC_NO,
        /*L4*/      KC_1,   KC_EXLM,        KC_EQUAL,   KC_HOME,    KC_TRNS,    KC_NO,
        /*          Down    Inner/Pad   Up      UpperOuter  LowerOuter  DoubleDown */
        /*RT*/      TO(0),  KC_NO,      KC_NO,  KC_NO,      KC_TRNS,    KC_NO,
        /*LT*/      KC_LGUI,KC_NO,      KC_NO,  KC_NO,      KC_TRNS,    KC_NO
    ),

    // =========================================================================
    // LAYER 3 - Symbols / Browser Nav
    //
    // Right: mouse cursor (R1 compass), scroll+page (R2/R3)
    // Left: browser back/forward, tab navigation, clipboard
    // =========================================================================
    [3] = LAYOUT(
        /*          Center          North       East        South       West        Double */
        /*R1*/      MS_BTN1,        MS_UP,      MS_RGHT,    MS_DOWN,    MS_LEFT,    KC_NO,
        /*R2*/      KC_PGUP,        MS_WHLU,    MS_WHLR,    MS_WHLD,    MS_WHLL,    KC_NO,
        /*R3*/      KC_HOME,        KC_PGUP,    KC_END,     KC_PGDN,    KC_TRNS,    KC_NO,
        /*R4*/      KC_ENT,         KC_TRNS,    KC_TRNS,    KC_BSPC,    KC_TRNS,    KC_NO,
        /*L1*/      LGUI(KC_RBRC),  LGUI(KC_UP),    LGUI(KC_V),     MS_BTN1,    LGUI(KC_LBRC),      KC_NO,
        /*L2*/      LCTL(KC_TAB),   LGUI(KC_C),     KC_TRNS,        MS_BTN2,    LCTL(LSFT(KC_TAB)), KC_NO,
        /*L3*/      LGUI(KC_GRAVE), LGUI(KC_X),     KC_TRNS,        KC_TRNS,    KC_ESCAPE,          KC_NO,
        /*L4*/      KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_LCTL,    KC_TRNS,            KC_NO,
        /*          Down    Inner/Pad   Up      UpperOuter  LowerOuter  DoubleDown */
        /*RT*/      TO(0),  KC_NO,      KC_NO,  KC_NO,      KC_TRNS,    KC_NO,
        /*LT*/      KC_LGUI,KC_NO,      KC_NO,  KC_NO,      KC_TRNS,    KC_NO
    ),
};

// ---------------------------------------------------------------------------
// Custom dual-function key processing
// Matches Piantor Pro voyager_adapted tap/hold behaviors exactly
// ---------------------------------------------------------------------------
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case DUAL_FUNC_C: { // C tap / Ctrl+C hold (with over-trigger protection)
            static bool c_hold_active = false;
            if (record->tap.count > 0) {
                if (record->event.pressed) {
                    register_code16(KC_C);
                } else {
                    unregister_code16(KC_C);
                }
            } else {
                if (record->event.pressed) {
                    if (!c_hold_active) {
                        register_code16(LCTL(KC_C));
                        c_hold_active = true;
                    }
                } else {
                    unregister_code16(LCTL(KC_C));
                    c_hold_active = false;
                }
            }
            return false;
        }
        case DUAL_FUNC_V: { // V tap / Ctrl+A hold (with over-trigger protection)
            static bool v_hold_active = false;
            if (record->tap.count > 0) {
                if (record->event.pressed) {
                    register_code16(KC_V);
                } else {
                    unregister_code16(KC_V);
                }
            } else {
                if (record->event.pressed) {
                    if (!v_hold_active) {
                        register_code16(LCTL(KC_A));
                        v_hold_active = true;
                    }
                } else {
                    unregister_code16(LCTL(KC_A));
                    v_hold_active = false;
                }
            }
            return false;
        }
        case DUAL_FUNC_QUOT: // ' tap / " hold
            if (record->tap.count > 0) {
                if (record->event.pressed) { register_code16(KC_QUOTE); }
                else { unregister_code16(KC_QUOTE); }
            } else {
                if (record->event.pressed) { register_code16(KC_DQUO); }
                else { unregister_code16(KC_DQUO); }
            }
            return false;
        case DUAL_FUNC_AT: // @ tap / # hold
            if (record->tap.count > 0) {
                if (record->event.pressed) { register_code16(KC_AT); }
                else { unregister_code16(KC_AT); }
            } else {
                if (record->event.pressed) { register_code16(KC_HASH); }
                else { unregister_code16(KC_HASH); }
            }
            return false;
        case DUAL_FUNC_A: // A tap / Alt+Tab hold
            if (record->tap.count > 0) {
                if (record->event.pressed) { register_code16(KC_A); }
                else { unregister_code16(KC_A); }
            } else {
                if (record->event.pressed) { register_code16(LALT(KC_TAB)); }
                else { unregister_code16(LALT(KC_TAB)); }
            }
            return false;
        case DUAL_FUNC_S: // S tap / Cmd+Tab hold
            if (record->tap.count > 0) {
                if (record->event.pressed) { register_code16(KC_S); }
                else { unregister_code16(KC_S); }
            } else {
                if (record->event.pressed) { register_code16(LGUI(KC_TAB)); }
                else { unregister_code16(LGUI(KC_TAB)); }
            }
            return false;
        case DUAL_FUNC_L: // L tap / % hold
            if (record->tap.count > 0) {
                if (record->event.pressed) { register_code16(KC_L); }
                else { unregister_code16(KC_L); }
            } else {
                if (record->event.pressed) { register_code16(KC_PERC); }
                else { unregister_code16(KC_PERC); }
            }
            return false;
        case DUAL_FUNC_SCLN: // ; tap / : hold
            if (record->tap.count > 0) {
                if (record->event.pressed) { register_code16(KC_SCLN); }
                else { unregister_code16(KC_SCLN); }
            } else {
                if (record->event.pressed) { register_code16(KC_COLN); }
                else { unregister_code16(KC_COLN); }
            }
            return false;
        case DUAL_FUNC_B: // B tap / & hold
            if (record->tap.count > 0) {
                if (record->event.pressed) { register_code16(KC_B); }
                else { unregister_code16(KC_B); }
            } else {
                if (record->event.pressed) { register_code16(KC_AMPR); }
                else { unregister_code16(KC_AMPR); }
            }
            return false;
        case DUAL_FUNC_N: // N tap / ( hold
            if (record->tap.count > 0) {
                if (record->event.pressed) { register_code16(KC_N); }
                else { unregister_code16(KC_N); }
            } else {
                if (record->event.pressed) { register_code16(KC_LPRN); }
                else { unregister_code16(KC_LPRN); }
            }
            return false;
        case DUAL_FUNC_M: // M tap / ) hold
            if (record->tap.count > 0) {
                if (record->event.pressed) { register_code16(KC_M); }
                else { unregister_code16(KC_M); }
            } else {
                if (record->event.pressed) { register_code16(KC_RPRN); }
                else { unregister_code16(KC_RPRN); }
            }
            return false;
        case DUAL_FUNC_X: // X tap / Ctrl+Tab hold
            if (record->tap.count > 0) {
                if (record->event.pressed) { register_code16(KC_X); }
                else { unregister_code16(KC_X); }
            } else {
                if (record->event.pressed) { register_code16(LCTL(KC_TAB)); }
                else { unregister_code16(LCTL(KC_TAB)); }
            }
            return false;
        case DUAL_FUNC_DOT: // . tap / ` hold
            if (record->tap.count > 0) {
                if (record->event.pressed) { register_code16(KC_DOT); }
                else { unregister_code16(KC_DOT); }
            } else {
                if (record->event.pressed) { register_code16(KC_GRAVE); }
                else { unregister_code16(KC_GRAVE); }
            }
            return false;
        case DUAL_FUNC_Z: // Z tap / Cmd+` hold
            if (record->tap.count > 0) {
                if (record->event.pressed) { register_code16(KC_Z); }
                else { unregister_code16(KC_Z); }
            } else {
                if (record->event.pressed) { register_code16(LGUI(KC_GRAVE)); }
                else { unregister_code16(LGUI(KC_GRAVE)); }
            }
            return false;
        case DUAL_FUNC_SLSH: // / tap / \ hold
            if (record->tap.count > 0) {
                if (record->event.pressed) { register_code16(KC_SLASH); }
                else { unregister_code16(KC_SLASH); }
            } else {
                if (record->event.pressed) { register_code16(KC_BSLS); }
                else { unregister_code16(KC_BSLS); }
            }
            return false;
        case DUAL_FUNC_Q: // Q tap / PgDn hold
            if (record->tap.count > 0) {
                if (record->event.pressed) { register_code16(KC_Q); }
                else { unregister_code16(KC_Q); }
            } else {
                if (record->event.pressed) { register_code16(KC_PGDN); }
                else { unregister_code16(KC_PGDN); }
            }
            return false;
        case DUAL_FUNC_W: // W tap / PgUp hold
            if (record->tap.count > 0) {
                if (record->event.pressed) { register_code16(KC_W); }
                else { unregister_code16(KC_W); }
            } else {
                if (record->event.pressed) { register_code16(KC_PAGE_UP); }
                else { unregister_code16(KC_PAGE_UP); }
            }
            return false;
        case DUAL_FUNC_E: // E tap / Cmd+Left hold
            if (record->tap.count > 0) {
                if (record->event.pressed) { register_code16(KC_E); }
                else { unregister_code16(KC_E); }
            } else {
                if (record->event.pressed) { register_code16(LGUI(KC_LEFT)); }
                else { unregister_code16(LGUI(KC_LEFT)); }
            }
            return false;
        case DUAL_FUNC_R: // R tap / Cmd+Right hold
            if (record->tap.count > 0) {
                if (record->event.pressed) { register_code16(KC_R); }
                else { unregister_code16(KC_R); }
            } else {
                if (record->event.pressed) { register_code16(LGUI(KC_RIGHT)); }
                else { unregister_code16(LGUI(KC_RIGHT)); }
            }
            return false;
        case DUAL_FUNC_T: // T tap / Cmd+T hold
            if (record->tap.count > 0) {
                if (record->event.pressed) { register_code16(KC_T); }
                else { unregister_code16(KC_T); }
            } else {
                if (record->event.pressed) { register_code16(LGUI(KC_T)); }
                else { unregister_code16(LGUI(KC_T)); }
            }
            return false;
        case DUAL_FUNC_G: // G tap / Alt+Left hold
            if (record->tap.count > 0) {
                if (record->event.pressed) { register_code16(KC_G); }
                else { unregister_code16(KC_G); }
            } else {
                if (record->event.pressed) { register_code16(LALT(KC_LEFT)); }
                else { unregister_code16(LALT(KC_LEFT)); }
            }
            return false;
        case DUAL_FUNC_H: // H tap / Alt+Right hold
            if (record->tap.count > 0) {
                if (record->event.pressed) { register_code16(KC_H); }
                else { unregister_code16(KC_H); }
            } else {
                if (record->event.pressed) { register_code16(RALT(KC_RIGHT)); }
                else { unregister_code16(RALT(KC_RIGHT)); }
            }
            return false;
        case DUAL_FUNC_Y: // Y tap / 0 hold
            if (record->tap.count > 0) {
                if (record->event.pressed) { register_code16(KC_Y); }
                else { unregister_code16(KC_Y); }
            } else {
                if (record->event.pressed) { register_code16(KC_0); }
                else { unregister_code16(KC_0); }
            }
            return false;
        case DUAL_FUNC_U: // U tap / ^ hold
            if (record->tap.count > 0) {
                if (record->event.pressed) { register_code16(KC_U); }
                else { unregister_code16(KC_U); }
            } else {
                if (record->event.pressed) { register_code16(KC_CIRC); }
                else { unregister_code16(KC_CIRC); }
            }
            return false;
        case DUAL_FUNC_I: // I tap / $ hold
            if (record->tap.count > 0) {
                if (record->event.pressed) { register_code16(KC_I); }
                else { unregister_code16(KC_I); }
            } else {
                if (record->event.pressed) { register_code16(KC_DLR); }
                else { unregister_code16(KC_DLR); }
            }
            return false;
        case DUAL_FUNC_O: // O tap / [ hold
            if (record->tap.count > 0) {
                if (record->event.pressed) { register_code16(KC_O); }
                else { unregister_code16(KC_O); }
            } else {
                if (record->event.pressed) { register_code16(KC_LBRC); }
                else { unregister_code16(KC_LBRC); }
            }
            return false;
        case DUAL_FUNC_P: // P tap / ] hold
            if (record->tap.count > 0) {
                if (record->event.pressed) { register_code16(KC_P); }
                else { unregister_code16(KC_P); }
            } else {
                if (record->event.pressed) { register_code16(KC_RBRC); }
                else { unregister_code16(KC_RBRC); }
            }
            return false;
        case DUAL_FUNC_EQL: // = tap / + hold
            if (record->tap.count > 0) {
                if (record->event.pressed) { register_code16(KC_EQUAL); }
                else { unregister_code16(KC_EQUAL); }
            } else {
                if (record->event.pressed) { register_code16(KC_PLUS); }
                else { unregister_code16(KC_PLUS); }
            }
            return false;
        case DUAL_FUNC_COMMA: // , tap / - hold
            if (record->tap.count > 0) {
                if (record->event.pressed) { register_code16(KC_COMMA); }
                else { unregister_code16(KC_COMMA); }
            } else {
                if (record->event.pressed) { register_code16(KC_MINUS); }
                else { unregister_code16(KC_MINUS); }
            }
            return false;
        case DUAL_FUNC_ASTR: // * tap / ! hold
            if (record->tap.count > 0) {
                if (record->event.pressed) { register_code16(KC_ASTR); }
                else { unregister_code16(KC_ASTR); }
            } else {
                if (record->event.pressed) { register_code16(KC_EXLM); }
                else { unregister_code16(KC_EXLM); }
            }
            return false;
        case DUAL_FUNC_COPY: // Cmd+C tap / Cmd+V hold
            if (record->tap.count > 0) {
                if (record->event.pressed) { register_code16(LGUI(KC_C)); }
                else { unregister_code16(LGUI(KC_C)); }
            } else {
                if (record->event.pressed) { register_code16(LGUI(KC_V)); }
                else { unregister_code16(LGUI(KC_V)); }
            }
            return false;
        case DUAL_FUNC_BTN: // left click tap / right click hold
            if (record->tap.count > 0) {
                if (record->event.pressed) { register_code16(MS_BTN1); }
                else { unregister_code16(MS_BTN1); }
            } else {
                if (record->event.pressed) { register_code16(MS_BTN2); }
                else { unregister_code16(MS_BTN2); }
            }
            return false;
    }
    return true;
}

// ---------------------------------------------------------------------------
// CHORDAL_HOLD override: prevent letter dual-function keys from triggering
// hold when followed by an opposite-hand key during fast typing (e.g., "bu",
// "by", "no"). Without this, B(left) + U(right) within tapping window resolves
// as & instead of B. Holds are still accessible via TAPPING_TERM alone.
// ---------------------------------------------------------------------------
bool get_chordal_hold(uint16_t tap_hold_keycode, keyrecord_t *tap_hold_record, uint16_t other_keycode, keyrecord_t *other_record) {
    switch (tap_hold_keycode) {
        case DUAL_FUNC_A: case DUAL_FUNC_S: case DUAL_FUNC_L: case DUAL_FUNC_SCLN:
        case DUAL_FUNC_B: case DUAL_FUNC_N: case DUAL_FUNC_M: case DUAL_FUNC_X:
        case DUAL_FUNC_DOT: case DUAL_FUNC_Z: case DUAL_FUNC_SLSH:
        case DUAL_FUNC_Q: case DUAL_FUNC_W: case DUAL_FUNC_E: case DUAL_FUNC_R:
        case DUAL_FUNC_T: case DUAL_FUNC_G: case DUAL_FUNC_H: case DUAL_FUNC_Y:
        case DUAL_FUNC_U: case DUAL_FUNC_I: case DUAL_FUNC_O: case DUAL_FUNC_P:
        case DUAL_FUNC_EQL: case DUAL_FUNC_COMMA:
            return false;  // never chord-hold; use TAPPING_TERM for deliberate holds
    }
    return get_chordal_hold_default(tap_hold_record, other_record);
}

// ---------------------------------------------------------------------------
// Exclude MEH_T and ALL_T keys from Flow Tap so they work as quick modifiers.
// Without this, pressing MEH_T(KC_SPC) within 150ms of a previous alpha key
// would force a tap (output space) instead of activating MEH.
// ---------------------------------------------------------------------------
bool is_flow_tap_key(uint16_t keycode) {
    switch (keycode) {
        case MEH_T(KC_SPC):   // RT Inner/Pad
        case MEH_T(KC_TAB):   // L1 West
        case ALL_T(KC_ESC):   // L4 West
            return false;
    }
    switch (get_tap_keycode(keycode)) {
        case KC_SPC:
        case KC_A ... KC_Z:
        case KC_DOT:
        case KC_COMM:
        case KC_SCLN:
        case KC_SLSH:
            return true;
    }
    return false;
}
