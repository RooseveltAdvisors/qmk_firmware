# QMK Tap-Hold Configuration Fix for Light Switches

## Problem Summary

**Issue**: Tap-hold keys (home row mods, layer-tap keys) were miss-triggering during fast typing on Piantor Pro with 20gf light switches.

**Symptoms**:
- Intended taps incorrectly activated hold functions (modifiers/layers)
- Occurred during fast typing and home row rolls
- Affected both home row mods and other dual-function keys

## Root Cause Analysis

### Primary Issue: Missing Chordal Hold Implementation
**Finding**: `CHORDAL_HOLD` was defined in config.h but **not implemented**
- Configuration had `#define CHORDAL_HOLD` (line 8)
- Missing `chordal_hold_layout` handedness matrix in keymap.c
- **Without the matrix, Chordal Hold doesn't actually work**
- This was the critical missing piece preventing proper tap-hold behavior

### Secondary Issues: Suboptimal Timing Parameters

1. **FLOW_TAP_TERM too short (100ms)**
   - Community recommends 150ms as starting point
   - 20gf switches have instant actuation → keys pressed very close together
   - 100ms window too tight for fast typing with light switches

2. **TAPPING_TERM slightly high (280ms)**
   - Community recommends 200-250ms when using Chordal Hold
   - Larger window = more opportunity for tap/hold confusion
   - With light switches, taps complete much faster than 280ms

3. **PERMISSIVE_HOLD behavior**
   - Actually CORRECT to have enabled with Chordal Hold
   - Initial analysis was wrong - community best practice is to keep it
   - Works together with Chordal Hold for optimal behavior

## Community Best Practices Research (2024-2025)

### Recommended Configuration for Home Row Mods + Fast Typing

Based on QMK documentation, ZSA blog, and Pascal Getreuer's research:

```c
✅ CHORDAL_HOLD enabled with handedness matrix (critical!)
✅ PERMISSIVE_HOLD enabled (works with Chordal Hold)
✅ FLOW_TAP_TERM 150-200ms (disables holds during fast typing)
✅ TAPPING_TERM 200-250ms (higher works better with Chordal Hold)
✅ NO HOLD_ON_OTHER_KEY_PRESS (causes too many misfires)
```

### Key Insights

1. **Chordal Hold** (released 2024-2025)
   - Successor to Achordion
   - Built into QMK core
   - Implements "opposite hands" rule
   - Prevents accidental modifiers during same-hand rolls
   - **Requires handedness matrix to function**

2. **Flow Tap** (released May 2025)
   - Disables hold behavior during fast typing
   - Creates a "flow of taps" window
   - Particularly useful for home row mods
   - Reduces input lag during fast typing

3. **Timing with Light Switches**
   - 20gf switches = instant actuation
   - Need larger FLOW_TAP_TERM window (150ms+)
   - Can use slightly lower TAPPING_TERM (220ms vs 280ms)
   - High debounce (30ms) correct for preventing chatter

## Solution Implemented

### Changes to `keyboards/beekeeb/piantor_pro/keymaps/voyager_adapted/config.h`

```c
// Before:
#define FLOW_TAP_TERM 100
#define TAPPING_TERM 280

// After:
#define FLOW_TAP_TERM 150  // Increased by 50ms for light switches
#define TAPPING_TERM 220   // Reduced by 60ms, optimal with Chordal Hold
```

### Changes to `keyboards/beekeeb/piantor_pro/keymaps/voyager_adapted/keymap.c`

**Added Chordal Hold handedness matrix** (critical missing piece):

```c
const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM = LAYOUT_split_3x6_3(
//  Left hand                                                Right hand
    'L', 'L', 'L', 'L', 'L', 'L',                          'R', 'R', 'R', 'R', 'R', 'R',
    'L', 'L', 'L', 'L', 'L', 'L',                          'R', 'R', 'R', 'R', 'R', 'R',
    'L', 'L', 'L', 'L', 'L', 'L',                          'R', 'R', 'R', 'R', 'R', 'R',
                   'L', 'L', 'L',                          'R', 'R', 'R'
);
```

## How This Fixes the Issue

