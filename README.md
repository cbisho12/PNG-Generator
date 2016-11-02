# PNG-Generator
Creates PNG files from the RGB codes using the list of colors on Wikipedia for common HTML colors

This c++ code creates PNG files of size NxM for a large list of colors that can be found in colors.h.
These PNG files can then be used as sawtches to demontrate those colors. The names of the PNG files
are the colors themselves.

The colors.h is credited to :
https://github.com/codebrainz/color-names

The OpenCV library is required to run this code and can be found here:
http://opencv.org/

and can be installed with the command line by going into the openCV dir and:

mkdir build
cd build
cmake ..
make

The cuda toolkit is also required to run this code and can be found here:
https://developer.nvidia.com/cuda-toolkit
