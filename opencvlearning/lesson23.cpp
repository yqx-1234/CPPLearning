#include<opencv2/opencv.hpp>
#include<iostream>
using namespace cv;
using namespace std;
Mat src, dst, map_x, map_y;
const char* OUTPUT_TITLE = "remap demo";
int index = 0;
void update_map(void);//��������ӳ��ģʽ
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

	map_x.create(src.size(), CV_32FC1);//����x�����ӳ��ͼ��Ԫ�أ�����Ϊ32(32λ)F(float)C1(һͨ����
	map_y.create(src.size(), CV_32FC1);//����y�����ӳ��ͼ��Ԫ�أ�����Ϊ32(32λ)F(float)C1(һͨ����

	int c = 0;
	while (true) {
		c = waitKey(500);//ÿ500msˢ��һ��ͼ��
		if ((char)c == 27) {
			break;
		}
		index = c % 4;//�ж�c��asciiֵ
		update_map();
		remap(src, dst, map_x, map_y, INTER_LINEAR, BORDER_CONSTANT, Scalar(0, 255, 255));
		//ͼ����ӳ�䣬x��y�����ӳ��ͼ��ֱ�Ϊmap_x, map_y��ӳ�䷽ʽΪINTER_LINEAR���߽���䷽ʽΪBORDER_CONSTANT���߽������ɫΪ0��255��255
		imshow(OUTPUT_TITLE, dst);

	}
	return 0;
}

void update_map(void) {//ͼ����ӳ�䷽ʽ����
	for (int row = 0; row < src.rows; row++) {
		for (int col = 0; col < src.cols; col++) {
			switch (index) {
			case 0://��ͼ���Сӳ��Ϊԭͼ���һ�룬����һ�벿������Ϊ��ɫ
				if (col > (src.cols*0.25) && col <= (src.cols*0.75) && row > (src.rows*0.25) && row <= (src.rows*0.75)) {
					map_x.at<float>(row, col) = 2 * (col - (src.cols*0.25));//�ұ߿��ܻ���ֱ߽������ɫ����ͼ���С��0.25��0.75�й�
					map_y.at<float>(row, col) = 2 * (row - (src.rows*0.25));
				}
				else {
					map_x.at<float>(row, col) = 0;
					map_y.at<float>(row, col) = 0;
				}
				break;

			case 1://ͼ�����ҷ�ת
				map_x.at<float>(row, col) = (src.cols-col-1);//��һ����Ϊcol��0��ʼȡֵ
				map_y.at<float>(row, col) = row;
				break;
			case 2://ͼ�����·�ת
				map_x.at<float>(row, col) = col;
				map_y.at<float>(row, col) = (src.rows-row-1);
				break;
			case 3://ͼ���������ҷ�ת
				map_x.at<float>(row, col) = (src.cols - col - 1);
				map_y.at<float>(row, col) = (src.rows - row - 1);
				break;
			}
		}
	}

}