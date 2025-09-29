# QMK Testing and Quality Assurance

## Test Commands
```bash
# Run Python tests
qmk pytest

# Run all tests
make test:all

# Run specific test
make test:<test_name>

# List available tests
make list-tests

# Docker-based testing (matches CI)
make pytest
make format-core
make format-and-pytest
```

## Code Quality Tools
```bash
# Format C code
qmk format-c --core-only -a

# Format Python code  
qmk format-python -a

# Format all code
qmk format-c -a && qmk format-python -a

# Check code style
# (Format tools also validate style compliance)
```

## Quality Assurance Workflow
- **Pre-commit**: Format code before committing
- **CI/CD**: GitHub Actions run formatting and tests
- **Submodule Validation**: Build system checks submodule status
- **Hardware Testing**: Physical keyboard testing required for keyboard-specific changes

## Test Structure
- **Unit Tests**: Located in tests/ directory
- **Integration Tests**: Build tests for keyboard configurations
- **Python Tests**: pytest-based tests for CLI tools
- **Build Validation**: Ensures all keyboards can compile

## Development Validation
When completing tasks, run:
1. `qmk format-c -a` (format C code)
2. `qmk format-python -a` (format Python code) 
3. `qmk pytest` (run Python tests)
4. `make clean` (clean build artifacts)
5. Test build: `make <keyboard>:<keymap>` for any modified keyboards