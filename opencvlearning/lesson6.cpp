#include<opencv2/opencv.hpp>
#include<iostream>
using namespace cv;

int main(int argc, char** argv) {
	Mat src1,src2,dst;
	src1 = imread("D:/photos/2.jpg");
	src2 = imread("D:/photos/111.png");
	if (!src1.data&&!src2.data) {
		std::cout << "could not find image...\n";
		return -1;
	}
	double alpha = 0.5;
	if (src1.rows == src2.rows&&src1.cols == src2.cols&&src1.type() == src2.type()) {
		addWeighted(src1, alpha, src2, 1.0 - alpha, 0.0, dst);//图像混合，线性叠加
		//add(src1, src2,dst,Mat());直接相加
		//multiply(src1, scr2, dst, 1.0);像素相乘

namedWindow("blend demo", CV_WINDOW_AUTOSIZE);
	imshow("belnd demo", dst);
	}
	else {
		printf("could not blend images,the size of images is different!\n");
		return -2;
	}
	waitKey(0);

	return 0;
}