#include<opencv2/opencv.hpp>
#include<iostream>
using namespace cv;
using namespace std;
Mat src, dst, map_x, map_y;
const char* OUTPUT_TITLE = "equalizeHist demo";
int index = 0;
void update_map(void);//更新像素映射模式
int main(int argc, char** argv) {
	src = imread("D:/photos/2.jpg");
	if (!src.data) {
		printf("Could not load image...\n");
		return 1;
	}
	char input_win[] = "input image";
	namedWindow(input_win, CV_WINDOW_AUTOSIZE);
	namedWindow(OUTPUT_TITLE, CV_WINDOW_AUTOSIZE);
	cvtColor(src, src, CV_BGR2GRAY);
	imshow(input_win, src);
	equalizeHist(src, dst);
	imshow(OUTPUT_TITLE, dst);
	waitKey(0);
	return 0;
}