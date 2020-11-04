#include "fstream"
#include "iostream"

using namespace std;
int main() {
	fstream fp("test.txt", ios::in | ios::out);//创建一个文件流对象，并打开文件，打开模式为in和out,可读可写
	if (!fp) {
		cerr << "打开文件失败!" << endl;
		return 0;
	}
	fp << "ILOVEYQX";
	static char str[100];
	static char ste[100];
	fp.seekg(ios::beg);//seekg()方法，将文件指针移到指定位置，ios::beg:文件流的起始位置，ios::end:文件流的结束位置
	fp >> str;
	cout << str << endl;
	fp >> ste;//继续读取后面的内容
	cout << ste << endl;
	fp.close();
	return 0;
}