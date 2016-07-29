#include <iostream>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
using namespace std;
using namespace cv;

int Min_value(Vec3b val[],int a){
	int res=255;

    for(int i=0;i<9;i++)
	    if(res>val[i][a])
		    res=val[i][a];
    return res;
}
 
int main(){
	Mat image, min_image;
	image=imread("a.jpg",CV_LOAD_IMAGE_COLOR);

	if(!image.data){
		return -1;
	}

	Vec3b temp[9];
	min_image = image.clone();

	for(int y=1;y<image.rows-1;y++){
		for(int x=1;x<image.cols-1;x++){
			int a=0;
			for(int i=0;i<3;i++)
				for(int j=0;j<3;j++){
					temp[a]=image.at<Vec3b>(Point(x+i-1,y+j-1));
					a++;
				}
			Vec3b res;
			res[0]=Min_value(temp,0);
			res[1]=Min_value(temp,1);
			res[2]=Min_value(temp,2);
			min_image.at<Vec3b>(Point(x,y))=res;
		}
	}

	namedWindow("Imagen Minimo",CV_WINDOW_AUTOSIZE);
	namedWindow("Imagen Original",CV_WINDOW_AUTOSIZE);
	
	imshow("Imagen Minimo",min_image);
	imshow("Imagen Original",image);
	waitKey();
	
	return 0;
}