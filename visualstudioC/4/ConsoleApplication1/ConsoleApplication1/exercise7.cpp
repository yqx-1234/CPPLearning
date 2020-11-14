//泛型程序设计
#include <iostream>

template <typename elemType>//模板类，使得函数可以接受各种类型的输入参数，而编译器在编译时会根据输入参数的类型将elemeType变为不同类型
void print( elemType *pBegin, elemType *pEnd )
{
	while( pBegin != pEnd )
	{
		std::cout << *pBegin;
		++pBegin;
	}
}

int main()
{
	int num[5] = { 0, 1, 2, 3, 4 };
	char name[5] = { 'F', 'i', 's', 'h', 'C' };
	
	print( num, num+5 );
	std::cout << '\n';
	print( name, name+5 );
	std::cout << '\n';
	
	return 0;
}