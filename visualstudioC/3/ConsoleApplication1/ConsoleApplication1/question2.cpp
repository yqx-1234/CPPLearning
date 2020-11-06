//温度转换
#include "iostream"
int main() {

//华氏温度=摄氏温度*9.0/5.0+32,注视格式自动转换问题
	const unsigned short ADD_SUBSTRACT = 32;//定义常变量，该变量无写入权，只有读权限，需要初始化
	const double RATIO = 9.0 / 5.0;
	double tempIn, tempOut;
	char typeIn, typeOut;
	std::cout << "请按以下格式【XX.X C】或【XX.X F】输入温度";//注意空格
	std::cin >> tempIn >> typeIn;//32.4 C
	std::cin.ignore(100, '\n');//忽略回车
	std::cout << '\n';





}