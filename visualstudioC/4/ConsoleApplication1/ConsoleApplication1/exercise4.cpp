#include <iostream>

int main()
{
	const unsigned short ITEMS = 5;

	int intArray[ITEMS] = { 1, 2, 3, 4, 5 };
	char charArray[ITEMS] = { 'F', 'i', 's', 'h', 'C' };

	int *intPtr = intArray;
	char *charPtr = charArray;

	std::cout << "整型数组输出: " << '\n';
	for (int i = 0; i < ITEMS; i++)
	{
		std::cout << *intPtr << " at " << intPtr << '\n';
		intPtr++;
	}

	std::cout << "字符型数组输出: " << '\n';
	for (int i = 0; i < ITEMS; i++)
	{
		//std::cout << *charPtr << " at " << charPtr << '\n';//charPtr输出的是字符串而不是地址，且字符串由于未完全初始化，会出现烫烫烫字符
		//因为C++I/O类对<<进行了重载，遇到字符型指针后会当成字符串名来处理，输出指针所指向的字符串。
		//所以若要输出对应地址，则需要强制类型转换符来进行转换
		std::cout << *charPtr << " at " << reinterpret_cast<unsigned long>(charPtr) << '\n';
		charPtr++;
	}
	return 0;
}