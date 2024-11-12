# AVDSP_DAC8 / AVDSP Tools
## AVDSP for DAC8PRO and DAC8STEREO

This repository contains libraries and utilities to compile dsp programs written with AVDSP commands and syntax, and to generate opcodes files used by AVDSP runtime.

Binary files can be created with **dspcreate** utility, either from a simple text file containing a flow of avdsp macros, 
or from a compiled object file originally written in C langage and using the **libavdspencoder** libray.

**dspcreate** and the encoder library are provided for all operating system and must be launched from a terminal or shell window.
The resulting binary file can be uploaded straight in the DAC8PRODSP or DAC8STEREODSP memory with the usbtool utility, and then saved to 4 flash memory locations.

Source code for dspcreate and libavdspencoder can be found in branch "develop" here  https://github.com/fabriceo/AVDSP/tree/develop/module_avdsp/encoder

Novenber 12th,2024
