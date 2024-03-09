# AVDSP_DAC8
AVDSP for DAC8PRO and DAC8STEREO

This repository contains libraries and utilities to compile dsp programs written with avdsp commands
and to generate opcodes files used by runtime.

Binary files can be created with dspcreate utility, either from a simple text file containing a flow of avdsp macros, 
or from a compiled object file originally written in C langage and using the libencoderavdsp libray.

dspcreate and the encoder library is provided for all operating system and must be launched from a terminal or shell window.
the resulting binary file can be uploaded straight in the DAC8PRO or DAC8STEREO memory with the usbtool utility and then saved to flash memory.

more to come
