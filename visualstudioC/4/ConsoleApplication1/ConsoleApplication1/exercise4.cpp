#include <iostream>

int main()
{
	const unsigned short ITEMS = 5;

	int intArray[ITEMS] = { 1, 2, 3, 4, 5 };
	char charArray[ITEMS] = { 'F', 'i', 's', 'h', 'C' };

	int *intPtr = intArray;
	char *charPtr = charArray;

	std::cout << "�����������: " << '\n';
	for (int i = 0; i < ITEMS; i++)
	{
		std::cout << *intPtr << " at " << intPtr << '\n';
		intPtr++;
	}

	std::cout << "�ַ����������: " << '\n';
	for (int i = 0; i < ITEMS; i++)
	{
		//std::cout << *charPtr << " at " << charPtr << '\n';//charPtr��������ַ��������ǵ�ַ�����ַ�������δ��ȫ��ʼ����������������ַ�
		//��ΪC++I/O���<<���������أ������ַ���ָ���ᵱ���ַ��������������ָ����ָ����ַ�����
		//������Ҫ�����Ӧ��ַ������Ҫǿ������ת����������ת��
		std::cout << *charPtr << " at " << reinterpret_cast<unsigned long>(charPtr) << '\n';
		charPtr++;
	}
	return 0;
}