#include<opencv2/opencv.hpp>
#include<iostream>
using namespace cv;

int main(int argc, char** argv) {
	Mat src, dst;
	src = imread("E:/photoss/dog1.jpeg");

	if (!src.data) {
		std::cout << "could not find image...\n";
		return -1;
	}
	char INPUT_WIN[] = "input_image";
	char OUTPUT_WIN[] = "output_image";
	namedWindow(INPUT_WIN, CV_WINDOW_AUTOSIZE);
	imshow(INPUT_WIN, src);
	//上采样
	pyrUp(src, dst, Size(src.cols * 2, src.rows * 2));
	imshow("ZOOM_IN", dst);

	//降采样
	pyrDown(src, dst, Size(src.cols / 2, src.rows / 2));
	imshow("ZOOM_OUT", dst);
	//高斯不同(DOG)
	//对源图像灰度化，然后做多次高斯模糊，然后相减，可得到图像轮廓
	Mat g1, g2;
	Mat gray_src,dogImg;
	cvtColor(src, gray_src, CV_BGR2GRAY);
	GaussianBlur(gray_src,g1,Size(5,5),0.0);
	GaussianBlur(g1, g2, Size(5, 5), 0, 0);
	subtract(g1, g2, dogImg, Mat());
	normalize(dogImg, dogImg, 255, 0, NORM_MINMAX);//将图像的像素值按比例分配到0-255像素空间
	imshow("DOG Image", dogImg);//得到了图像的轮廓


	waitKey(0);
	return 0;
}