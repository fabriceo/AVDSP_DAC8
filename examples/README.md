# AVDSP_DAC8
AVDSP for DAC8PRO and DAC8STEREO

This repository contains few examples ready for generating binary program with dspcreate

file ending with .txt contains macros and can be processed directly with the following command:
dspcreate <options> -dsptext myfile.txt -binfile mytarget.bin <defines>

<options> are explained in the documentation of the dspcreate utility
<defines> is a list of statement which will be added virtually at the top of the text file before processing it.
this gives the possibility to set or force some variable like cutoff frequency or delays or gains

files provided as c source code must be compiled with any C compiler able to generate a dynamic library file that will be used by dspcreate.
the path of the encoder header file must be provided.

example:
./dspcreate -dspformat 28 -dsptext crossover4way.txt -binfile crossover4way.bin FCUT=450 DIST=100

this will generate the binary file crossover4way.bin by compiling the text file crossover4way.txt, with any numerical value being encoded as a 32 bit fixed integer 
with 28bits mantissa, 1 sign bit and 3bits for the integer part.


more to come

