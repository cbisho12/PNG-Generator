
OPENCV_LIBPATH=/home/chris/Documents/OpenCV/build/lib
OPENCV_LIBS= -lopencv_core -lopencv_imgproc -lopencv_highgui 
CUDA_INCLUDEPATH=/usr/local/cuda-8.0/include

student: main.o Makefile colors.h
	 g++ -O3 -o main main.o -L $(OPENCV_LIBPATH) $(OPENCV_LIBS) 
main.o: main.cpp Makefile colors.h 
	g++ -O3 -c main.cpp  -I $(CUDA_INCLUDEPATH)

clean:
	rm -f *.o *.png main
