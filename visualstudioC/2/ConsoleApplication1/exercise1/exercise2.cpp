#include"fstream"
#include"iostream"

using namespace std;
int main(){
	ofstream out;//����һ���ļ�������out,������˶����ļ�ָ��ָ����ļ���д�����ݣ�//Ĭ�ϴ򿪷�ʽ�ǣ�ios::out | ios::trunc,����ļ��Ѵ�����ɾ����д�봴���ļ�
	out.open("test.txt");//��һ���ļ�����д��ʽ
	if (!out) {
		cerr << "�ļ���ʧ��" << endl;
		return 0;
	}
	for(int i = 0; i < 10; i++) {
		out << i;
	}
	out << endl;
	out.close();//�ر��ļ�
	return 0;

}