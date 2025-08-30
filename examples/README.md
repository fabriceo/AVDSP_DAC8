# AVDSP_DAC8
## AVDSP for DAC8PRO and DAC8STEREO

This repository contains few examples ready for generating binary program with dspcreate

file ending with .avdsp contains macros and can be processed directly with the following command:
dspcreate options -dsptext myfile.txt -binfile mytarget.bin defines

**options** are explained in the documentation of the dspcreate utility
**defines** is a list of statement which will be added virtually at the top of the avdsp file before processing it.
this gives the possibility to set or force some variable like cutoff frequency or delays or gains

files provided as c source code must be compiled with any C compiler able to generate a dynamic library file that will be used by dspcreate.
the path of the encoder header file must be provided.

example:
./dspcreate -dspformat 28 -dsptext crossover4way.avdsp -binfile crossover4way.bin FCUT=450 DIST=100

this will generate the binary file crossover4way.bin by compiling the text file crossover4way.avdsp, with any numerical value being encoded as a 32 bit fixed integer 
with 28bits mantissa, 1 sign bit and 3bits for the integer part. the parameter FCUT and DIST are overloaded with the values 450 and 100 in this example.

with the new dspcreate encoder version V120, the syntax of the comand line is simplified and the flag -dsptext can be omited when the source filename ends with .avdsp or .avd.
Also a new flag -dspload can be used to automatically launch the xmosusb utility with parameter --dspload and this will use binary file generated and defined with -binfile.

Update August 11th, 2025

