# pyPatchMatch

A simple python wrapper for the PatchMatch algorithm using the CImg library.

##Build

run the `cl_build` script or copy/paste its content into a terminal.

##Usage

```python
patch_match(np.ndarray[np.float32_t, ndim=3] arr0, np.ndarray[np.float32_t, ndim=3] arr1, psiz = 5, nit = 5)
```

`psiz`: patch size
`nit`: number of iterations

## Important

CImg stores images with a different memory layout than scipy.ndimage.

If the shapes of your numpy arrays (say `img0` and `img1`) are `[nrows,ncols,nchannel]` then you should pass 

```python
cimg0 = np.rollaxes(img0,2).copy()
```

(resp. `cimg1`) to the `patch_match()` function.

Oh, and you need cython. But who doesn't?

The documentation of the c++ plugin is available at:
https://github.com/odhondt/PatchMatch_plugin
