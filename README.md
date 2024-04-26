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

### 3) how can I modify my settings and tune the response ?
The front panel provides the possibility to select 4 differents DSP programs and each program can have a specific behaviour depending on source selection. All the filter coefficients, gains or delays are static and stored within each programs. At the time of writing it is not possible to modify a DSP program by using the front panel menus, but the user can switch the 4 programs with the remote control during music playback.
Dynamic changes and testing are done with the utilities provided and thus requires a usb connection to a computer during devlopement test and tuning. 

### 4) will DSP firmware impact performance of the DAC like THD or Noise ?
The reasonable answer is NO ! the specific runtime is written in assembly langage and extensively use 64 bits computation, with biquad coefficients pre-computed for each sampling rate. This provides an un-precedent performance, especially at high sampling rates. Also for the sake of sound integrity, there are no SRC and no compressor or non linear treatment in the signal chain. A specific clipping detection and autoscalling are used to protect from saturation.

### 5) Can I revert back my DAC8 product if I m not happy with the DSP capability ?
Yes, the DAC8 DSP firmware is installed in flash memory after the original factory firmware and thus it is always possible to revert to original version. But this is not need : when DSP Prog 0 is selected in the filter menu, the behaviour of the DAC is exact same as the original firmware.

### 6) My DSP program is very complex and requires lots of instructions. Can I still use it for 192khz music program ?
When loading or launching a DSP program, the DAC8 product will test the DSP treatment duration for one sample. If it appears that the duration is not compatible with the current sampling rate then a process of decimation is used to reduce the sampling rate by half or even fourth. This decimation process is acceptable but it is recommended to send the music program at a sampling rate compatible with the DSP cpu load, or to downsample the music program upfront on the host player with higher precision. The utility provided gives the exact cpu instructions required per each core and a load purcentage compared to sampling rate.

more to come

