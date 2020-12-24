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
	//�ϲ���
	pyrUp(src, dst, Size(src.cols * 2, src.rows * 2));
	imshow("ZOOM_IN", dst);

	//������
	pyrDown(src, dst, Size(src.cols / 2, src.rows / 2));
	imshow("ZOOM_OUT", dst);
	//��˹��ͬ(DOG)
	//��Դͼ��ҶȻ���Ȼ������θ�˹ģ����Ȼ��������ɵõ�ͼ������
	Mat g1, g2;
	Mat gray_src,dogImg;
	cvtColor(src, gray_src, CV_BGR2GRAY);
	GaussianBlur(gray_src,g1,Size(5,5),0.0);
	GaussianBlur(g1, g2, Size(5, 5), 0, 0);
	subtract(g1, g2, dogImg, Mat());
	normalize(dogImg, dogImg, 255, 0, NORM_MINMAX);//��ͼ�������ֵ���������䵽0-255���ؿռ�
	imshow("DOG Image", dogImg);//�õ���ͼ�������


	waitKey(0);
	return 0;
}