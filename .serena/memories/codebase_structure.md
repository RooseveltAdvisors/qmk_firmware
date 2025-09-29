# QMK Codebase Structure

## Top-Level Directories

### Core Framework
- **quantum/**: Main QMK firmware framework
  - Core keyboard functionality, features, and utilities
  - Feature modules: RGB, Audio, Encoders, Split keyboards, etc.
  - Key processing pipeline and action handling
  
- **tmk_core/**: Low-level hardware abstraction layer
  - Platform-specific code for AVR and ARM
  - USB/HID communication protocols
  - Matrix scanning and hardware interfaces

### Content Directories  
- **keyboards/**: Individual keyboard definitions (~500+ keyboards)
  - Each keyboard has: config.h, info.json, keymaps/, readme.md
  - Hierarchical structure: keyboards/manufacturer/model/
  - Revision support: keyboards/planck/rev6/
  
- **layouts/**: Shared physical layouts (ANSI, ISO, etc.)
  - Community layouts that work across multiple keyboards
  - Layout-specific keymaps
  
- **users/**: Personal user configurations
  - Cross-keyboard user customizations
  - Shared code between user's different keyboards

### Development Infrastructure
- **builddefs/**: Build system makefiles and rules
  - Feature flags and build configuration
  - Target-specific build rules (flash, test, etc.)
  
- **lib/**: External library submodules
  - Third-party dependencies managed as git submodules
  
- **tests/**: Test suite infrastructure
  - Unit tests for core functionality
  - Build validation tests

## Key Configuration Files
- **Makefile**: Root build orchestration
- **paths.mk**: Build system path definitions  
- **info.json**: Keyboard metadata and layout definitions
- **config.h**: Feature flags and configuration hierarchy
- **rules.mk**: Build rules and feature enables
- **.clang-format**: Code style enforcement