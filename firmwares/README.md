# AVDSP_DAC8
## AVDSP for DAC8PRO and DAC8STEREO / Firmwares

This repository contains firmware binary files for DAC8PRO and DAC8STEREO products.
the firmware shall be flashed into the XMOS target CPU using usb cables and either
- **Thesycon DFU utility** for windows platform
- **xmosusb** utility for other operating system, available in the usbtool directory

**IMPORTANT:**
These firmwares are created form the original source code and provide the exact same feature and behaviour than the official version provided by the manufacturer (for a given version, starting V1.6).
The front panel will recognize a dsp-enabled firmware version and will show a specific entry in the **Filter** menu to select a dsp program between 1 and 4 (or 0 to switch dsp off).
Once flashed, the dsp firmwares comes on top of the factory firmware, the original factory firmware is not replaced as such.
In case of issue during the flash or upgrade process, the original factory firmware is automaticaly restored.
Once installed, the behaviour of the audio inputs and outputs of the DAC8PRO or DAC8STEREO product will depend of the dsp program selected in the "filter" menu and become under the entire responsability of the user.
The manufacturer is not liable for any damage caused to the component (especially loudspeaker drivers) driven by a DAC8PRO or DAC8STEREO configured with a user dsp program.

## WHICH FIRMWARE TO USE
see documentation in PDF file.
DAC8PRO : 2 versions possible depending if you use the 4 AES inputs(8 channels) in a raw, or if you use these inputs always in stereo mode.
DAC8STEREO : 2 versions possible depending if you own a standard DAC8STEREO or a custom version with the 8 independent outputs.

## Where are the firmwares ??
For the time being we send the firmware to any DAC8 product owner just requiring it by email to the support adress avdspproject@gmail.com
This is the chosen way to provide advise and support and to manage user expectation. Also this provides valuable return of experience that will be used to enhance the solution.
Please provide your serial number and DAC model and a short summary of your project. You will receive the binary firmware file free of charge and configured for your serial number.


May 5,2024

