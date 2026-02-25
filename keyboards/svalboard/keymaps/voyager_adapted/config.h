#pragma once

// Required by svalboard.h for layer_colors array sizing (replaces VIA_ENABLE)
#define DYNAMIC_KEYMAP_LAYER_COUNT 16

// Tapping config - mirrors Piantor Pro voyager_adapted settings
#define FLOW_TAP_TERM 200   // Disables holds when next key pressed within 200ms
#define CHORDAL_HOLD        // Opposite hands rule for home row mods
                            // Note: chordal_hold_layout is defined in svalboard.c
#undef TAPPING_TERM
#define TAPPING_TERM 350    // Hold activation threshold (higher for Svalboard deliberate motions)
#define QUICK_TAP_TERM 120  // Force tap if same key pressed within 120ms

// Remove PERMISSIVE_HOLD - board sets it, but it causes false hold triggers during fast typing
#undef PERMISSIVE_HOLD

// Debounce
#undef DEBOUNCE
#define DEBOUNCE 30

// Mouse key settings
#undef MOUSEKEY_DELAY
#define MOUSEKEY_DELAY 10
#undef MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL 20
#undef MOUSEKEY_MOVE_DELTA
#define MOUSEKEY_MOVE_DELTA 4
#undef MOUSEKEY_MAX_SPEED
#define MOUSEKEY_MAX_SPEED 10
#undef MOUSEKEY_TIME_TO_MAX
#define MOUSEKEY_TIME_TO_MAX 40
#undef MOUSEKEY_WHEEL_DELAY
#define MOUSEKEY_WHEEL_DELAY 10
#undef MOUSEKEY_WHEEL_INTERVAL
#define MOUSEKEY_WHEEL_INTERVAL 80
#undef MOUSEKEY_WHEEL_MAX_SPEED
#define MOUSEKEY_WHEEL_MAX_SPEED 12
#undef MOUSEKEY_WHEEL_TIME_TO_MAX
#define MOUSEKEY_WHEEL_TIME_TO_MAX 60
