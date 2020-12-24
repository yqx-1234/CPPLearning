#include<opencv2/opencv.hpp>
#include<iostream>
using namespace cv;
int threshold_value = 127;
int threshold_max = 255;
int type_value = 2;
int type_max = 4;
Mat src, dst, gray_src;
const char* output_title = "binary_image";
void Threshold_Demo(int, void*);
int main(int argc, char** argv) {
	
	src = imread("D:/photos/2.jpg");

	if (!src.data) {
		std::cout << "could not find image...\n";
		return -1;
	}

	namedWindow("input_image", CV_WINDOW_AUTOSIZE);
	namedWindow(output_title, CV_WINDOW_AUTOSIZE);
	imshow("input_image", src);
	//cvtColor(src, gray_src, CV_BGR2GRAY);
	createTrackbar("Threshold_Value", output_title, &threshold_value, threshold_max, Threshold_Demo);
	createTrackbar("Type Value", output_title, &type_value, type_max, Threshold_Demo);
	Threshold_Demo(0, 0);
	waitKey(0);
	return 0;
}

void Threshold_Demo(int, void*) {
	cvtColor(src, gray_src, CV_BGR2GRAY);
	threshold(gray_src, dst, 0, 255, THRESH_TRIANGLE|type_value);
	imshow(output_title, dst);

}
