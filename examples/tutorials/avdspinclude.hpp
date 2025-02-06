//example consireing samples as 32 bits integer and processor in float
typedef float accu_t; 
typedef int   sample_t;
sample_t * samplesPtr;   //samples are coded q31 between -1 < x < 1
unsigned dspCoreMask;
int dspFS;          //hold the current sampling rate in samples per seconds
/***** *****/
int dspFreqIndex(int fs){ return ((fs==44100?0:(fs==48000?1:(fs==88200?2:(fs==96000?3:(fs==176400?4:(fs==192000?5:(fs==352800?6:(fs==384000?7:7)))))))));}
typedef union { int i_; float f_; int i[1]; float f[1]; accu_t a_; accu_t a[1]; } dspifa_t;
dspifa_t * dataPtr;
static accu_t accuX, accuY;
typedef struct { unsigned io; accu_t val; } dsp_MIXER_t;
int  dsp_CORE(unsigned any1, unsigned no0) { return (dspCoreMask & any1) && ((dspCoreMask & no0)==0); };
void dsp_LOAD(unsigned n)    { accuX = samplesPtr[n]; };
void dsp_LOAD_STORE(unsigned i,unsigned o) { samplesPtr[o] = samplesPtr[i]; }
void dsp_GAIN(float g)  { accuX *= g; }
void dsp_MIXER(dsp_MIXER_t * ptr,unsigned n);
void dsp_CLRXY()  { accuX = 0; };
void dsp_COPYXY() { accuY = accuX; };
void dsp_COPYYX() { accuX = accuY; };
void dsp_SWAPXY() { accu_t accu = accuY; accuY = accuX; accuX = accu; };
void dsp_ADDXY()  { accuX += accuY; };
void dsp_ADDYX()  { accuY += accuX; };
void dsp_SUBXY()  { accuX -= accuY; };
void dsp_SUBYX()  { accuY -= accuX; };
void dsp_AVGXY()  { accuX = (accuX+accuY)/2;};
void dsp_AVGYX()  { accuY = (accuX+accuY)/2;};
void dsp_NEGX()   { accuX = -accuX; };
void dsp_NEGY()   { accuY = -accuY; };
void dsp_MULXY()  { accuX *= accuY; };
void dsp_MULYX()  { accuY *= accuX; };
void dsp_DIVXY()  { accuX /= accuY; };
void dsp_DIVYX()  { accuY /= accuX; };
void dsp_VALUEX(float f) { accuX = f; };
void dsp_VALUEY(float f) { accuY = f; };
void dsp_CLIP(float f) { if (accuX>f) accuX = f; else if (accuX<f) accuX = -f; };
void dsp_SAT0DB() { if (accuX >1) accuX=1; else if (accuX<-1) accuX = -1; };
void dsp_SAT0DB_VOL(){ if (accuX >1) accuX=1; else if (accuX<-1) accuX = -1; }; //TODO
void dsp_SAT0DB_GAIN(float g) { accuX *= g; dsp_SAT0DB(); }
void dsp_WHITE() { accuX = 0; };//TODO
void dsp_STORE(int n) { do { samplesPtr[n & 255] = accuX; n >>= 8; } while (n); }
void dsp_DELAY(int microsec, int data, int max) { 
    int n = dspFS * microsec * 0.000001;
    if (n > max) n = max; //sanitycheck
    int idx = dataPtr[data].i_;
    accu_t acc = dataPtr[data+1].a[idx]; 
    dataPtr[data+1].a[idx] = accuX;
    idx++; if (idx >= n) idx=0;
    dataPtr[data].i_ = idx; }
void dsp_DELAY_DP(int microsec, int data, int max) { dsp_DELAY(microsec,data,max); }
void dsp_DELAY_1(int data) { accu_t acc = accuX; accuX = dataPtr[data].a_; dataPtr[data].a_ = acc; }
void dsp_LOAD_GAIN(int i, float g) { accuX = samplesPtr[i] * g; }
void dsp_STORE_VOL(int o) { dsp_SAT0DB_VOL(); dsp_STORE(o); }
void dsp_STORE_VOL_SAT(int o) { dsp_SAT0DB(); dsp_STORE(o); }
void dsp_STORE_TPDF(int o) { dsp_STORE(o); } //TODO apply tpdf
void dsp_STORE_GAIN(int o, float g) { accuX *= g; dsp_STORE(o); }
void dsp_INTEGRATOR(int data) { dataPtr[data].a_ += accuX; }
void dsp_CIC(int microsec, int data, int max) { 
    int n = dspFS * microsec * 0.000001;
    if (n > max) n = max; //sanitycheck
} //TODO
void dsp_CIC_N(int data, int max, int size, float coef) { } //TODO
void dsp_EXPMA(int data,float alpha) { 
    accu_t yn = dataPtr[data].a_; 
    dataPtr[data].a_ = yn + (1.0-alpha)*(accuX - yn); } 
void dsp_THDCOMP(float c2, float c3) { accuX += (accuX*accuX * ( c2 + accuX * c3)); }
void dsp_TPDF(int n) {}
void dsp_TPDF_CALC(int n) { }
void dsp_BIQUAD_calc(float * coefs, float * state) {
    accu_t xn = accuX;
    //      yn-1     + b0 * xn     + b1 * xn-1         + b2 * xn-2         + a1 * yn-1         + a2 * yn-2
    accuX = state[0] + coefs[0]*xn + coefs[1]*state[2] + coefs[2]*state[3] + coefs[3]*state[4] + coefs[4]*state[5];
    //  xn-2 <- xn-1         xn-1 <- xn     yn-2 <- yn-1        yn-1  <- yn-1     <- yn
    state[3] = state[2]; state[2] = xn; state[5] = state[4]; state[0] = state[4] = accuX;
}
void dsp_BIQUADS(void const * label, int sections, int data, int max) {
    float * coefs = (float*)label + 2+3+(dspFreqIndex(dspFS)*6);
    dsp_BIQUAD_calc(coefs, &dataPtr[data].f[0]);
}
void dsp_BIQUADS_FS(void const * label, int sections, int data, int max) {
    float * coefs = (float*)label + max;
    dsp_BIQUAD_calc(coefs, &dataPtr[data].f[0]);
}


