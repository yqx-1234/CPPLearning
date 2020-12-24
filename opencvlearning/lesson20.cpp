#include<opencv2/opencv.hpp>
#include<iostream>
#include<math.h>

using namespace cv;
Mat src, dst;
Mat gray_src;
int t1_value = 50;
int max_value = 255;
char output_title[] = "Canny_image";
void Canny_Demo(int, void*);
int main(int argc, char** argv) {
	
	src = imread("D:/photos/2.jpg");
	if (!src.data) {
		printf("could not find image\n");
	}
	char input_title[] = "input_image";
	namedWindow(input_title, CV_WINDOW_AUTOSIZE);
	namedWindow(output_title, CV_WINDOW_AUTOSIZE);
	imshow(input_title, src);

	
	cvtColor(src, gray_src, CV_BGR2GRAY);
	createTrackbar("Threshold Value", output_title, &t1_value, max_value, Canny_Demo);

	waitKey(0);
	return 0;
}

void Canny_Demo(int, void*) {
	Mat edge_output;
	blur(gray_src, gray_src, Size(3, 3), Point(-1, -1), BORDER_DEFAULT);
	Canny(gray_src, edge_output, t1_value, t1_value * 2, 3, false);
	//dst.create(src.size(), src.type());
	//Mat mask1 = Mat::zeros(src.size(), src.type());
	//src.copyTo(dst, edge_output);//将edge_output非零像素点位置处的src的像素拷贝到dst中，形成边缘为是彩色效果
	//若edge_output为零像素点位置处的src的像素则不拷贝到dst中
	imshow(output_title, ~edge_output);
}