#include <iostream>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
using namespace std;
using namespace cv;

int main(){
	float hist[256];

	for(int a=0;a<256;a++)
		hist[a]=0;

	Mat image=imread("a.jpg", CV_LOAD_IMAGE_GRAYSCALE);
	Mat hsv_image=image.clone();
	float total=(float)image.total();
	float L=256;

	for(int y=0;y<image.rows;y++){
		for(int x=0;x<image.cols;x++){
			int a=image.at<uchar>(y,x);
			hist[a]=hist[a]+1;
		}
	}

	for(int y=0;y<image.rows;y++){
		for(int x=0;x<image.cols;x++){
			int a=image.at<uchar>(y,x);
			int b=(int)((hist[a]/total)*(L-1));
			cout<<"b: "<<b<<endl;
		}
	}

	namedWindow("Imagen HSV",CV_WINDOW_AUTOSIZE);
	namedWindow("Imagen Original",CV_WINDOW_AUTOSIZE);
	
	imshow("Imagen HSV", hsv_image);
	imshow("Imagen Original", image);
	waitKey();
	
	return 0;
}