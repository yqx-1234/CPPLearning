//CPP�ַ����÷�
#include "iostream"
#include "string"
int main() {
	std::string str1;
	std::string str2;
	std::cout << "���������һ���ַ���:" << "\n";
	//std::cin >> str;//���ո���Ϊ����һ������
	std::getline(std::cin, str1);//��ȡһ���ַ�����\n����,�����cinһ�������з����ڻ�������
	//std::cin.ignore(100, '\n');//��ջ�����
	std::getline(std::cin, str2);//��ȡһ���ַ�����\n����
	std::cout << "str1=" << str1 << "\n";
	std::cout << "str2=" << str2 << "\n";
	std::cout << "��ȡstr1�����ַ���Ϊ��" << str1.substr(0, 3) << "\n";//str.substr(a,b)������ַ���str�дӵ�aλ��ʼ����Ϊb���ַ�
	int a = str1.compare(0, 1, str2, 0, 1);//str1.compare(a, b, str2, c, d)��str1�ַ����ĵ�aλ��ʼ��b�����ȵ��ַ�����str2�ַ�����cλ��ʼ��d�����ȵ��ַ���
	//����������0�������ֵ�˳��ASCII��ֵ����ȣ�str1<str2,�����-1�������������1
	std::cout << "�ȽϽ��Ϊ" << a << "\n";
	str1.insert(1, str2);//���뷽������str1��ԭ�±�1��ǰ�����str2�ַ���
	std::cout << "�������ַ���str1Ϊ" << str1 << "\n";
	int b = 0;
	b = str1.find(str2);//����str2��str1�г��ֵ�λ��
	std::cout << "�������Ϊ" << b << "\n";
	return 0;
}
