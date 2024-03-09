# AVDSP_DAC8
## AVDSP for DAC8PRO and DAC8STEREO / Firmwares

This repository contains firmware binary files for DAC8PRO and DAC8STEREO products.
the firmware shall be flashed into the XMOS target CPU using usb cables and either
- **Thesycon DFU utility** for windows platform
- **xmosusb** utility for other operating system, available in the usbtool directory

**IMPORTANT:**
These firmwares are created form the original source code and provide the exact same feature and behaviour than the official version provided by the manufacturer (for a given version, starting V1.6).
They do not include a copy of the firmware used in the front panel (user interface) and are only compatible with front panel firmware V1.6 and higher.
The front panel will recognize a dsp-enabled firmware version and will show a specific entry in the **Filter** menu to select a dsp program between 1 and 4 (or 0 to switch dsp off).
Once flashed, the dsp firmwares comes on top of the factory firmware, the original factory firmware is not replaced as such.
In case of issue during the flash or upgrade process, the original factory firmware is automaticaly restored.
Once installed, the behaviour of the audio inputs and outputs of the DAC8PRO or DAC8STEREO product will depend of the dsp program selected in the "filter" menu and become under the entire responsability of the user.
The manufacturer is not liable for any damage caused to the component (especially loudspeaker drivers) driven by a dac configured with a user dsp program.

## WHICH FIRMWARE TO USE
DAC8STEREO has only a single version with maximum sampling frequency at 192khz (instead of 384 for standard version)
DAC8PRO is provided with 2 versions:
A ) maximum 48khz, supporting 4 AES inputs (8 channels)
B ) maximum 96khz, supporting a single AES input (2 channels)
a specific version can be provided for OEM with other configuration and sampling rates up to 192khz.

DSD audio stream cannot be treated by DSP, therefore any DSD audio signal will be converted to silence

more to come

