# AVDSP_DAC8 / AVDSP Tools
## AVDSP for DAC8PRO and DAC8STEREO

This repository contains an extension for Visual Studio Code, to provide code highlighting when editing a file with extension .avd or .avdsp

keywords core,end, section and MEMORY are shown in light blue.
all dsp functions like input, biquad, delayus... are shown in pink
all filter names like LPLR4, PEAK ... are shown in light blue.

to install the extension, eventually quit vscode, and just copy the **avdsp-code-highlighting** folder into folder **.vscode** which exists in your user home directory, and delete the file extensions.json already existing in this .vscode folder, it will be rebuilt upon vscode startup automatically.

Create a new file with extension .avd or .avdsp, or open one of the provided examples and the code displayed will be colored accordingly.

the file **tasks.json** contains simple declaration for launching dspcreate and xmosusb from the menu "terminal" in vscode and is a quick way to analyse the avdsp programs and upload them directly into the dac without opening a terminal session and typing commands.
 To install this file, go in your working folder where you have your avdsp files and copy tasks.json inside the folder .vscode which should be there, otherwise create it first.
 

January 18th,2025
