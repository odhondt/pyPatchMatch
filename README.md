# pyPatchMatch
a simple python wrapper for the patch match algorithm using the CImg library.

**Important:**
CImg memory stores images with a different layout than scipy.ndimage.

If the shape of your numpy arrays (say `img0` and `img1`) is `[nrows,ncols,nchannel]` then 
you should pass `cimg0 = np.rollaxes(img0,2)` (resp. cimg1) to the `patch_match()` function.

The original documentation of the plugin is available at:
https://github.com/odhondt/PatchMatch_plugin
