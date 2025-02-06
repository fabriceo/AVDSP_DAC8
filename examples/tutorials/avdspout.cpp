//welcome to cplusplus

#include "avdspinclude.hpp"


// dsp_PARAM section start
const float bp[][6] = {
   { 76, 1000.000000, 3.000000, 1.000000, 0, 0 }, //BP0DB
   { 76, 1000.000000, 3.000000, 1.000000, 0, 0 }, //BP0DB
   { 76, 1000.000000, 3.000000, 1.000000, 0, 0 }, //BP0DB
{ 0,0,0,0,0,0},{ 0,0,0,0,0,0},{ 0,0,0,0,0,0}, }; //3 biquad cell(s) provided
const float no[][6] = {
   { 75, 1000.000000, 10.000000, 1.000000, 0, 0 }, //NOTCH
{ 0,0,0,0,0,0}, }; //1 biquad cell(s) provided
void dsp_CORE1() {
   if (0==dsp_CORE(0xffffffff,0x0)) return;
   dsp_LOAD(16);
   dsp_STORE(24);
   dsp_BIQUADS(&bp,3,32,18); //TODO
   dsp_STORE(25);
   dsp_NEGX();
   dsp_COPYXY();
   dsp_LOAD(16);
   dsp_BIQUADS(&no,1,50,6); //TODO
   dsp_STORE(26);
   dsp_ADDXY();
   dsp_STORE(27);
} //end of core 1
int dspDataSpace1[56];
