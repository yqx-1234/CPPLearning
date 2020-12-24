#include<opencv2/opencv.hpp>
#include<iostream>
using namespace cv;

int main(int argc, char** argv) {
	Mat src, dst;
	src = imread("D:/photos/21.jpg");
	if (!src.data) {
		std::cout << "could not find image...\n";
		return -1;
	}
	namedWindow("input_image", CV_WINDOW_AUTOSIZE);
	imshow("input_image", src);
	char output_title[] = "morphology demo";
	namedWindow(output_title, CV_WINDOW_AUTOSIZE);
	
	Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3), Point(-1, -1));//����ṹԪ��
	morphologyEx(src, dst, CV_MOP_TOPHAT, kernel);//��ñ������ԭͼ���뿪����(�ȸ�ʴ������)�Ĳ�ֵ
	imshow(output_title, dst);
	waitKey(0);
	return 0;
}