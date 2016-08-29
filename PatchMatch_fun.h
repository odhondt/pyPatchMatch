/*
 #
 #  File        : PatchMatch.cpp
 #                ( C++ source file )
 #
 #  Description : Example of use for the CImg plugin 'PatchMatch_plugin'.
 #                ( http://cimg.sourceforge.net )
 #
 #  Copyright   : Olivier D'Hondt
 #                (https://sites.google.com/site/dhondtolivier/)
 #
 #  License     : CeCILL v2.0
 #                ( http://www.cecill.info/licences/Licence_CeCILL_V2-en.html )
 #
 #  This software is governed by the CeCILL  license under French law and
 #  abiding by the rules of distribution of free software.  You can  use,
 #  modify and/ or redistribute the software under the terms of the CeCILL
 #  license as circulated by CEA, CNRS and INRIA at the following URL
 #  "http://www.cecill.info".
 #
 #  As a counterpart to the access to the source code and  rights to copy,
 #  modify and redistribute granted by the license, users are provided only
 #  with a limited warranty  and the software's author,  the holder of the
 #  economic rights,  and the successive licensors  have only  limited
 #  liability.
 #
 #  In this respect, the user's attention is drawn to the risks associated
 #  with loading,  using,  modifying and/or developing or reproducing the
 #  software by the user in light of its specific status of free software,
 #  that may mean  that it is complicated to manipulate,  and  that  also
 #  therefore means  that it is reserved for developers  and  experienced
 #  professionals having in-depth computer knowledge. Users are therefore
 #  encouraged to load and test the software's suitability as regards their
 #  requirements in conditions enabling the security of their systems and/or
 #  data to be ensured and,  more generally, to use and operate it in the
 #  same conditions as regards security.
 #
 #  The fact that you are presently reading this means that you have had
 #  knowledge of the CeCILL license and that you accept its terms.
 #
*/

#include<iostream>

#define cimg_plugin "PatchMatch_plugin.h"
#include "./CImg.h"

using namespace cimg_library;
using namespace std;

void patch_match_cpp(float *in0, float *in1, float *out, 
                     int dimx0, int dimy0, int dimc0
                     int dimx1, int dimy1, int dimc1) {
  CImg<float> img0(in0, dimx0, dimy0, 1, dimc0);
  CImg<float> img1(in1, dimx1, dimy1, 1, dimc1);
  CImg<float> off(out, dimx0, dimy0, 1, 2);
  int P = 5; // TODO: add parameters
  const int N = 5;
  off.patchMatch(img0, img1, P, N);
}
