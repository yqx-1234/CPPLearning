#include"fstream"
#include"iostream"

using namespace std;
int main(){
	ofstream out;//定义一个文件流对象out,用于向此对象文件指针指向的文件中写入数据，//默认打开方式是：ios::out | ios::trunc,如果文件已存在先删除在写入创建文件
	out.open("test.txt");//打开一个文件，可写方式
	if (!out) {
		cerr << "文件打开失败" << endl;
		return 0;
	}
	for(int i = 0; i < 10; i++) {
		out << i;
	}
	out << endl;
	out.close();//关闭文件
	return 0;

}