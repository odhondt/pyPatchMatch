#include<iostream>

#define cimg_plugin "PatchMatch_plugin.h"
#include "./CImg.h"

using namespace cimg_library;
using namespace std;

void patch_match_cpp(float *in0, float *in1, float *out, 
                      int Psize,
                      int Niter,
                      int dimx0, int dimy0, int dimc0, 
                      int dimx1, int dimy1, int dimc1)
{
  CImg<float> img0(in0, dimx0, dimy0, 1, dimc0, true);
  CImg<float> img1(in1, dimx1, dimy1, 1, dimc1, true);
  CImg<float> off(out, dimx0, dimy0, 1, 2, true);
  off.patchMatch(img0, img1, Psize, Niter);
}
