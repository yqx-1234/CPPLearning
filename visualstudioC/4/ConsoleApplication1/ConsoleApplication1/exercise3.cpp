//���ݽṹ����ָ��
#include "iostream"
#include "string"
int main() {
	int a = 123;
	float b = 3.14;
	char c = 'C';
	unsigned long d = 19880808;
	std::string e = "I love CPP";

	std::cout << "a��ֵ�ǣ�" << a << std::endl;
	std::cout << "b��ֵ�ǣ�" << b << "\n";
	std::cout << "c��ֵ�ǣ�" << c << "\n";
	std::cout << "d��ֵ�ǣ�" << d << "\n";
	std::cout << "e��ֵ�ǣ�" << e << "\n";

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

	std::cout << "a��ֵ�ǣ�" << a << std::endl;
	std::cout << "b��ֵ�ǣ�" << b << "\n";
	std::cout << "c��ֵ�ǣ�" << c << "\n";
	std::cout << "d��ֵ�ǣ�" << d << "\n";
	std::cout << "e��ֵ�ǣ�" << e << "\n";

	return 0;
}