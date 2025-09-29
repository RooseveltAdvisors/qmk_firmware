# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project Overview

QMK (Quantum Mechanical Keyboard) is an open-source keyboard firmware framework for custom mechanical keyboards. It supports Atmel AVR and ARM controllers and provides a modular, feature-rich foundation for keyboard customization.

## Essential Commands

### Building and Flashing
```bash
# Build specific keyboard and keymap
make <keyboard>:<keymap>
# Example: make planck/rev6:default

# Flash firmware to connected keyboard
make <keyboard>:<keymap>:flash

# Using QMK CLI (preferred for development)
qmk compile -kb <keyboard> -km <keymap>
qmk flash -kb <keyboard> -km <keymap>

# List all available keyboards
qmk list-keyboards

# Clean build artifacts
make clean
make distclean  # Also removes .hex/.bin/.uf2 files
```

### Development and Testing
```bash
# Format code (run before committing)
qmk format-c -a
qmk format-python -a

# Run tests
qmk pytest
make test:all

# Check QMK installation
qmk hello

# Update submodules (run if build issues occur)
qmk git-submodule --sync
```

## Architecture Overview

### Core Directory Structure
- **quantum/**: Main QMK framework with feature modules (RGB, Audio, Split keyboards, etc.)
- **keyboards/**: 500+ individual keyboard definitions organized by manufacturer
- **tmk_core/**: Low-level hardware abstraction for AVR/ARM platforms
- **keymaps/**: Keyboard-specific layout definitions
- **users/**: Cross-keyboard user customizations
- **builddefs/**: Build system infrastructure and makefiles

### Configuration Hierarchy
QMK uses a cascading configuration system:
1. **quantum/config.h**: Global defaults
2. **keyboards/[keyboard]/config.h**: Keyboard-specific settings
3. **keyboards/[keyboard]/keymaps/[keymap]/config.h**: Keymap overrides
4. **users/[user]/config.h**: User-specific settings

### Build Target Format
All builds use: `<keyboard>:<keymap>[:target]`
- **keyboard**: Path relative to keyboards/ (e.g., `planck/rev6`, `dz60`)
- **keymap**: Keymap name from keyboard's keymaps/ directory
- **target**: Optional (compile=default, flash, clean, etc.)

## Development Workflow

### Creating/Modifying Keyboards
1. Keyboard definitions live in `keyboards/[manufacturer]/[model]/`
2. Required files: `config.h`, `info.json`, `rules.mk`, `[keyboard].c`
3. Keymaps go in `keyboards/[keyboard]/keymaps/[keymap]/keymap.c`
4. Test build: `make [keyboard]:[keymap]`

### Code Style Requirements
- **C Style**: Google-based, 4-space indentation, 1000 char line limit
- **Naming**: snake_case for functions/variables, UPPER_SNAKE_CASE for constants
- **Headers**: Use `#pragma once`, feature-based conditional compilation
- **Formatting**: Must run `qmk format-c -a` before committing

### Feature Development
- Features are modular and live in `quantum/[feature]/`
- Enable via `#define FEATURE_ENABLE` in config.h and `FEATURE_ENABLE = yes` in rules.mk
- Common features: RGBLIGHT, AUDIO, ENCODER, SPLIT_KEYBOARD, VIA

### Quality Assurance
Before committing changes:
1. `qmk format-c -a && qmk format-python -a`
2. `qmk pytest`
3. Test build affected keyboards
4. Verify submodules: `qmk git-submodule --check`

## Hardware Architecture

### Supported Platforms
- **AVR**: ATmega32U4, ATmega32U2, ATmega328P
- **ARM**: STM32F1xx, STM32F4xx, RP2040, Kinetis
- **Communication**: USB HID, Split keyboard protocols

### Key Processing Pipeline
1. **Matrix Scan**: Hardware key state detection
2. **Debouncing**: Filter mechanical switch noise
3. **Keycode Processing**: Convert matrix position to keycode
4. **Action Processing**: Handle layers, modifiers, special functions
5. **HID Output**: Send USB HID reports to host

### Memory Layout
- **Flash**: Firmware code and read-only configuration
- **EEPROM**: Persistent settings (layouts, RGB config, etc.)
- **RAM**: Runtime state and buffers

## Common Patterns

### Keymap Structure
```c
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_60_ansi(
        KC_ESC,  KC_1,    KC_2,    /* ... */
    ),
};
```

### Feature Integration
```c
// In config.h
#define FEATURE_ENABLE

// In keymap.c
#ifdef FEATURE_ENABLE
void feature_function(void) {
    // Feature-specific code
}
#endif
```

### Platform Detection
```c
#ifdef __AVR__
    // AVR-specific code
#elif defined(PROTOCOL_CHIBIOS)
    // ARM/ChibiOS code
#endif
```

The QMK codebase emphasizes modularity, hardware abstraction, and extensive customization while maintaining consistent build patterns across hundreds of keyboard variants.