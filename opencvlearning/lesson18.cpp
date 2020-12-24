#include<opencv2/opencv.hpp>
#include<iostream>
using namespace cv;

int main(int argc, char** argv) {
	Mat src, dst;
	src = imread("D:/photos/2.jpg");

	if (!src.data) {
		std::cout << "could not find image...\n";
		return -1;
	}
	char INPUT_WIN[] = "input image";
	char OUTPUT_WIN[] = "output image";
	namedWindow(INPUT_WIN, CV_WINDOW_AUTOSIZE);
	namedWindow(OUTPUT_WIN, CV_WINDOW_AUTOSIZE);
	imshow(INPUT_WIN, src);

	GaussianBlur(src, dst, Size(3, 3), 0, 0);
	Mat gray_src;
	cvtColor(dst, gray_src, CV_BGR2GRAY);
	imshow("gray_image", gray_src);

	Mat xgrad, ygrad;
	Scharr(gray_src, xgrad, CV_16S, 1, 0);
	Scharr(gray_src, ygrad, CV_16S, 0, 1);
	//Sobel(gray_src,xgrad, CV_16S, 1, 0, 3);
	//Sobel(gray_src, ygrad, CV_16S, 0, 1, 3);
	convertScaleAbs(xgrad, xgrad);//取绝对值，将负数变为正数
	convertScaleAbs(ygrad, ygrad);//取绝对值，将负数变为正数

	imshow("xgrad", xgrad);
	imshow("ygrad", ygrad);

	Mat xygrad=Mat(xgrad.size(),xgrad.type());
	printf("type is %d", xgrad.type());
	int width = xgrad.cols;
	int height = ygrad.rows;
	for (int row = 0; row < height; row++) {
		for (int col = 0; col < width; col++) {
			int xg = xgrad.at<uchar>(row, col);
			int yg = ygrad.at<uchar>(row, col);
			int xy = xg +yg;
				xygrad.at<uchar>(row, col) = saturate_cast<uchar>(xy);
		}
	}
		//addWeighted(xgrad, 0.5, ygrad, 0.5, 0, xygrad);//两图相加
	imshow("Final result", xygrad);
	waitKey(0);
	return 0;

}