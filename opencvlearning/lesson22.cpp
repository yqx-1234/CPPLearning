#include<opencv2/opencv.hpp>
#include<iostream>
using namespace cv;
using namespace std;
int main(int argc, char** argv) {
	Mat src, dst;
	src = imread("E:/photoss/1243.jpg");

	if (!src.data) {
		std::cout << "could not find image...\n";
		return -1;
	}
	char INPUT_WIN[] = "input_image";
	char OUTPUT_WIN[] = "hough_circle_demo";
	namedWindow(INPUT_WIN, CV_WINDOW_AUTOSIZE);
	//namedWindow(output_title, CV_WINDOW_AUTOSIZE);
	imshow(INPUT_WIN, src);

	//ÖÐÖµÂË²¨
	Mat src_gray;
	Mat moutput;
	medianBlur(src, moutput, 3);
	imshow("medianblur", moutput);
	cvtColor(moutput, moutput, CV_BGR2GRAY);//ÏÈÂË²¨ÔÙ×ª»»»Ò¶È£¬×¢ÒâË³Ðò
	
	//»ô·òÔ²±ä»»
	vector<Vec3f>pcircles;
	HoughCircles(moutput, pcircles, CV_HOUGH_GRADIENT, 1, 10, 100, 50,20, 80);
	src.copyTo(dst);
	for (size_t i = 0; i < pcircles.size(); i++) {
		Vec3f cc = pcircles[i];
		circle(dst, Point(cc[0], cc[1]), cc[2], Scalar(0, 0, 255), 2, LINE_AA);
		circle(dst, Point(cc[0], cc[1]), 2, Scalar(0, 0, 255), 2, LINE_AA);
	}
	imshow(OUTPUT_WIN, dst);

	waitKey(0);
	return 0;
}