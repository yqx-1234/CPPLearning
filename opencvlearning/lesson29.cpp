//�������֣�ͨ��cv::fingContoursAPI����������ͨ��cv::drawContours��������
#include <opencv2/opencv.hpp>
#include <opencv2/dnn.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int threshold_value = 100;
int threshold_max = 255;
RNG rng;
const char* output_win = "Demo_Contour";
void Demo_Contours(int, void*);
Mat src,dst;
int main(int argc, char** argv) {

	src = imread("D:/photos/45.png");
	if (src.empty()) {
		printf("could not load image...\n");
		return -1;
	}
	namedWindow("input image", CV_WINDOW_AUTOSIZE);
	namedWindow(output_win, CV_WINDOW_AUTOSIZE);
	imshow("input image", src);
	cvtColor(src, src, CV_BGR2GRAY);//�ҶȻ�ͼ��ΪCanny��Ե�����׼��

	const char* trackbar_title = "threshold_value";
	createTrackbar(trackbar_title, output_win, &threshold_value, threshold_max, Demo_Contours);//��̬����Canny��Ե������ֵ
	Demo_Contours(0, 0);//ʹ����տ�ʼ���н������createTrackbar�޹�


	waitKey(0);
	return 0;
}

void Demo_Contours(int, void*) {
	Mat canny_output;
	vector<vector<Point>> contours;
	vector<Vec4i> hierachy;
	Canny(src, canny_output, threshold_value, threshold_value * 2, 3, false);//Canny��Ե��⣬3�������ӳߴ�
	imshow("canny image", canny_output);
	findContours(canny_output, contours, hierachy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point(0, 0));
	//contours���������ĵ㼯��������ȡ��ʽΪRETR_TREE����������Ϊ��CHAIN_APPROX_SIMPLE
	dst = Mat::zeros(src.size(), CV_8UC3);
	RNG rng(12345);
	for (size_t i = 0; i < contours.size(); i++) {//������������
		Scalar color = Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
		drawContours(dst, contours, i, color, 2, 8, hierachy, 0, Point(0, 0));
	}
	imshow(output_win, dst);

}