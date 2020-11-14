#include <iostream>
#include <fstream>
#include <windows.h>         // 为了使用Sleep()函数 
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

	InitFishC();  // 初始化数据。 
	while (1)
	{
		std::cout << "请选择需要进行的操作: \n";
		std::cout << "1. 打印数据到屏幕\n";
		std::cout << "2. 录入数据\n";
		std::cout << "3. 退出程序\n";
		std::cin >> i;

		switch (i)
		{
		case 1:
			if (ReadFishC())
				std::cout << "成功读取文件^_^\n\n";
			else
				std::cout << "读取文件失败T_T\n\n";
			break;
		case 2:
			RecordFishC();
			break;
		case 3:
			return 0;
		}
	}

	std::cout << "初始化失败T_T......\n\n";

	return 0;

}

bool InitFishC()
{
	FishOil YQX;
	YQX.name = "YQX";
	YQX.sex = 'M';
	YQX.uid = "000001";
	if (WriteFishC(&YQX) == false) {
		std::cout << "初始化失败\n";
		return false;
	}
	return true;
}

bool ReadFishC()
{
	std::string temp;
	std::fstream input("YQX.txt");
	if (input.is_open()) {
		std::cout << "正在输出数据.....";
			for (int i = 0; i <= 100; i++)      // 打印百分比 
			{
				std::cout.width(3);
				std::cout << i << "%";
				Sleep(50);
				std::cout << "\b\b\b\b";//将将要输入的字符前移四个位，并删除已占用的字符
			}
		std::cout << "\n\n";
		std::cout << " 姓名 " << "  身份证  " << " 性别 " << "\n\n";
		while (std::getline(input, temp))//将读取的一行字符存放在temp里，读到\n一次读入完成，读到文件末尾结束循环
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
		std::cout << "请输入用户名" << "\n";
		std::cin >> record1.name;
		std::cout << "请输入性别" << "\n";
		std::cin >> record1.sex;
		std::cout << "请输入UID" << "\n";
		std::cin >> record1.uid;
	std::cout << "录入成功, 请问需要保存吗？（Y/N）";
	std::cin >> save;
	if (save == 'Y') {
		record1p = &record1;
		if(WriteFishC(record1p))
			std::cout << "成功写入文件^_^\n";
		else
			std::cout << "写入文件失败T_T\n";
	}
	else
	{
		return;
	}
	std::cout << "/n请问需要再次录入吗？（Y/N）";
	std::cin >> goon;
}
}

bool WriteFishC(FishOil *pOilData)
{
	std::fstream fp("YQX.txt",std::ios::out | std::ios::app);
	if (fp.is_open()) {//判断文件是否成功打开
		fp << pOilData->name << "\t" << pOilData->sex << "\t" << pOilData->uid << "\n";
		fp.close();
		std::cout << "数据成功输入\n";
	}
	else {
		std::cout << "文件打开失败";
		fp.close();
		return false;
	}
	return true;
}
