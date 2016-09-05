cdef extern from "PatchMatch_fun.h":
  cdef void patch_match_cpp(float* in0, float* in1, float* out, 
      int Psiz, int Niter, 
      int dimx0, int dimy0, int dimc0, 
      int dimx1, int dimy1, int dimc1)

import numpy as np
cimport numpy as np

np.import_array()


def patch_match(np.ndarray[np.float32_t, ndim=3] arr0, np.ndarray[np.float32_t, ndim=3] arr1, psiz = 5, nit = 5):
    '''patch_match(np.ndarray[np.float32_t, ndim=3] arr0, np.ndarray[np.float32_t, ndim=3] arr1, psiz = 5, nit = 5)'''
    cdef int dimc0 = arr0.shape[0]
    cdef int dimy0 = arr0.shape[1]
    cdef int dimx0 = arr0.shape[2]
    cdef int dimc1 = arr1.shape[0]
    cdef int dimy1 = arr1.shape[1]
    cdef int dimx1 = arr1.shape[2]

    if dimc0 != dimc1:
        raise ValueError("Images must have the same number of channels")

    cdef np.ndarray[np.float32_t, ndim=3] arrout = np.zeros((2,dimy0,dimx0), dtype=np.float32)

    patch_match_cpp(<float*> arr0.data, <float*> arr1.data, 
        <float*> arrout.data,
        psiz, nit,
        dimx0, dimy0, dimc0, 
        dimx1, dimy1, dimc1)
    return arrout
