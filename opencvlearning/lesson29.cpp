//轮廓发现：通过cv::fingContoursAPI查找轮廓，通过cv::drawContours绘制轮廓
#include <opencv2/opencv.hpp>
#include <opencv2/dnn.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int threshold_value = 100;
int threshold_max = 255;
RNG rng;
const char* output_win = "Demo_Contour";
void Demo_Contours(int, void*);
Mat src,dst;
int main(int argc, char** argv) {

	src = imread("D:/photos/45.png");
	if (src.empty()) {
		printf("could not load image...\n");
		return -1;
	}
	namedWindow("input image", CV_WINDOW_AUTOSIZE);
	namedWindow(output_win, CV_WINDOW_AUTOSIZE);
	imshow("input image", src);
	cvtColor(src, src, CV_BGR2GRAY);//灰度化图像，为Canny边缘检测做准备

	const char* trackbar_title = "threshold_value";
	createTrackbar(trackbar_title, output_win, &threshold_value, threshold_max, Demo_Contours);//动态调整Canny边缘检测的阈值
	Demo_Contours(0, 0);//使程序刚开始就有结果，与createTrackbar无关


	waitKey(0);
	return 0;
}

void Demo_Contours(int, void*) {
	Mat canny_output;
	vector<vector<Point>> contours;
	vector<Vec4i> hierachy;
	Canny(src, canny_output, threshold_value, threshold_value * 2, 3, false);//Canny边缘检测，3代表算子尺寸
	imshow("canny image", canny_output);
	findContours(canny_output, contours, hierachy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point(0, 0));
	//contours储存轮廓的点集，轮廓提取方式为RETR_TREE，轮廓表达为：CHAIN_APPROX_SIMPLE
	dst = Mat::zeros(src.size(), CV_8UC3);
	RNG rng(12345);
	for (size_t i = 0; i < contours.size(); i++) {//逐条绘制轮廓
		Scalar color = Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
		drawContours(dst, contours, i, color, 2, 8, hierachy, 0, Point(0, 0));
	}
	imshow(output_win, dst);

}