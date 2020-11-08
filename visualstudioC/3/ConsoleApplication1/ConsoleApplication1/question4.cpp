//函数重载2
#include "iostream"
void convertTemperature(double tempIn, char typeIn);
void convertTemperature(int tempIn, char typeIn);//记住定义重载函数，只能通过不同参数进行函数重载，而不能通过返回值进行重载+

int main() {

	//华氏温度=摄氏温度*9.0/5.0+32,注视格式自动转换问题
	double tempIn;
	int tempInt;
	char typeIn;
	std::cout << "请按以下格式【XX.X C】或【XX.X F】输入温度";//注意空格
	std::cin >> tempIn >> typeIn;//32.4 C
	std::cin.ignore(100, '\n');//忽略回车
	std::cout << '\n';
	convertTemperature(tempIn, typeIn);

	std::cout << "请按以下格式【XX.X C】或【XX.X F】输入温度";//注意空格
	std::cin >> tempInt >> typeIn;//32.4 C
	std::cin.ignore(100, '\n');//忽略回车
	std::cout << '\n';
	convertTemperature(tempInt, typeIn);
	return 0;
}

void convertTemperature(double tempIn, char typeIn) {
	const unsigned short ADD_SUBSTRACT = 32;//定义常变量，该变量无写入权，只有读权限，需要初始化
	const double RATIO = 9.0 / 5.0;
	double tempOut;
	char typeOut;
	switch (typeIn) {
	case 'c':
	case 'C':
		tempOut = tempIn * RATIO + ADD_SUBSTRACT;
		typeIn = 'C';
		typeOut = 'F';
		break;
	case 'f':
	case 'F':
		tempOut = (tempIn - ADD_SUBSTRACT) / RATIO;
		typeIn = 'F';
		typeOut = 'C';
		break;
	default:
		typeOut = 'E';
		break;
	}
	if (typeOut != 'E') {
		std::cout << tempIn << typeIn << "=" << tempOut << typeOut << "\n\n";
	}
	else {
		std::cout << "输入错误！" << "\n\n";
	}
	std::cout << "输入任意字符结束" << "\n";
	std::cin.get();
}

void convertTemperature(int tempIn, char typeIn) {
	const unsigned short ADD_SUBSTRACT = 32;//定义常变量，该变量无写入权，只有读权限，需要初始化
	const double RATIO = 9.0 / 5.0;
	int tempOut;
	char typeOut;
	switch (typeIn) {
	case 'c':
	case 'C':
		tempOut = tempIn * RATIO + ADD_SUBSTRACT;
		typeIn = 'C';
		typeOut = 'F';
		break;
	case 'f':
	case 'F':
		tempOut = (tempIn - ADD_SUBSTRACT) / RATIO;
		typeIn = 'F';
		typeOut = 'C';
		break;
	default:
		typeOut = 'E';
		break;
	}
	if (typeOut != 'E') {
		std::cout << tempIn << typeIn << "=" << tempOut << typeOut << "\n\n";
	}
	else {
		std::cout << "输入错误！" << "\n\n";
	}
	std::cout << "输入任意字符结束" << "\n";
	std::cin.get();
}