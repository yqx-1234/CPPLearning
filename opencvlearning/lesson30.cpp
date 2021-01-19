#include <opencv2/opencv.hpp>
#include <opencv2/dnn.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int threshold_value = 100;
int threshold_max = 255;
RNG rng(12345);
const char* output_win = "Demo_convex hull";
void threshold_callback(int, void*);
Mat src, dst,dst2,gray_src;
int main(int argc, char** argv) {

	src = imread("D:/photos/45.png");
	if (src.empty()) {
		printf("could not load image...\n");
		return -1;
	}
	namedWindow("input image", CV_WINDOW_AUTOSIZE);
	namedWindow(output_win, CV_WINDOW_AUTOSIZE);
	const char* trackbar_label = "threshold:";
	imshow("input image", src);
	cvtColor(src, gray_src, CV_BGR2GRAY);
	blur(gray_src, gray_src, Size(3, 3), Point(-1, -1), BORDER_DEFAULT);//均值模糊进行降噪处理
	imshow("src_gray", gray_src);
	createTrackbar(trackbar_label, output_win, &threshold_value, threshold_max, threshold_callback);
	threshold_callback(0, 0);
	waitKey(0);
	return 0;
}
void threshold_callback(int, void*) {
	Mat bin_output;
	vector<vector<Point>> contours;
	vector<Vec4i> hierachy;
	threshold(gray_src, bin_output, threshold_value, threshold_max, THRESH_BINARY);
	findContours(bin_output, contours, hierachy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point(0, 0));
	vector<vector<Point>> convexs(contours.size());
	dst = Mat::zeros(src.size(), CV_8UC3);
	dst2 = Mat::zeros(src.size(), CV_8UC3);
	for (size_t i = 0; i < contours.size(); i++) {
		Scalar color = Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
		convexHull(contours[i], convexs[i], false, true);
		//drawContours(dst, contours, i, color, 2, 8, hierachy, 0, Point(0, 0));
	}
	vector<Vec4i> empty(0);
		for (size_t k = 0; k < contours.size(); k++) {
		Scalar color = Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
		drawContours(dst2, contours, k, color, 2, LINE_8, hierachy,1, Point(0, 0));
		drawContours(dst, convexs, k, color, 2, LINE_8, empty, 0, Point(0, 0));//注意此时hieracgy选项填Mat()
	}
	imshow(output_win, dst);
	imshow("contours_Demo", dst2);
	return;		
}