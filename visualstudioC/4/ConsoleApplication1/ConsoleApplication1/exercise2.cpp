//CPP字符串用法
#include "iostream"
#include "string"
int main() {
	std::string str1;
	std::string str2;
	std::cout << "请随便输入一个字符串:" << "\n";
	//std::cin >> str;//遇空格视为结束一次输入
	std::getline(std::cin, str1);//读取一行字符，遇\n结束,不会和cin一样将换行符存在缓冲区中
	//std::cin.ignore(100, '\n');//清空缓冲区
	std::getline(std::cin, str2);//读取一行字符，遇\n结束
	std::cout << "str1=" << str1 << "\n";
	std::cout << "str2=" << str2 << "\n";
	std::cout << "提取str1的子字符串为：" << str1.substr(0, 3) << "\n";//str.substr(a,b)：获得字符串str中从第a位开始长度为b的字符
	int a = str1.compare(0, 1, str2, 0, 1);//str1.compare(a, b, str2, c, d)将str1字符串的第a位开始到b个长度的字符串与str2字符串的c位开始到d个长度的字符串
	//若相等则输出0，若按字典顺序（ASCII表值）相比，str1<str2,则输出-1，若大于则输出1
	std::cout << "比较结果为" << a << "\n";
	str1.insert(1, str2);//插入方法，在str1中原下标1的前面插入str2字符串
	std::cout << "插入后的字符串str1为" << str1 << "\n";
	int b = 0;
	b = str1.find(str2);//搜索str2在str1中出现的位置
	std::cout << "搜索结果为" << b << "\n";
	return 0;
}
