# QMK Piantor Pro - Complete Configuration Guide

## User Profile - Jon

### Typing Profile
- **Average WPM**: 74 words per minute
- **Keyboard**: Piantor Pro with 20gf light switches (Kailh Choc low-profile)
- **Typing Style**: Fast typing with quick same-hand rolls
- **Primary Use Cases**: Vim editing (Ctrl+C quit command critical)

### Hardware Setup
- **Keyboard**: Piantor Pro (beekeeb/piantor_pro)
- **Layout**: 42 keys - 3x6 split layout + 3 thumb keys per side
- **Switches**: 20gf actuation force (extremely light, instant actuation)
- **Source Layout**: Adapted from Voyager (52 keys, 4x6 layout)

## Tap-Hold Configuration History

### Evolution of Timing Parameters

#### Session 1: Initial Chordal Hold Fix (2025-10-04)
**Problem**: Missing Chordal Hold implementation caused tap-hold miss-triggers
**Solution**: 
- Added `chordal_hold_layout` handedness matrix (critical missing piece)
- Increased `FLOW_TAP_TERM`: 100ms → 150ms
- Decreased `TAPPING_TERM`: 280ms → 220ms
**Result**: ✅ "Worked beautifully" - eliminated most miss-triggers

#### Session 2: PERMISSIVE_HOLD Removal (2025-10-04)
**Problem**: Typing "CHANGE" fast at 74 WPM triggered Ctrl+C during C-H overlap
**Symptoms**: 
- Deleted whole text buffer (Ctrl+C interrupt)
- Only "ANG" remained after typing "CHANGE"
- Happened with other fast letter combinations

**Root Cause**: `PERMISSIVE_HOLD` enabled
- At 74 WPM, keys overlap frequently (~150-160ms between presses)
- `PERMISSIVE_HOLD` interprets overlapping key presses as holds
- C pressed → H pressed while C still down → Ctrl+C triggered

**Solution**:
- **Removed**: `PERMISSIVE_HOLD` (was causing fast typing issues)
- **Added**: `QUICK_TAP_TERM 120` (forces tap on rapid same-key presses)
- **Increased**: `TAPPING_TERM`: 220ms → 250ms (more conservative)

**Result**: ✅ "CHANGE" types correctly, no more Ctrl+C triggers

### Current Configuration (Optimized for 74 WPM + 20gf switches)

```c
// keyboards/beekeeb/piantor_pro/keymaps/voyager_adapted/config.h

#define FLOW_TAP_TERM 150    // Disables holds when next key within 150ms
#define CHORDAL_HOLD         // Opposite hands rule for home row mods
#define TAPPING_TERM 250     // Hold activation threshold (conservative for 74 WPM)
#define QUICK_TAP_TERM 120   // Force tap if same key within 120ms
#define DEBOUNCE 30          // Prevent chatter with light switches

// PERMISSIVE_HOLD removed - caused hold triggers during fast overlapping presses
```

```c
// keyboards/beekeeb/piantor_pro/keymaps/voyager_adapted/keymap.c

const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM = LAYOUT_split_3x6_3(
//  Left hand                                                Right hand
    'L', 'L', 'L', 'L', 'L', 'L',                          'R', 'R', 'R', 'R', 'R', 'R',
    'L', 'L', 'L', 'L', 'L', 'L',                          'R', 'R', 'R', 'R', 'R', 'R',
    'L', 'L', 'L', 'L', 'L', 'L',                          'R', 'R', 'R', 'R', 'R', 'R',
                   'L', 'L', 'L',                          'R', 'R', 'R'
);
```

## How Configuration Works at 74 WPM

### Timing Analysis
At 74 WPM average:
- ~150-160ms between key presses in normal typing
- Same-hand rolls often faster (~120-140ms)
- Light switches have instant actuation (no travel time)

### Feature Interaction

**CHORDAL_HOLD + handedness matrix**:
- Same-hand rolls (like "CH" in "CHANGE") → forced to tap
- Opposite-hand overlaps → can still trigger holds intentionally
- Prevents accidental modifiers during natural typing patterns

**FLOW_TAP_TERM 150ms**:
- Any key pressed within 150ms of previous → forced to tap
- Matches natural typing rhythm at 74 WPM
- Disables hold behavior during "flow" of fast typing

**TAPPING_TERM 250ms**:
- Must hold key alone for 250ms to trigger hold function
- Conservative value prevents overlap confusion
- Within QMK community recommended 200-250ms range

**QUICK_TAP_TERM 120ms**:
- Same key pressed twice within 120ms → both taps
- Prevents hold trigger on rapid double-taps
- Useful for repeated characters

**NO PERMISSIVE_HOLD**:
- Critical for fast typing (74 WPM)
- Prevents overlap interpretation as hold
- Would cause "CHANGE" → Ctrl+C problem if enabled

## Custom Dual-Function Keys

### Pattern: LT() Macro with Custom Handlers

All dual-function keys follow consistent pattern:

```c
// Definition
#define DUAL_FUNC_C LT(0, KC_F20)  // C tap / Ctrl+C hold
#define DUAL_FUNC_V LT(0, KC_F21)  // V tap / Ctrl+A hold
#define DUAL_FUNC_QUOT LT(0, KC_F22)  // ' tap / " hold

// In keymap
..., DUAL_FUNC_C, DUAL_FUNC_V, ..., DUAL_FUNC_QUOT, ...

// Handler with over-trigger protection
case DUAL_FUNC_C:
    {
        static bool c_hold_active = false;
        if (record->tap.count > 0) {
            // Tap: normal C
            if (record->event.pressed) {
                register_code16(KC_C);
            } else {
                unregister_code16(KC_C);
            }
        } else {
            // Hold: Ctrl+C (send only once, prevent key repeat over-trigger)
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
    }
    return false;
```

