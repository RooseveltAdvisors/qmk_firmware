# Piantor Pro Flash Workflow

## User Preference: Flash Command Meaning

When the user says "flash to Piantor Pro" or "flash firmware to keyboard", they mean:

1. **Compile the firmware:**
   ```bash
   qmk compile -kb beekeeb/piantor_pro -km voyager_adapted
   ```

2. **Copy UF2 file to removable drive:**
   ```bash
   cp -X beekeeb_piantor_pro_voyager_adapted.uf2 /Volumes/RPI-RP2/
   ```

## Key Points

- **Do NOT use:** `qmk flash` command (this is not the preferred workflow)
- **Always use:** Manual compile + copy to RPI-RP2 volume
- **Use -X flag:** The `-X` flag prevents extended attribute errors when copying to the bootloader volume
- **Bootloader volume:** The Piantor Pro appears as `/Volumes/RPI-RP2/` when in bootloader mode

## Full Workflow

```bash
# 1. Compile firmware
qmk compile -kb beekeeb/piantor_pro -km voyager_adapted

# 2. Copy to keyboard (bootloader must be active)
cp -X beekeeb_piantor_pro_voyager_adapted.uf2 /Volumes/RPI-RP2/

# 3. Confirm success
echo "✅ Firmware flashed successfully!"
```

## Keyboard Details
- **Board:** Beekeeb Piantor Pro
- **Controller:** RP2040 (Raspberry Pi Pico)
- **Bootloader:** Appears as RPI-RP2 removable drive
- **Keymap:** voyager_adapted (adapted from ZSA Voyager layout)
- **Firmware format:** UF2 file

## Bootloader Mode
To enter bootloader mode on Piantor Pro:
- Double-tap the reset button on the keyboard
- The RPI-RP2 volume will mount automatically
- Ready to receive firmware via file copy
