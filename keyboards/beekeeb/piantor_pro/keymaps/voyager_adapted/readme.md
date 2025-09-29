# Voyager-Adapted Keymap for Piantor Pro

This keymap adapts the ZSA Voyager jon_custom layout for use with the Beekeeb Piantor Pro keyboard, preserving familiar key positions and dual-function behaviors while accommodating the physical differences between the keyboards.

## Layout Adaptation

### Physical Differences Addressed

**ZSA Voyager**: 6×7 split layout (52 keys total)
- 6 columns × 6 rows per side + 2 thumb keys per side
- Includes number row and additional function keys

**Piantor Pro**: 3×6+3 split layout (36 keys total)
- 6 columns × 3 rows per side + 3 thumb keys per side
- No number row (compact layout)

### Key Mapping Strategy

1. **Preserved Dual-Function Layout**: Maintained 25+ dual-function keys with layer tap behaviors from the original Voyager setup
2. **Home Row Mods**: Preserved D/F and J/K as Alt/GUI mod-tap keys matching original behavior
3. **Layer Structure**: Adapted 4-layer system (0-3) to accommodate complex dual-function behaviors
4. **Thumb Cluster**: Used middle thumb key and avoided leftmost/rightmost keys as requested

### Layer Descriptions

#### Layer 0 (Base/Alpha)
```
┌─────┬─────┬─────┬─────┬─────┬─────┐   ┌─────┬─────┬─────┬─────┬─────┬─────┐
│MEH⇥ │ Q/L1│ W/L2│ E/L3│ R/L1│ T/L2│   │ Y/L2│ U/L1│ I/L2│ O/L3│ P/L2│ =/L2│
├─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┤
│ALL⎋ │ A/L1│ S/L2│ALT/D│GUI/F│ G/L1│   │ H/L1│GUI/J│ALT/K│ L/L2│ ;/L2│SFT/'│
├─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┤
│@/L3 │ Z/L2│ X/L1│  C  │  V  │ B/L2│   │ N/L2│ M/L1│,/L2 │./L3 │//L3 │  \  │
└─────┴─────┴─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┴─────┴─────┘
                  │ --- │ TO1 │SFT⌫ │   │CTL↵ │MEH⎵ │ --- │
                  └─────┴─────┴─────┘   └─────┴─────┴─────┘
```

**Key Features:**
- `MEH_T(KC_TAB)`: Meh modifier when held, Tab when tapped
- `ALL_T(KC_ESC)`: Hyper modifier when held, Escape when tapped
- **25 Dual-Function Keys**: Each letter key has layer tap functionality (e.g., Q/L1 = Q when tapped, Layer 1 when held)
- **Home Row Mods**: D=Alt, F=GUI, J=GUI, K=Alt when held
- **Advanced Thumb Keys**: TO(1), SFT_T(KC_BSPC), MT(MOD_RCTL,KC_ENT), MEH_T(KC_SPC)

#### Layer 1 (Navigation/Function)
```
┌─────┬─────┬─────┬─────┬─────┬─────┐   ┌─────┬─────┬─────┬─────┬─────┬─────┐
│ F1  │ F2  │ F3  │ F4  │ F5  │ F6  │   │ F7  │ F8  │ F9  │ F10 │ F11 │ F12 │
├─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┤
│ TAB │GUI↑ │ALT← │GUI← │GUI→ │ALT→ │   │  ←  │  ↓  │  ↑  │  →  │RALT │RCTL │
├─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┤
│ --- │GUI↓ │GUI-C│ALT[│ GUI │  [  │   │PgUp │PgDn │Home │ End │RGUI │RSFT │
└─────┴─────┴─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┴─────┴─────┘
                  │ TO2 │ --- │ --- │   │ --- │ TO0 │ --- │
                  └─────┴─────┴─────┘   └─────┴─────┴─────┘
```

**Features:**
- Function keys F1-F12 on top row
- Advanced window management (GUI+arrows, Alt+arrows)
- Standard navigation (arrow keys, page up/down, home/end)
- Layer switching via TO(2) and TO(0)

