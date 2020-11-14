#include <iostream>
#include <fstream>
#include <windows.h>         // Ϊ��ʹ��Sleep()���� 
#include "string"
struct FishOil
{
	std::string name;
	std::string uid;
	char sex;
};

bool InitFishC();
bool ReadFishC();
void RecordFishC();
bool WriteFishC(FishOil *OilData);

int main()
{
	int i;

	InitFishC();  // ��ʼ�����ݡ� 
	while (1)
	{
		std::cout << "��ѡ����Ҫ���еĲ���: \n";
		std::cout << "1. ��ӡ���ݵ���Ļ\n";
		std::cout << "2. ¼������\n";
		std::cout << "3. �˳�����\n";
		std::cin >> i;

		switch (i)
		{
		case 1:
			if (ReadFishC())
				std::cout << "�ɹ���ȡ�ļ�^_^\n\n";
			else
				std::cout << "��ȡ�ļ�ʧ��T_T\n\n";
			break;
		case 2:
			RecordFishC();
			break;
		case 3:
			return 0;
		}
	}

	std::cout << "��ʼ��ʧ��T_T......\n\n";

	return 0;

}

bool InitFishC()
{
	FishOil YQX;
	YQX.name = "YQX";
	YQX.sex = 'M';
	YQX.uid = "000001";
	if (WriteFishC(&YQX) == false) {
		std::cout << "��ʼ��ʧ��\n";
		return false;
	}
	return true;
}

bool ReadFishC()
{
	std::string temp;
	std::fstream input("YQX.txt");
	if (input.is_open()) {
		std::cout << "�����������.....";
			for (int i = 0; i <= 100; i++)      // ��ӡ�ٷֱ� 
			{
				std::cout.width(3);
				std::cout << i << "%";
				Sleep(50);
				std::cout << "\b\b\b\b";//����Ҫ������ַ�ǰ���ĸ�λ����ɾ����ռ�õ��ַ�
			}
		std::cout << "\n\n";
		std::cout << " ���� " << "  ���֤  " << " �Ա� " << "\n\n";
		while (std::getline(input, temp))//����ȡ��һ���ַ������temp�����\nһ�ζ�����ɣ������ļ�ĩβ����ѭ��
		{
			std::cout << temp << "   ";
			std::cout << "\n";
		}
		std::cout << "\n\n";
		return true;
	}
	else
		return false;


}

void RecordFishC()
{
	char goon,save;
	FishOil record1;
	FishOil *record1p;
		goon = 'Y';
	while (goon == 'Y') {
		std::cout << "�������û���" << "\n";
		std::cin >> record1.name;
		std::cout << "�������Ա�" << "\n";
		std::cin >> record1.sex;
		std::cout << "������UID" << "\n";
		std::cin >> record1.uid;
	std::cout << "¼��ɹ�, ������Ҫ�����𣿣�Y/N��";
	std::cin >> save;
	if (save == 'Y') {
		record1p = &record1;
		if(WriteFishC(record1p))
			std::cout << "�ɹ�д���ļ�^_^\n";
		else
			std::cout << "д���ļ�ʧ��T_T\n";
	}
	else
	{
		return;
	}
	std::cout << "/n������Ҫ�ٴ�¼���𣿣�Y/N��";
	std::cin >> goon;
}
}

bool WriteFishC(FishOil *pOilData)
{
	std::fstream fp("YQX.txt",std::ios::out | std::ios::app);
	if (fp.is_open()) {//�ж��ļ��Ƿ�ɹ���
		fp << pOilData->name << "\t" << pOilData->sex << "\t" << pOilData->uid << "\n";
		fp.close();
		std::cout << "���ݳɹ�����\n";
	}
	else {
		std::cout << "�ļ���ʧ��";
		fp.close();
		return false;
	}
	return true;
}
