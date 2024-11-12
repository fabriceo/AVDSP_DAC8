# AVDSP_DAC8
## AVDSP for DAC8PRO and DAC8STEREO / usb tools

This repository contains utilities to interact with DAC8 DSP from the host computer over usb.

Each device connected to usb is identified with a VID-PID (vendor identifier and product identifier) usually presented in hexadecimal value
DAC8PRO is identified as 152A-88C4, DAC8STEREO is identified as 152A-88C5
Each DAC8 device exposes a descriptor for usb audio class 2 interfaces and for DFU interface.

By default windows will install a standard stereo driver called usbaudio2.sys.
on other platform (osx or linux based) a standard multichannel audio class 2 driver is already enabled.

For windows computer, a specific driver called "winusb" is also required to pass trough the usbtool commands to the device.
It must be installed on Interface 3. This can be done easily with Zadig opensource software. See further instruction in the other documents.
When a Thesycon audio driver for DAC8PRO or DAC8STEREO is installed, it will somehow overwrite the windows drivers and intercept all the audio and commands flows.
To be able to use the usbtool, it is then required to uninstall the Thesycon driver which will be then automatically replaced by the windows drivers.
The Thesycon driver can be reinstalled later when developement and tests are finished.

for other platform, the usbtools is using libusb. the library is staticaly included in the OSX version, but for linux this must be installed upfront by the user with the linux package manager.

Source code for xmosusb can be found in https://github.com/fabriceo/XMOS/tree/master/xmosusb

## REMARK:
for windows, uninstalling and reinstalling the Thesycon audio driver during dsp program devlopement is a borring exercise. 
The dsp firmware includes a specific process to reboot as an usb device with another VID-PID wich gives the possibility to interact with usbtool in a seamless way.
see other document for more information.
 
November 12th,2024

