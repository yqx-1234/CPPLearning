//��������
#include "iostream"
void convertTemperature(double tempIn, char typeIn);
int main() {

	//�����¶�=�����¶�*9.0/5.0+32,ע�Ӹ�ʽ�Զ�ת������
	double tempIn;
	char typeIn;
	std::cout << "�밴���¸�ʽ��XX.X C����XX.X F�������¶�";//ע��ո�
	std::cin >> tempIn >> typeIn;//32.4 C
	std::cin.ignore(100, '\n');//���Իس�
	std::cout << '\n';
	convertTemperature(tempIn, typeIn);
	return 0;
}

void convertTemperature(double tempIn, char typeIn) {
	const unsigned short ADD_SUBSTRACT = 32;//���峣�������ñ�����д��Ȩ��ֻ�ж�Ȩ�ޣ���Ҫ��ʼ��
	const double RATIO = 9.0 / 5.0;
	double tempOut;
	char typeOut;
	switch (typeIn) {
	case 'c':
	case 'C':
		tempOut = tempIn * RATIO + ADD_SUBSTRACT;
		typeIn = 'C';
		typeOut = 'F';
		break;
	case 'f':
	case 'F':
		tempOut = (tempIn - ADD_SUBSTRACT) / RATIO;
		typeIn = 'F';
		typeOut = 'C';
		break;
	default:
		typeOut = 'E';
		break;
	}
	if (typeOut != 'E') {
		std::cout << tempIn << typeIn << "=" << tempOut << typeOut << "\n\n";
	}
	else {
		std::cout << "�������" << "\n\n";
	}
	std::cout << "���������ַ�����" << "\n";
	std::cin.get();
}