// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"


int main(int argc,char* argv[]){//argc:程序的参数数量包含本身，argv[]的每个指针指向命令行的一个字符串
	FILE *in;
	FILE *out;//定义两个文件指针
	int ch;
	if (argc != 3) {//检查命令行输入参数个数，如果不等于3则打印错误信息
		fprintf(stderr, "输入形式：copyFile 源文件 目标文件名\n");//stderr:标准错误输出设备，默认向屏幕输出
		exit(EXIT_FAILURE);//退出程序，并表示此时是异常退出
	}
	if ((in = fopen(argv[1], "rb")) == NULL) {//打开一个文件,只读2进制形式打开，并将该文件的文件指针指向in
		fprintf(stderr, "打不开文件:/%s\n", argv[1]);//若打开失败，则向stderr中打印提示信息，表示找不到该源文件
		exit(EXIT_FAILURE);//退出程序，并表示此时是异常退出
	}
	if ((out = fopen(argv[2], "wb")) == NULL) {//打开目标文件：只写二进制形式
		fprintf(stderr, "打不开文件：%s\n", argv[2]);
		exit(EXIT_FAILURE);//程序异常退出
	}
	while ((ch = getc(in)) != EOF) {//从in文件指针指向的文件中读取一个字符，并判断是否读取到文件末尾结束符EOF
		if (putc(ch, out) == EOF) {//向目标文件中写入从源文件读取的字符，若读取错误返回EOF，则退出循环
			break;
		}
	}
	if (ferror(in)) {//使用ferror()函数判断源文件是否读取过程中产生错误,返回非零值则表示出现错误
		printf("读取文件%s失败!\n",argv[1]);
	}
	if (ferror(out)) {
		printf("写入文件%s失败!\n", argv[2]);
	}
	printf("成功复制1个文件!\n");
	fclose(in);//关闭源文件
	fclose(out);//关闭目标文件
	return 0;
	}


// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
