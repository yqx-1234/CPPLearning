#include "fstream"
#include "iostream"

using namespace std;

int main() {
	ofstream out("test.txt", ios::app);//����һ���ļ������󲢽��˶���ָ��test.txt,���򿪴��ļ�����ģʽΪ��
	//ios::app:��������������ļ�ĩβ
	if (!out) {
		cerr << "�ļ���ʧ��" << endl;
		return 0;
	}

	for (int i = 10; i > 0; i--) {
		out << i;
	}
	out << endl;
	out.close();
	return 0;
}