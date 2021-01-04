#include<opencv2/opencv.hpp>
#include<iostream>
#include<math.h>
using namespace cv;
using namespace std;

int main(int argc, char** argv) {
	Mat src, dst, map_x, map_y;
	src = imread("D:/photos/2.jpg");
	if (!src.data) {
		printf("Could not load image...\n");
		return 1;
	}
	char input_win[] = "input image";
	const char* OUTPUT_TITLE = "histogram demo";
	namedWindow(input_win, CV_WINDOW_AUTOSIZE);
	namedWindow(OUTPUT_TITLE, CV_WINDOW_AUTOSIZE);
	imshow(input_win, src);

	//��ͨ����ʾ
	vector<Mat> bgr_planes;
	split(src, bgr_planes);//��srcͼ�����ͨ��������bgr_planesͼ��������
	//imshow("single channel demo",bgr_planes[0]);

	//����ֱ��ͼ
	int histSize = 256;
	float range[] = { 0,256 };
	const float *histRanges = { range };
	Mat b_hist, g_hist, r_hist;
	calcHist(&bgr_planes[0], 1, 0, Mat(), b_hist, 1, &histSize, &histRanges, true, false);
	//����ͼ��Ϊbgr_planes[0]������ͼ�����Ϊ1����ͼ��ĵ�һͨ������ֱ��ͼͳ�ƣ���Ĥ����ΪMat()����������Ĥ�����ͼ��Ϊb_hist,��Ҫͳ��ֱ��ͼ����Ϊ1ά��Ϊ1�����ֵ���������binsΪ255��ͳ����������Ϊ0-255�����й�һ���������ۼӼ�������ֵ�ø���
	calcHist(&bgr_planes[1], 1, 0, Mat(), g_hist, 1, &histSize, &histRanges, true, false);
	calcHist(&bgr_planes[2], 1, 0, Mat(), r_hist, 1, &histSize, &histRanges, true, false);

	//��һ��
	int hist_h = 400;
	int hist_w = 512;
	int bin_w = hist_w / histSize;//ֱ��ͼÿһ������Ϊ�ܿ�ȳ���bins�ܸ���
	Mat histImage(hist_h, hist_w, CV_8UC3, Scalar(0, 0, 0));//����ͼ���Ϊhist_h����Ϊhist_w
	normalize(b_hist, b_hist, 0, hist_h, NORM_MINMAX, -1, Mat());//��һ��
	normalize(g_hist, g_hist, 0, hist_h, NORM_MINMAX, -1, Mat());
	normalize(r_hist, r_hist, 0, hist_h, NORM_MINMAX, -1, Mat());

	//������ͨ��ֱ��ͼ,����ͼ
	for (int i = 1; i < histSize; i++) {
		line(histImage, Point((i - 1)*bin_w, hist_h - cvRound(b_hist.at<float>(i - 1))),
			Point((i)*bin_w, hist_h - cvRound(b_hist.at<float>(i))), Scalar(255, 0, 0), 2, LINE_AA);//bͨ��
		line(histImage, Point((i - 1)*bin_w, hist_h - cvRound(g_hist.at<float>(i - 1))),
			Point((i)*bin_w, hist_h - cvRound(g_hist.at<float>(i))), Scalar(0, 255, 0), 2, LINE_AA);//gͨ��
		line(histImage, Point((i - 1)*bin_w, hist_h - cvRound(r_hist.at<float>(i - 1))),
			Point((i)*bin_w, hist_h - cvRound(r_hist.at<float>(i))), Scalar(0, 0, 255), 2, LINE_AA);//rͨ��
	}
	imshow(OUTPUT_TITLE, histImage);
	waitKey(0);
	return 0;
}