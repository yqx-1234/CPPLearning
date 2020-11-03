
#include <iostream>
#include "fstream"
using namespace std;

int main()
{
	ifstream in;//定义一个文件流对象，用于从指定文件中读取数据
	in.open("test.txt");//使用in对象中的open方法，来读取文件test,txt，将in与test.txt文件关联起来
	if (!in) {//判断文件流状态是否正常
		cerr << "打开文件失败" << endl;//向一个输出流对象中输出程序错误提示信息
		return 0;
	}
	char x;
	while (in >> x) {//将文件中的数据使用>>IO运算符来读出到x中
		cout << x;//将x写入到cout标准输出中

	}
	cout << endl;//换行结尾
	in.close();

	std::cout << "Hello World!\n";
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
