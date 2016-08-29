cdef extern from "PatchMatch_fun.h":
  cdef void patch_match_cpp(float* in0, float* in1, int dimx0, int dimy0,
                            int dimc0, int dimx1, int dimy1, int dimc1)

import numpy as np
cimport numpy as np

np.import_array()


#def polsarblf(np.ndarray[np.complex64_t, ndim=4] arr, float gs=2.8, float gr=1.4, method = 'ai', bint trick=True, bint flat=False):

def patch_match(np.ndarray[np.float32_t, ndim=3] arr0, np.ndarray[np.float32_t, ndim=3] arr1):
    '''def patch_match(np.ndarray[np.float32_t, ndim=3] arr1, np.ndarray[np.float32_t, ndim=3] arr2)'''
    cdef ndimc0 = arr0.shape[0]
    cdef ndimy0 = arr0.shape[1]
    cdef ndimc0 = arr0.shape[2]
    cdef ndimc1 = arr1.shape[0]
    cdef ndimy1 = arr1.shape[1]
    cdef ndimc1 = arr1.shape[2]

    if ndimc0 != ndimc1:
        raise ValueError("Images must have the same number of channels")

    cdef np.ndarray[np.float32_t, ndim=2] arrout

    patch_match_cpp(<float complex*> arr0.data, <float complex*> arr1.data,
                    <float complex*> arrout.data,
                    int dimx0, int dimy0, int dimc0,
                    int dimx1, int dimy1, int dimc1)
    return arrout
