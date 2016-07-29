#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
 using namespace cv;

void Burbuja(Vec3b val[],int a){
    int temp;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
        	if(val[j][a]>val[j+1][a]){
        		temp=val[j][a];
        		val[j][a]=val[j+1][a];
        		val[j+1][a]=temp;
        	}
        }
    }
}

int main(){
	Mat image, media_image;
	image = imread("a.jpg", CV_LOAD_IMAGE_COLOR);

	if( !image.data )
	{ return -1; }

	Vec3b temp[9];
	media_image = image.clone();

	for(int y=1;y<image.rows-1;y++){
		for(int x=1;x<image.cols-1;x++){

			int a=0;
			for(int i=0;i<3;i++)
				for(int j=0;j<3;j++){
					temp[a]=image.at<Vec3b>(Point(x+i-1,y+j-1));
					a++;
				}
			Burbuja(temp,0);
			Burbuja(temp,1);
			Burbuja(temp,2);
			media_image.at<Vec3b>(Point(x,y))=temp[4];
		}
	}

	namedWindow("Imagen Media",CV_WINDOW_AUTOSIZE);
	namedWindow("Imagen Original",CV_WINDOW_AUTOSIZE);

	imshow("Imagen Media",media_image);
	imshow("Imagen Original",image);
	waitKey();

	return 0;
}