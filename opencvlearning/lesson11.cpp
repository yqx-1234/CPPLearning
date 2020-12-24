#include <opencv2/opencv.hpp> 
#include <iostream> 
using namespace cv;

int main(int argc, char** argv) {
	Mat src, dst;
	src = imread("D:/photos/2.jpg");
	if (!src.data) {
		printf("could not load image...\n");
		return -1;
	}
	namedWindow("input image", CV_WINDOW_AUTOSIZE);
	imshow("input image", src);

	//medianBlur(src, dst, 3);//��ֵģ��
	//imshow("medianBlur image", dst);//ȥ��������Ч���Ϻ�
	
	bilateralFilter(src, dst, 15, 100, 5);//˫��ģ��
	namedWindow("BiBlur Filter Result", CV_WINDOW_AUTOSIZE);
	imshow("BiBlur Filter Result", dst);//˫��ģ��

	Mat resultImg;
	Mat kernel = (Mat_<int>(3, 3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);//��Ĥ���ӣ���߶Աȶ�
	filter2D(dst, resultImg, -1, kernel, Point(-1, -1), 0);
	imshow("Final Result", resultImg);//˫��ģ�����������ͼ��Աȶ�
	
	waitKey(0);
	return 0;

}