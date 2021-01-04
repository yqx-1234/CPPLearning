#include<opencv2/opencv.hpp>
#include<iostream>
using namespace cv;
using namespace std;
Mat src, dst, map_x, map_y;
const char* OUTPUT_TITLE = "remap demo";
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
	imshow(input_win, src);

	map_x.create(src.size(), CV_32FC1);//创建x方向的映射图像元素，类型为32(32位)F(float)C1(一通道）
	map_y.create(src.size(), CV_32FC1);//创建y方向的映射图像元素，类型为32(32位)F(float)C1(一通道）

	int c = 0;
	while (true) {
		c = waitKey(500);//每500ms刷新一次图像
		if ((char)c == 27) {
			break;
		}
		index = c % 4;//判断c的ascii值
		update_map();
		remap(src, dst, map_x, map_y, INTER_LINEAR, BORDER_CONSTANT, Scalar(0, 255, 255));
		//图像重映射，x，y方向的映射图像分别为map_x, map_y，映射方式为INTER_LINEAR，边界填充方式为BORDER_CONSTANT，边界填充颜色为0，255，255
		imshow(OUTPUT_TITLE, dst);

	}
	return 0;
}

void update_map(void) {//图像重映射方式更新
	for (int row = 0; row < src.rows; row++) {
		for (int col = 0; col < src.cols; col++) {
			switch (index) {
			case 0://将图像大小映射为原图像的一半，超过一半部分置零为黑色
				if (col > (src.cols*0.25) && col <= (src.cols*0.75) && row > (src.rows*0.25) && row <= (src.rows*0.75)) {
					map_x.at<float>(row, col) = 2 * (col - (src.cols*0.25));//右边可能会出现边界填充颜色，与图像大小和0.25，0.75有关
					map_y.at<float>(row, col) = 2 * (row - (src.rows*0.25));
				}
				else {
					map_x.at<float>(row, col) = 0;
					map_y.at<float>(row, col) = 0;
				}
				break;

			case 1://图像左右翻转
				map_x.at<float>(row, col) = (src.cols-col-1);//减一是因为col从0开始取值
				map_y.at<float>(row, col) = row;
				break;
			case 2://图像上下翻转
				map_x.at<float>(row, col) = col;
				map_y.at<float>(row, col) = (src.rows-row-1);
				break;
			case 3://图像上下左右翻转
				map_x.at<float>(row, col) = (src.cols - col - 1);
				map_y.at<float>(row, col) = (src.rows - row - 1);
				break;
			}
		}
	}

}