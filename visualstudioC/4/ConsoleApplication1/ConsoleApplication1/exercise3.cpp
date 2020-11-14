//数据结构——指针
#include "iostream"
#include "string"
int main() {
	int a = 123;
	float b = 3.14;
	char c = 'C';
	unsigned long d = 19880808;
	std::string e = "I love CPP";

	std::cout << "a的值是：" << a << std::endl;
	std::cout << "b的值是：" << b << "\n";
	std::cout << "c的值是：" << c << "\n";
	std::cout << "d的值是：" << d << "\n";
	std::cout << "e的值是：" << e << "\n";

	int *apointer = &a;
	float *bpointer = &b;
	char *cpointer = &c;
	unsigned long *dpointer = &d;
	std::string *epointer =&e;

	*apointer = 456;
	*bpointer = 4.13;
	*cpointer = 'F';
	*dpointer = 20111124;
	*epointer = "I love beauty!";

	std::cout << "a的值是：" << a << std::endl;
	std::cout << "b的值是：" << b << "\n";
	std::cout << "c的值是：" << c << "\n";
	std::cout << "d的值是：" << d << "\n";
	std::cout << "e的值是：" << e << "\n";

	return 0;
}