#include "fstream"
#include "iostream"

using namespace std;
int main() {
	fstream fp("test.txt", ios::in | ios::out);//����һ���ļ������󣬲����ļ�����ģʽΪin��out,�ɶ���д
	if (!fp) {
		cerr << "���ļ�ʧ��!" << endl;
		return 0;
	}
	fp << "ILOVEYQX";
	static char str[100];
	static char ste[100];
	fp.seekg(ios::beg);//seekg()���������ļ�ָ���Ƶ�ָ��λ�ã�ios::beg:�ļ�������ʼλ�ã�ios::end:�ļ����Ľ���λ��
	fp >> str;
	cout << str << endl;
	fp >> ste;//������ȡ���������
	cout << ste << endl;
	fp.close();
	return 0;
}