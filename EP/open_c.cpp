#include "filtros.h"
#include <iostream>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
using namespace std;
using namespace cv;

int main(){
	Mat image,final;
	image=imread("a2.jpg",CV_LOAD_IMAGE_COLOR);
	//final=Media(image);
	//final=Mediana(final);
	final=Max_Min(image,0);
	final=Max_Min(final,1);
	//final=Gauss_p(final);

	namedWindow("Imagen Final",CV_WINDOW_AUTOSIZE);
	namedWindow("Imagen Original",CV_WINDOW_AUTOSIZE);
	
	imshow("Imagen Final", final);
	imshow("Imagen Original", image);
	waitKey();

	return 0;
}