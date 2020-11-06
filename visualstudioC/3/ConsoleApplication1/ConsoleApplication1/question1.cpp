// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

//using namespace std;
int main()
{
	char answer;
	std::cout << "May I delete your comquter?!【Y/N】"<<std::endl;//不用命名区间namespace,而采用std::,对于大型程序是有好处且有必要的
	std::cin >> answer;
	switch (answer) {
	case 'Y':
	case 'y':
		std::cerr << "随便格式化硬盘是不好的行为";
		break;
	case 'N':
	case 'n':
		std::cerr << "您的选择是对的"<<std::endl;
		break;
	default:
		std::cout << "输出错误格式字符" <<std::endl;
		break;
	}
	std::cout << "输入任何字符结束程序" << std::endl;
	std::cin.ignore(100, '\n');//忽略缓冲区100个字符或遇到'\n'结束函数，或者使用std::cin.get();
	std::cin.get();
	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
