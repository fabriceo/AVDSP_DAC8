# AVDSP_DAC8
## AVDSP for DAC8PRO and DAC8STEREO

This repository contains few examples ready for generating binary program with dspcreate

file ending with .avdsp contains macros and can be processed directly with the following command:
dspcreate myfile.avdsp -options -binfile mytarget.bin defines

**-options** are explained in the documentation of the dspcreate utility
**defines** is a list of statement which will be added virtually at the top of the avdsp file before processing it.
this gives the possibility to set or force some variable like cutoff frequency or delays or gains

example:
./dspcreate  crossover4way.avdsp -binfile bin/crossover4way.bin FCUT=450 DIST=100

this will generate the binary file crossover4way.bin in the local bin folder by compiling the text file crossover4way.avdsp. the parameter FCUT and DIST are overloaded with the values 450 and 100 in this example.

with the new dspcreate encoder version V120, the syntax of the comand line is simplified and the flag -dsptext can be omited when the source filename ends with .avdsp or .avd.
Also a new flag -dspload can be used to automatically launch the xmosusb utility with parameter --dspload and this will use binary file generated and defined with -binfile.

the folder examples 162 contains additional example formated with instructions only compatible with firmware 162 and dspcreate V120

Update August 31th, 2025

