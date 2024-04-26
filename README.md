# AVDSP_DAC8
AVDSP for DAC8PRO and DAC8STEREO

This repository contains utilities to provide DSP functionalities to DAC8PRO and DAC8STEREO products and to develop and upload dsp programs into the devices over usb.
The original devlopement is based on AVDSP (see dedicated repo) and has been specialized for XMOS target cpu.

User support is provided on a goodwill basis by email at avdspproject@gmail.com

Community users are welcome to directly use Github to report issues as long as they are reasonably documented.

## Q & A
### 1) Is this DAC8 firmware officially supported by OktoResearch ?
The firmware has been tested by Okto research and is recognized to perform as good as the original 1.60 version. It can be installed by the end user with the Okto research DFU utility without impacting the warranty conditions.

### 2) This looks complex ! why not providing a graphic user interface ?
The original goal was to extend the capabilities of the DAC8 products by leveraging the unused power of the embded XU216 cpu. the AVDSP project was a good way to provide DSP capabilities with reasonable efforts but its flexibility and the language oriented approach are not really compatible with a static graphic interface.

### 3) Can I revert back my DAC8 product if I m not happy with the DSP capability ?
Yes, the DAC8 DSP firmware is installed in flash memory after the original factory firmware and thus it is always possible to revert to original version. But when DSP Prog 0 is selected in the filter menu, the behaviour of the DAC is exact same as the original firmware.

more to come

