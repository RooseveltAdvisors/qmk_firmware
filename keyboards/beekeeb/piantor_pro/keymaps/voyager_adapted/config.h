// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

// Voyager-adapted tapping configuration
#define FLOW_TAP_TERM 100
#define CHORDAL_HOLD
#undef TAPPING_TERM
#define TAPPING_TERM 280

// Debounce configuration from Voyager
#undef DEBOUNCE
#define DEBOUNCE 30

// Mouse configuration from Voyager
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