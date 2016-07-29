#include <iostream>
#include <math.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
using namespace std;
using namespace cv;

Vec3b Gauss(Vec3b v[9]){
	Vec3b temp;
	int a=1,c=1,x=0,b=1;
	float fx,t[3],total=0;

	t[0]=0;
	t[1]=0;
	t[2]=0;
	fx=a*exp(-1*pow((x-b),2)/pow(c,2));

	for(int i=0;i<9;i++){
		t[0]=t[0]+v[i][0]*fx;
		t[1]=t[1]+v[i][1]*fx;
		t[2]=t[2]+v[i][2]*fx;
		total=total+fx;
	}
	temp[0]=(int)(t[0]/total);
	temp[1]=(int)(t[1]/total);
	temp[2]=(int)(t[2]/total);
	return temp;
}

Mat Filtro(Mat image){
	Mat c_image=image.clone();

	for(int y=1;y<image.rows-1;y++){
		for(int x=1;x<image.cols-1;x++){
			int a=0;
			Vec3b color[9];
			
			for(int i=0;i<3;i++){
				for(int j=0;j<3;j++){
					color[a] = image.at<Vec3b>(Point(x+i-1,y+j-1));
						a++;
				}
				c_image.at<Vec3b>(Point(x,y))=Gauss(color);
			}
		}
	}
	return c_image;
}

int main(){
	Mat image=imread("a1.png", CV_LOAD_IMAGE_COLOR);
	Mat c_image=Filtro(image);

	namedWindow("Imagen Filtrada",CV_WINDOW_AUTOSIZE);
	namedWindow("Imagen Original",CV_WINDOW_AUTOSIZE);
	
	imshow("Imagen Filtrada", c_image);
	imshow("Imagen Original", image);
	waitKey();
	
	return 0;
}