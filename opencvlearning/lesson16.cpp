#include<opencv2/opencv.hpp>
#include<iostream>
using namespace cv;
int threshold_value = 127;
int threshold_max = 255;
int type_value = 2;
int type_max = 4;
Mat src, dst, gray_src;
const char* output_title = "Robert_X";
void Threshold_Demo(int, void*);
int main(int argc, char** argv) {

	src = imread("D:/photos/2.jpg");

	if (!src.data) {
		std::cout << "could not find image...\n";
		return -1;
	}

	namedWindow("input_image", CV_WINDOW_AUTOSIZE);
	namedWindow(output_title, CV_WINDOW_AUTOSIZE);
	imshow("input_image", src);
    //SobelX方向

	//Mat kernel_x = (Mat_<int>(3, 3) << -1, 0, 1,-2,0, 2,-1,0,1);
	//filter2D(src, dst, -1, kernel_x, Point(-1, -1), 0, 0);
	//SobelY方向
	//Mat ying;
	//Mat kernel_y = (Mat_<int>(3, 3) << -1, -2, -1, 0,0,0,1,2,1);
	//filter2D(src, ying, -1, kernel_y, Point(-1, -1), 0, 0);

	//拉普拉斯算子
	//Mat kernel_y = (Mat_<int>(3, 3) << 0, -1, 0, -1, 4, -1, 0, -1, 0);
	//filter2D(src, dst, -1, kernel_y, Point(-1, -1), 0, 0);

	//imshow("Robert_Y", dst);

	int c = 0;
	int index = 0;
	int ksize = 5;
	while (true) {
		c = waitKey(500);//隔500ms模糊一下
		if ((char)c == 27) {
			break;//按ESC退出
		}
		ksize = 4 + (index % 5) * 2 + 1;
		Mat kernel = Mat::ones(Size(ksize, ksize), CV_32F) / (float)(ksize*ksize);
		filter2D(src, dst, -1, kernel, Point(-1, -1));
		index++;
		imshow(output_title, dst);

	}
	


		waitKey(0);
	return 0;
}
