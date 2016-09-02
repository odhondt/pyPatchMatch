from distutils.core import setup
from distutils.extension import Extension
from Cython.Build import cythonize
import numpy as np

# OSX only
from os import environ
# environ["CC"] = "g++-4.9"
# environ["CXX"] = "g++-4.9"

extensions = [
    Extension("patchmatch",
      sources=["patchmatch.pyx"],
      language="c++",
      include_dirs = [np.get_include(), "/opt/X11/include"],
      # Uncomment if extension relies on openmp
# -I/opt/X11/include -L/opt/X11/lib -lX11  -Dcimg_use_xshm -lXext -Dcimg_use_xrandr -lXrandr -Dcimg_use_jpeg -ljpeg -Dcimg_use_tiff -ltiff -Dcimg_use_fftw3 -lfftw3
      #extra_compile_args=['-Dcimg_use_xshm -Dcimg_use_xrandr -Dcimg_use_tiff -Dcimg_use_jpeg '],
      #extra_link_args=['-L/opt/X11/lib -lX11  -lXext -lXrandr -ljpeg -ltiff -lfftw3']
      extra_link_args=['-L/opt/X11/lib', '-lX11',  '-lXext']
      #extra_compile_args=['-L/opt/X11/lib -lX11 -lXext']
      #extra_compile_args=['-fopenmp'],
      #extra_link_args=['-lgomp']
      ),
    ]

setup(
        name = "Patch Match wrapper",
    ext_modules = cythonize(extensions)
    )
