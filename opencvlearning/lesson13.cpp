#include<opencv2/opencv.hpp>
#include<iostream>
using namespace cv;

int main(int argc, char** argv) {
	Mat src, dst;
	src = imread("D:/photos/31.png");

	if (!src.data) {
		std::cout << "could not find image...\n";
		return -1;
	}
	char INPUT_WIN[] = "input_image";
	char OUTPUT_WIN[] = "output_image";
	namedWindow(INPUT_WIN, CV_WINDOW_AUTOSIZE);
	imshow(INPUT_WIN, src);
	
	Mat gray_src;
	cvtColor(src, gray_src, CV_BGR2GRAY);
	imshow("gray image", gray_src);

	Mat binIma;
	adaptiveThreshold(~gray_src, binIma, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 15, -2);
	imshow("binary_image", binIma);

	Mat hline = getStructuringElement(MORPH_RECT, Size(src.cols / 16, 1), Point(-1, -1));
	Mat vline = getStructuringElement(MORPH_RECT, Size(1,src.rows / 16), Point(-1, -1));
	Mat kernel= getStructuringElement(MORPH_RECT, Size(5,5 ),Point(-1, -1));

	Mat temp;
	morphologyEx(binIma, dst, CV_MOP_OPEN, kernel);//开操作
	//erode(binIma, temp, hline);
	//dilate(temp, dst, hline);
	bitwise_not(dst, dst);//背景变白色
	blur(dst, dst, Size(3, 3), Point(-1, -1));
	imshow("final_image", dst);
	waitKey(0);
	return 0;
}