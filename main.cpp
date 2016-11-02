//Make PNG Files 

#include <iostream>
#include <string>
#include <stdio.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include "colors.h"
#include <iomanip>
#include <cuda.h>
#include <cuda_runtime.h>




void writeImage(const std::string& output_file, uchar4* data_ptr, size_t numRows,size_t numCols) {
  cv::Mat output(numRows, numCols, CV_8UC4, (void*)data_ptr);
  cv::Mat imageOutputBGR;
  cv::cvtColor(output, imageOutputBGR, CV_RGBA2BGR);
  cv::imwrite(output_file.c_str(), imageOutputBGR);
}


void generateImage(size_t numRows,size_t numCols,uchar4* data_ptr,int iter) {
  unsigned char red ,blue,green;
  red = color_data[iter].rgb.r;
  green = color_data[iter].rgb.g;
  blue = color_data[iter].rgb.b;
  uchar4 mypixel = make_uchar4(red, green, blue, 255);
  for (int r = 0; r < numRows; ++r) {
    for (int c = 0; c <numCols; ++c) {
     data_ptr[c + r*numCols] = mypixel;
    }
  }
}

int main(int argc, char **argv) {
  size_t numRows=34,numCols=34;
  uchar4 *rgbaImage = new uchar4[numRows * numCols];

 for (int itt = 0; itt < COLOR_NAMES_MAX; itt++) {
    std::string output_file;
    output_file = color_data[itt].name;
    output_file.append(".png");
    generateImage(numRows,numCols,rgbaImage,itt);
    writeImage(output_file,rgbaImage,numRows, numCols);

  }
  delete[] rgbaImage;
  return 0;
}