### Over-Trigger Protection Pattern

Critical for Vim usage (Ctrl+C quits):
- Static boolean tracks hold state
- `register_code16()` called only once on press
- Ignores key repeat events while hold active
- Resets on key release

**Why needed**: 
- Key repeat can send multiple Ctrl+C signals
- Multiple Ctrl+C in Vim = multiple quit attempts
- Can cause data loss or unexpected behavior

## Flash Workflow

### User's Preferred Method
```bash
# 1. Compile firmware
qmk compile -kb beekeeb/piantor_pro -km voyager_adapted

# 2. Enter bootloader mode (hardware reset)
# Press reset button on keyboard

# 3. Copy UF2 to mounted volume
cp beekeeb_piantor_pro_voyager_adapted.uf2 /Volumes/RPI-RP2/
```

**Not used**: `qmk flash` - user prefers manual bootloader + file copy workflow

## Community Best Practices (2024-2025)

### Recommended for Fast Typing + Light Switches

Based on QMK docs, ZSA blog, Pascal Getreuer research:

```c
✅ CHORDAL_HOLD with handedness matrix (critical!)
✅ FLOW_TAP_TERM 150-200ms (disable holds during fast typing)
✅ TAPPING_TERM 200-250ms (optimal with Chordal Hold)
✅ QUICK_TAP_TERM 100-150ms (force tap on rapid repeats)
✅ HIGH DEBOUNCE (30ms) for light switches
❌ NO PERMISSIVE_HOLD for fast typists (>70 WPM)
❌ NO HOLD_ON_OTHER_KEY_PRESS (causes misfires)
```

### Key QMK Features Used

**Chordal Hold** (released 2024-2025):
- Successor to Achordion
- Built into QMK core
- Implements "opposite hands" rule
- **Requires handedness matrix** - definition alone doesn't work!

**Flow Tap** (released May 2025):
- Disables holds during fast typing flow
- Reduces input lag for fast typists
- Particularly useful for home row mods

## Fine-Tuning Guide

If issues appear after user typing speed changes:

### Too many false holds during fast typing:
```c
#define FLOW_TAP_TERM 180  // Increase window
#define TAPPING_TERM 220   // Decrease threshold
```

### Holds don't register easily enough:
```c
#define FLOW_TAP_TERM 120  // Decrease window
#define TAPPING_TERM 280   // Increase threshold
```

### Specific keys problematic:
Add per-key timing with `get_tapping_term()`:
```c
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case DUAL_FUNC_C:  // Critical Vim quit key
        case DUAL_FUNC_V:  // Frequently used
            return 280;     // Higher threshold for safety
        default:
            return TAPPING_TERM;
    }
}
```

## Testing Validation

### Session 1 Results (Chordal Hold Fix)
- ✅ Home row mods work correctly
- ✅ Layer-tap keys respond properly
- ✅ Fast typing doesn't trigger accidental modifiers
- ✅ User feedback: "This worked beautifully"

### Session 2 Results (PERMISSIVE_HOLD Removal)
- ✅ "CHANGE" types correctly at speed
- ✅ No Ctrl+C triggers during fast typing
- ✅ No text buffer deletions
- ✅ Other fast combinations work properly
- ✅ All letters appear as typed

## Key Learnings

### 1. Configuration Requires Complete Implementation
- Having `#define CHORDAL_HOLD` is NOT enough
- Must add `chordal_hold_layout` handedness matrix
- QMK features often need supporting code structures

### 2. User Typing Speed Matters
- 74 WPM = ~150-160ms between keys
- Configuration must account for actual typing rhythm
- Community recommendations are starting points, not absolutes

### 3. PERMISSIVE_HOLD Trade-offs
- Good: Faster modifier activation with opposite-hand combos
- Bad: Causes false holds during same-hand fast typing
- **Critical**: Incompatible with fast typing (>70 WPM)

### 4. Light Switches Need Special Handling
- 20gf actuation = instant key presses
- Higher debounce (30ms) prevents chatter
- Larger timing windows needed (FLOW_TAP_TERM, QUICK_TAP_TERM)
- Less travel time = keys closer together temporally

### 5. Over-Trigger Protection Critical for Vim
- Ctrl+C quit command in Vim
- Multiple signals from key repeat = data loss risk
- Static boolean state tracking prevents over-triggering
- Essential pattern for critical hold functions

## References

- QMK Tap-Hold: https://docs.qmk.fm/tap_hold
- Chordal Hold: https://blog.zsa.io/chordal-hold/
- Pascal Getreuer's Achordion: https://getreuer.info/posts/keyboards/achordion/
- Pascal Getreuer's Tap Flow: https://getreuer.info/posts/keyboards/tap-flow/
- Home Row Mods Guide: https://precondition.github.io/home-row-mods

## Configuration Files

**Modified Files** (voyager_adapted keymap only):
- `keyboards/beekeeb/piantor_pro/keymaps/voyager_adapted/config.h`
- `keyboards/beekeeb/piantor_pro/keymaps/voyager_adapted/keymap.c`

**Scope**: Changes affect ONLY voyager_adapted keymap, not other keymaps/keyboards

**Status**: ✅ Fully tested and validated at 74 WPM with 20gf switches
**Last Updated**: 2025-10-04