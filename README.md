# pyPatchMatch

A simple python wrapper for the PatchMatch algorithm using the CImg library.

##Build

run the `cl_build` script or copy/paste its content into a terminal. Then copy the `.so` in a folder belonging to your python path.

##Usage

```python
from patchmatch import patch_match
res = patch_match(img0, img1, psiz, nit)
```
`img0` and `img1` are color images (if using grayscale images, you need to add an extra axis `img0 = img0[:,:,np.newaxis]`).

`psiz`: patch size

`nit`: number of iterations

## Important

CImg stores images with a different memory layout than scipy.ndimage.

If the shapes of your numpy arrays (say `img0` and `img1`) are `[nrows,ncols,nchannel]` then you should pass 

```python
cimg0 = np.rollaxis(img0,2).copy()
```

(resp. `cimg1`) to the `patch_match()` function.

Oh, and you need cython. But who doesn't?

The documentation of the c++ plugin is available at:
https://github.com/odhondt/PatchMatch_plugin
