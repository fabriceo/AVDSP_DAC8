# AVDSP_DAC8
AVDSP for DAC8PRO and DAC8STEREO

This repository contains firmware binary files for DAC8PRO and DAC8STEREO products.
the firmware shall be flashed into the XMOS target CPU using usb cables and either
- Thesycon DFU utility for windows platform
- xmosusb utility for other operating system, available in the usbtool directory

IMPORTANT:
These firmwares are created form the original source code and provide the exact same feature and behaviour than the official version provided by the manufacturer.
They do not include a copy of the standard version of the firmware used in the front panel and are only compatible with front panel firmware V1.6 and higher.
The front panel will recognize a dsp enabled version and will show a specific entry in the "filter" menu to select a dsp program between 1 and 4 (or 0 to switch dsp off)
Once flashed, these firmware comes on top of the factory firmware, the original factory firmware is not replaced as such.
In case of issue during the flash or upgrade process, the original factory firmware is automaticaly restored.
Once installed, the behaviour of the audio inputs and outputs of the product depends of the dsp program selected in the "filter" menu and become the entire responsability of the user.

more to come

