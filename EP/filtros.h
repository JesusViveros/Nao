#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
using namespace cv;

int Max_value(Vec3b val[],int a){
	int res=0;

    for(int i = 0; i < 9; i++)
	    if(res<val[i][a])
		    res=val[i][a];
    return res;
}

int Min_value(Vec3b val[],int a){
	int res=255;

    for(int i=0;i<9;i++)
	    if(res>val[i][a])
		    res=val[i][a];
    return res;
}

Mat Max_Min(Mat image,int b){
	Mat maxmin_image;

	Vec3b temp[9];
	maxmin_image = image.clone();

	for(int y=1;y<image.rows-1;y++){
		for(int x=1;x<image.cols-1;x++){
			int a=0;
			for(int i=0;i<3;i++)
				for(int j=0;j<3;j++){
					temp[a]=image.at<Vec3b>(Point(x+i-1,y+j-1));
					a++;
				}
			Vec3b res;
			if(b==0){
				res[0]=Max_value(temp,0);
				res[1]=Max_value(temp,1);
				res[2]=Max_value(temp,2);
			}else{
				res[0]=Min_value(temp,0);
				res[1]=Min_value(temp,1);
				res[2]=Min_value(temp,2);
			}
			maxmin_image.at<Vec3b>(Point(x,y))=res;
		}
	}	
	return maxmin_image;
}

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

Mat Gauss_p(Mat image){
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

Mat Media(Mat image){
	Mat media_image;

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
	return media_image;
}

int Prom(Vec3b val[],int a){
	float res=0;

    for(int i=0;i<9;i++)
        res=res+(float)val[i][a];
    res=res/9;
    return (int)res;
}
 
Mat Mediana(Mat image){
	Mat mediana_image;

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
			res[0]=Prom(temp,0);
			res[1]=Prom(temp,1);
			res[2]=Prom(temp,2);
			mediana_image.at<Vec3b>(Point(x,y))=res;
		}
	}
	return mediana_image;
}