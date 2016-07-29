#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
using namespace cv;

int Mediana(Vec3b val[],int a){
	float res=0;

    for(int i=0;i<9;i++)
        res=res+(float)val[i][a];
    res=res/9;
    return (int)res;
}
 
int main(){
	Mat image, mediana_image;
	image = imread("a.jpg", CV_LOAD_IMAGE_COLOR);

	if( !image.data )
	{ return -1; }

	Vec3b temp[9];
	mediana_image = image.clone();

	for(int y=1;y<image.rows-1;y++){
		for(int x=1;x<image.cols-1;x++){
			int a=0;
			for(int i=0;i<3;i++)
				for(int j=0;j<3;j++){
					temp[a]=image.at<Vec3b>(Point(x+i-1,y+j-1));
					a++;
				}
			Vec3b res;
			res[0]=Mediana(temp,0);
			res[1]=Mediana(temp,1);
			res[2]=Mediana(temp,2);
			mediana_image.at<Vec3b>(Point(x,y))=res;
		}
	}

	namedWindow("Imagen Mediana",CV_WINDOW_AUTOSIZE);
	namedWindow("Imagen Original",CV_WINDOW_AUTOSIZE);
	
	imshow("Imagen Mediana",mediana_image);
	imshow("Imagen Original",image);
	waitKey();
	
	return 0;
}