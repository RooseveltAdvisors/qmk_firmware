# QMK Build System

## Primary Build Commands

### Building Keyboards
```bash
# Build specific keyboard:keymap combination
make <keyboard>:<keymap>

# Examples:
make planck/rev6:default
make dz60:default
make ergodox_ez:default

# Flash firmware to keyboard
make <keyboard>:<keymap>:flash

# Clean build artifacts
make clean

# Clean all build artifacts and binaries
make distclean
```

### QMK CLI Tool Commands
```bash
# Check if qmk is working
qmk hello

# List all keyboards
qmk list-keyboards

# Compile a keyboard
qmk compile -kb <keyboard> -km <keymap>

# Flash firmware
qmk flash -kb <keyboard> -km <keymap>

# Format code
qmk format-c
qmk format-python

# Run tests
qmk pytest

# Update git submodules
qmk git-submodule --sync
```

## Build Infrastructure
- **Main Makefile**: Root level makefile that parses keyboard:keymap:target format
- **builddefs/**: Build definition files for different targets and features
- **Submodule Management**: Automatic git submodule sync and validation
- **Python CLI**: Modern `qmk` command provides easier interface than raw make
- **Docker Support**: Containerized builds available for consistency

## Target Format
The build system uses the format: `<keyboard>:<keymap>[:target]`
- keyboard: Path to keyboard in keyboards/ directory
- keymap: Name of keymap in keyboard's keymaps/ directory  
- target: Optional build target (default is to compile, 'flash' flashes to device)