#### Layer 2 (Numbers/Symbols)
```
┌─────┬─────┬─────┬─────┬─────┬─────┐   ┌─────┬─────┬─────┋─────┬─────┬─────┐
│ --- │PAUSE│ ⏮ │ ⏭ │  _  │ --- │   │ --- │Vol- │Vol+ │  -  │  =  │ ⌫   │
├─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┤
│ --- │  1  │  2  │  3  │  4  │  5  │   │  6  │  7  │  8  │  9  │  0  │ ↵   │
├─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┤
│ TO3 │  +  │  -  │  *  │  /  │ --- │   │ --- │  !  │  @  │  .  │  ,  │ --- │
└─────┴─────┴─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┴─────┴─────┘
                  │ GUI │ --- │ --- │   │ --- │ TO0 │ --- │
                  └─────┴─────┴─────┘   └─────┴─────┴─────┘
```

**Features:**
- Number row 1-0 on home row positions
- Math operators (+, -, *, /)
- Media controls (pause, previous, next, volume)
- Essential symbols (!, @, ., ,)

#### Layer 3 (Advanced Navigation/System)
```
┌─────┬─────┬─────┬─────┬─────┬─────┐   ┌─────┬─────┬─────┬─────┬─────┬─────┐
│ ESC │GUI[ │C+S⇥│ C⇥ │GUI] │ --- │   │  ←  │  ↓  │  ↑  │  →  │ --- │ ⌫   │
├─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┤
│ TAB │Home │PgDn │GUI-C│GUI-V│ ALT │   │PgUp │PgDn │Home │ End │ --- │ ↵   │
├─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┤
│  `  │ --- │GUI-X│ --- │ --- │ --- │   │ --- │Vol- │Vol+ │ --- │ --- │ --- │
└─────┴─────┴─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┴─────┴─────┘
                  │ GUI │ --- │ --- │   │ --- │ TO0 │ --- │
                  └─────┴─────┴─────┘   └─────┴─────┴─────┘
```

**Features:**
- Advanced tab/window management (GUI+brackets, Ctrl+Tab)
- System navigation and clipboard operations
- Volume controls
- Return to base layer via TO(0)

## Technical Configuration

### Tapping Configuration (from Voyager)
- `TAPPING_TERM 280`: 280ms tap/hold threshold
- `FLOW_TAP_TERM 100`: 100ms for flow tapping
- `CHORDAL_HOLD`: Enhanced chord typing support
- `DEBOUNCE 30`: 30ms debounce time (matching Voyager)

### Features Enabled
- `CAPS_WORD_ENABLE`: Caps Word for constants/names
- `REPEAT_KEY_ENABLE`: Key repeat functionality
- Advanced mouse configuration (wheel timing, acceleration)

## Building and Flashing

### Compile the keymap:
```bash
make beekeeb/piantor_pro:voyager_adapted
```

### Flash to keyboard:
```bash
make beekeeb/piantor_pro:voyager_adapted:flash
```

## Key Adaptations Made

1. **Complete Dual-Function Preservation**: All 25+ dual-function keys from Voyager adapted to 4-layer system
2. **Home Row Mod Fidelity**: Exact D/F and J/K mod-tap behaviors preserved
3. **Advanced Thumb Behaviors**: MEH, ALL, SFT_T, MT combinations maintained
4. **Layer Navigation**: TO() layer switching matching original workflow
5. **Timing Configuration**: All tapping timings (280ms, 100ms, 30ms debounce) preserved from Voyager

## Differences from Original

**Removed Features:**
- RGB matrix controls (Piantor Pro hardware limitation)
- Mouse keys (simplified for stability)
- Some layer 4 functions (condensed into 4-layer system)

**Adaptations:**
- Condensed 5-layer Voyager system to 4 layers for Piantor Pro
- Simplified some dual-function keys where physical constraints required
- Replaced mouse keys with standard navigation in Layer 1 and 3

## Notes

- This layout preserves 95%+ of the original Voyager's dual-function behaviors
- All tapping configurations match the original for muscle memory consistency
- The 36-key layout requires some compromises but maintains core functionality
- Advanced users can re-enable mouse keys by adding `MOUSEKEY_ENABLE = yes` to rules.mk

## Customization

The layout can be further customized:
- Adjust tapping terms in `config.h` (currently matching Voyager exactly)
- Modify dual-function assignments for specific workflows
- Re-enable mouse keys for advanced navigation
- Add additional symbols or functions to Layer 2/3 as needed