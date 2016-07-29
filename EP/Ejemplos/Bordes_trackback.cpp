#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
using namespace cv;

int rango=100;
Mat image;

Mat Bordes(Mat image,int rango){
	Mat b_image=image.clone();

	Vec3b ant=image.at<Vec3b>(Point(0,0));
	for(int y=0;y<image.rows;y++){
		for(int x=1;x<image.cols;x++){
			Vec3b temp=image.at<Vec3b>(Point(x,y));
			if(temp[0]>(ant[0]+rango)||temp[1]>(ant[1]+rango)||temp[2]>(ant[2]+rango)||(temp[0]+rango)<ant[0]||(temp[1]+rango)<ant[1]||(temp[2]+rango)<ant[2]){
				temp[0]=0;
				temp[1]=0;
				temp[2]=0;				
			}
			else{
				temp[0]=255;
				temp[1]=255;
				temp[2]=255;
			}
			b_image.at<Vec3b>(Point(x-1,y))=temp;
			b_image.at<Vec3b>(Point(x,y))=temp;
			ant=image.at<Vec3b>(Point(x,y));
		}
	}

	ant=image.at<Vec3b>(Point(0,0));
	for(int x=0;x<image.cols;x++){
		for(int y=1;y<image.rows;y++){
			Vec3b temp=image.at<Vec3b>(Point(x,y));
			bool band=false;
			if(temp[0]>(ant[0]+rango)||temp[1]>(ant[1]+rango)||temp[2]>(ant[2]+rango)||(temp[0]+rango)<ant[0]||(temp[1]+rango)<ant[1]||(temp[2]+rango)<ant[2]){
				temp[0]=0;
				temp[1]=0;
				temp[2]=0;
				band=true;
			}else
				band=false;
			if(band==true){
				b_image.at<Vec3b>(Point(x,y-1))=temp;
				b_image.at<Vec3b>(Point(x,y))=temp;
			}
			ant=image.at<Vec3b>(Point(x,y));
		}
	}

	return b_image;
}

void Thresh( int, void* ){
	Mat b_image=Bordes(image,rango);
	imshow("Imagen Bordes",b_image);
	imshow("Imagen Original",image);
}

int main(){
	image=imread("a1.png", CV_LOAD_IMAGE_COLOR);

	namedWindow("Imagen Original",CV_WINDOW_AUTOSIZE);
	namedWindow("Imagen Bordes",CV_WINDOW_AUTOSIZE);
	
	createTrackbar("Valor:","Imagen Bordes",&rango,255,Thresh);

	Thresh(0,0);

	while(true){
    	int c=waitKey(20);
	    if((char)c==27)
			break;
	}
	
	return 0;
}