### Before (What was broken):
1. ❌ CHORDAL_HOLD defined but not implemented (no handedness matrix)
2. ⚠️ FLOW_TAP_TERM 100ms too short → holds triggered during fast typing
3. ⚠️ TAPPING_TERM 280ms too long → larger window for confusion

### After (What's fixed):
1. ✅ **Chordal Hold now actually works** - Prevents accidental modifiers during same-hand rolls
2. ✅ **Flow Tap has bigger window** (150ms) - Handles fast typing with light switches
3. ✅ **Tapping Term optimized** (220ms) - Sweet spot for Chordal Hold + light switches

### How Each Feature Helps

**Chordal Hold**:
- Same-hand rolls (like "as", "we", "re") → tap behavior
- Opposite-hand combinations → can use PERMISSIVE_HOLD for instant holds
- Prevents accidental modifier activation during natural typing patterns

**Flow Tap**:
- Keys pressed within 150ms of previous key → forced to tap
- Disables hold behavior during typing "flow"
- Reduces input lag for fast typists

**Optimized TAPPING_TERM**:
- 220ms window matches typing speed with light switches
- Works with Chordal Hold's recommended 200-250ms range
- Shorter than 280ms = less opportunity for confusion

## Testing Results

**User Feedback**: "Okay, this worked beautifully. Good job."

**Expected Improvements** (all confirmed):
- ✅ Fewer accidental modifiers during fast typing
- ✅ Better tap detection during rolls
- ✅ More consistent home row mod behavior
- ✅ Reduced "miss triggers" with 20gf light switches

## Fine-Tuning Options (if needed)

If issues persist after implementation:

### Too many false holds:
- Increase FLOW_TAP_TERM to 180ms
- Decrease TAPPING_TERM to 200ms

### Holds don't register easily:
- Decrease FLOW_TAP_TERM to 120-130ms
- Increase TAPPING_TERM to 250ms

### Specific keys problematic:
Add per-key timing with `get_tapping_term()`:

```c
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MT(MOD_LALT, KC_D):  // Home row mods
        case MT(MOD_LGUI, KC_F):
        case MT(MOD_RGUI, KC_J):
        case MT(MOD_RALT, KC_K):
            return 150;  // Shorter for frequently used keys
        default:
            return TAPPING_TERM;
    }
}
```

## Key Learnings

1. **Always verify feature implementation**
   - Having `#define FEATURE` is not enough
   - Some features require additional code (like handedness matrix)
   - Check QMK documentation for complete implementation requirements

2. **Community research is valuable**
   - QMK community has extensive research on tap-hold timing
   - Pascal Getreuer's work (Achordion, Chordal Hold, Flow Tap) is authoritative
   - ZSA blog has practical implementation guidance

3. **Light switches need special consideration**
   - 20gf actuation = instant key presses
   - Need larger timing windows for "flow" detection
   - Higher debounce (30ms) prevents chatter
   - Timing parameters must account for faster key presses

4. **Modern QMK features are sophisticated**
   - Chordal Hold (2024-2025) is major improvement over old methods
   - Flow Tap (May 2025) specifically addresses fast typing issues
   - Using latest features provides best experience

## References

- QMK Tap-Hold Configuration: https://docs.qmk.fm/tap_hold
- Chordal Hold Introduction: https://blog.zsa.io/chordal-hold/
- Pascal Getreuer's Achordion: https://getreuer.info/posts/keyboards/achordion/
- Pascal Getreuer's Tap Flow: https://getreuer.info/posts/keyboards/tap-flow/
- Home Row Mods Guide: https://precondition.github.io/home-row-mods

## Configuration Summary

**Keyboard**: Piantor Pro (beekeeb/piantor_pro)
**Keymap**: voyager_adapted
**Switch Type**: 20gf light switches (Kailh Choc low-profile)
**Modified Files**:
- `keyboards/beekeeb/piantor_pro/keymaps/voyager_adapted/config.h`
- `keyboards/beekeeb/piantor_pro/keymaps/voyager_adapted/keymap.c`

**Scope**: Changes affect ONLY the voyager_adapted keymap, not other keymaps or keyboards.

**Date**: 2025-10-04
**Status**: ✅ Successfully implemented and tested
