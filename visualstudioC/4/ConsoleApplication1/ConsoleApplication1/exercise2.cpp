//CPP�ַ����÷�
#include "iostream"
#include "string"
int main() {
	std::string str;
	std::cout << "���������һ���ַ���:";
	//std::cin >> str;//���ո���Ϊ����һ������
	std::getline(std::cin, str);//��ȡһ���ַ�����\n����
	std::cout << str<<"\n";
	return 0;
}