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

	//分通道显示
	vector<Mat> bgr_planes;
	split(src, bgr_planes);//对src图像进行通道分离至bgr_planes图像数组中
	//imshow("single channel demo",bgr_planes[0]);

	//计算直方图
	int histSize = 256;
	float range[] = { 0,256 };
	const float *histRanges = { range };
	Mat b_hist, g_hist, r_hist;
	calcHist(&bgr_planes[0], 1, 0, Mat(), b_hist, 1, &histSize, &histRanges, true, false);
	//输入图像为bgr_planes[0]，输入图像个数为1，对图像的第一通道进行直方图统计，掩膜设置为Mat()即不设置掩膜，输出图像为b_hist,需要统计直方图个数为1维数为1，划分的区间数即bins为255，统计像素区间为0-255，进行归一化处理，不累加计算像素值得个数
	calcHist(&bgr_planes[1], 1, 0, Mat(), g_hist, 1, &histSize, &histRanges, true, false);
	calcHist(&bgr_planes[2], 1, 0, Mat(), r_hist, 1, &histSize, &histRanges, true, false);

	//归一化
	int hist_h = 400;
	int hist_w = 512;
	int bin_w = hist_w / histSize;//直方图每一区间宽度为总宽度除以bins总个数
	Mat histImage(hist_h, hist_w, CV_8UC3, Scalar(0, 0, 0));//定义图像高为hist_h，宽为hist_w
	normalize(b_hist, b_hist, 0, hist_h, NORM_MINMAX, -1, Mat());//归一化
	normalize(g_hist, g_hist, 0, hist_h, NORM_MINMAX, -1, Mat());
	normalize(r_hist, r_hist, 0, hist_h, NORM_MINMAX, -1, Mat());

	//做出各通道直方图,折线图
	for (int i = 1; i < histSize; i++) {
		line(histImage, Point((i - 1)*bin_w, hist_h - cvRound(b_hist.at<float>(i - 1))),
			Point((i)*bin_w, hist_h - cvRound(b_hist.at<float>(i))), Scalar(255, 0, 0), 2, LINE_AA);//b通道
		line(histImage, Point((i - 1)*bin_w, hist_h - cvRound(g_hist.at<float>(i - 1))),
			Point((i)*bin_w, hist_h - cvRound(g_hist.at<float>(i))), Scalar(0, 255, 0), 2, LINE_AA);//g通道
		line(histImage, Point((i - 1)*bin_w, hist_h - cvRound(r_hist.at<float>(i - 1))),
			Point((i)*bin_w, hist_h - cvRound(r_hist.at<float>(i))), Scalar(0, 0, 255), 2, LINE_AA);//r通道
	}
	imshow(OUTPUT_TITLE, histImage);
	waitKey(0);
	return 0;
}