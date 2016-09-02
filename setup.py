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
      extra_link_args=['-L/opt/X11/lib', '-lX11',  '-lXext']
      ),
    ]

setup(
        name = "Patch Match wrapper",
    ext_modules = cythonize(extensions)
    )
