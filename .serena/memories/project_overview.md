# QMK Firmware Project Overview

## Purpose
QMK (Quantum Mechanical Keyboard) is an open-source keyboard firmware based on tmk_keyboard firmware. It supports Atmel AVR and ARM controllers and is designed primarily for custom mechanical keyboards.

## Core Components
- **Quantum Core**: The main firmware framework (`quantum/` directory)
- **Keyboard Definitions**: Individual keyboard configurations (`keyboards/` directory)
- **TMK Core**: Low-level hardware abstraction layer (`tmk_core/` directory)
- **Layouts**: Shared keymap layouts (`layouts/` directory)
- **Users**: Personal user configurations (`users/` directory)
- **Build System**: Make-based build system with Python CLI tool

## Tech Stack
- **Languages**: C (primary), Python (build tools)
- **Build System**: GNU Make with custom makefile infrastructure
- **CLI Tool**: Python-based `qmk` command-line interface
- **Supported Platforms**: AVR microcontrollers, ARM Cortex-M
- **Version Control**: Git with submodules for libraries

## Architecture Pattern
- **Hierarchical Configuration**: Global → Keyboard → Keymap → User
- **Feature Modules**: Modular features (RGB, Audio, Encoders, etc.)
- **Hardware Abstraction**: Platform-specific code isolated in tmk_core
- **Plugin Architecture**: Features can be enabled/disabled via configuration