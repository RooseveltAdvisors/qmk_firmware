# QMK Code Style and Conventions

## C Code Style (.clang-format)
- **Base Style**: Google C++ style guide
- **Indentation**: 4 spaces (no tabs)
- **Column Limit**: 1000 characters (very wide)
- **Pointer Alignment**: Right-aligned (`int *ptr`)
- **Consecutive Alignment**: Align assignments and declarations
- **Preprocessor**: Indent directives after hash
- **Case Labels**: Indented within switch statements

## Naming Conventions
- **Files**: snake_case.c, snake_case.h
- **Functions**: snake_case()
- **Variables**: snake_case
- **Constants**: UPPER_SNAKE_CASE
- **Preprocessor**: UPPER_SNAKE_CASE

## File Organization
- **Headers**: Include guards using `#pragma once`
- **Includes**: Platform deps first, then local headers
- **Feature Flags**: Heavy use of conditional compilation (#ifdef)

## Architecture Patterns
- **Configuration Hierarchy**: config.h files cascade from quantum → keyboard → keymap
- **Feature Modules**: Self-contained feature implementations in quantum/
- **Hardware Abstraction**: Platform-specific code in tmk_core/
- **Keymap Structure**: Keymaps define layout and behavior for specific keyboards

## Git Conventions
- **Submodules**: External libraries managed as git submodules in lib/
- **Branch Strategy**: Development on feature branches, stable releases tagged
- **Commit Style**: Descriptive commit messages with component prefixes