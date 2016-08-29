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
      # include_dirs = [np.get_include(), "./include"],
      # Uncomment if extension relies on openmp
      extra_compile_args=['-fopenmp'],
      extra_link_args=['-lgomp']
      ),
    ]

setup(
        name = "Patch Match wrapper",
    ext_modules = cythonize(extensions)
    )
