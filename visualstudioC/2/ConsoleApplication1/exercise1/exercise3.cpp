#include "fstream"
#include "iostream"

using namespace std;

int main() {
	ofstream out("test.txt", ios::app);//创建一个文件流对象并将此对象指向test.txt,并打开此文件，打开模式为：
	//ios::app:所有输出附加在文件末尾
	if (!out) {
		cerr << "文件打开失败" << endl;
		return 0;
	}

	for (int i = 10; i > 0; i--) {
		out << i;
	}
	out << endl;
	out.close();
	return 0;
}