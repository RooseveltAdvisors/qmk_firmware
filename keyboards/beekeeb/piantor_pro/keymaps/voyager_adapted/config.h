// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

// Voyager-adapted tapping configuration
// Optimized for 20gf light switches and fast typing
#define FLOW_TAP_TERM 150  // Increased from 100ms - disables holds during fast typing (community recommended: 150ms)
#define CHORDAL_HOLD       // Opposite hands rule for home row mods
#undef TAPPING_TERM
#define TAPPING_TERM 220   // Reduced from 280ms - optimal range with CHORDAL_HOLD (community recommended: 200-250ms)

// Debounce configuration from Voyager
#undef DEBOUNCE
#define DEBOUNCE 30

// Mouse configuration from Voyager with proper acceleration curve
// Mouse movement settings - slower initial movement for precision
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

// Mouse wheel settings
#undef MOUSEKEY_WHEEL_DELAY
#define MOUSEKEY_WHEEL_DELAY 10

#undef MOUSEKEY_WHEEL_INTERVAL
#define MOUSEKEY_WHEEL_INTERVAL 80

#undef MOUSEKEY_WHEEL_MAX_SPEED
#define MOUSEKEY_WHEEL_MAX_SPEED 12

#undef MOUSEKEY_WHEEL_TIME_TO_MAX
#define MOUSEKEY_WHEEL_TIME_TO_MAX 60

// Enable mod-tap functionality
#define PERMISSIVE_HOLD