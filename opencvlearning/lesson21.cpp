#include<opencv2/opencv.hpp>
#include<iostream>
using namespace cv;
using namespace std;
int main(int argc, char** argv) {
	Mat src, gray_src,dst;
	src = imread("E:/photoss/12.png");

	if (!src.data) {
		std::cout << "could not find image...\n";
		return -1;
	}
	char INPUT_WIN[] = "input_image";
	char OUTPUT_WIN[] = "hough_line_detection";
	namedWindow(INPUT_WIN, CV_WINDOW_AUTOSIZE);
	namedWindow(OUTPUT_WIN, CV_WINDOW_AUTOSIZE);
	imshow(INPUT_WIN, src);

	Canny(src, gray_src, 100, 200);
	imshow("egde_image", gray_src);
	cvtColor(gray_src, dst, CV_GRAY2BGR);//将灰度图像转换成彩色图像
	
	vector<Vec4f> plines;//定义一个浮点直线数，用于存放二维直线,四个坐标点
	HoughLinesP(gray_src, plines, 1, CV_PI / 180.0, 10, 0,10);
	Scalar color = Scalar(0, 0, 255);
	Vec4f hline;
	for (size_t i = 0; i < plines.size(); i++) {//size_t可看成int类型
		 hline = plines[i];
		line(dst, Point(hline[0], hline[1]), Point(hline[2], hline[3]), color, 3, LINE_AA);
	}
	imshow(OUTPUT_WIN, dst);
	waitKey(0);
	return 0;
}