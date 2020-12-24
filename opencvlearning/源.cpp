#include<opencv2/opencv.hpp>
#include<iostream>
using namespace cv;

int main(int argc, char** argv) {
	Mat  src, gray_src;
	src = imread("D:/photos/2.jpg");
	if (src.empty()) {
		std::cout << "could not load image...\n";
		return -1;
	}
	namedWindow("input", CV_WINDOW_AUTOSIZE);
	imshow("input", src);

	cvtColor(src, gray_src, CV_BGR2GRAY);
	namedWindow("output", CV_WINDOW_AUTOSIZE);
	//imshow("output", gray_src);
	int height = gray_src.rows;
	int width = gray_src.cols;
	for (int row = 0; row < height; row++) {
		for (int col = 0; col < width; col++) {
			int gray = gray_src.at<uchar>(row, col);
			gray_src.at<uchar>(row, col) = 255 - gray;
		}
	}
	Mat dst;
	dst.create(src.size(),src.type());
	height = src.rows;
	width = src.cols;
	int nc = src.channels();
	
	for (int row = 0; row < height; row++) {
		for (int col = 0; col < width; col++) {
			if (nc == 1) {
				int gray = gray_src.at<uchar>(row, col);
				gray_src.at<uchar>(row, col) = 255 - gray;
			}
			else if (nc == 3) {
				int b=src.at<Vec3b>(row, col)[0];
				int g = src.at<Vec3b>(row, col)[1];
				int r = src.at<Vec3b>(row, col)[0];
				dst.at<Vec3b>(row, col)[0]=255-b;
				dst.at<Vec3b>(row, col)[1] = 255 - g;
				dst.at<Vec3b>(row, col)[2] = 255 - r;
				gray_src.at<uchar>(row, col) = min(r, min(b, g));
			}
		}
	}
	imshow("output23", gray_src);
	bitwise_not(src, dst);

	imshow("output", dst);
	waitKey(0);
	return 0
		;
}