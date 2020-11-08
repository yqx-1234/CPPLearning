// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
//#define ITEM 10
int main()
{
	const unsigned short ITEM = 10;
	int num[ITEM];
	std::cout << "请输入10个整形数据！\n\n";
	for (int i = 0; i < ITEM; i++) {
		std::cout << "请输入第" << i + 1 << "个数据";
		while (!(std::cin >> num[i])) {//输入有效性检测
			std::cin.clear();//将条件状态标志位复位
			std::cin.ignore(100, '\n');//清除缓存区
			std::cout << "请输入一个合法的值\n";
		}
	}
	int total = 0;
	for (int j = 0; j < ITEM; j++) {
		total += num[j];
	}
	std::cout << "总和是：" << total;
	std::cout << "平均值是：" <<(float) total / ITEM;

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
