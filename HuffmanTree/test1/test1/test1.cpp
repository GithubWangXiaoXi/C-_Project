// test1.cpp : 定义控制台应用程序的入口点。
//
/************************************************************************/
/*  哈夫曼编码   先得到一些字符出现的频率，再根据频率将字符排成哈夫曼树
/*（WPL值最小）,并将其编码（左右子树分别为0，1）,这样1个字节（8位）的字符
/* 被压缩成了变长的二进制（如果一共有7种字符，则变长最长为3位）
/************************************************************************/



#include "stdafx.h"
#include"DataStorage.h"
#include <iostream>
#include <fstream>
#include <cassert>
#include<string>
using namespace std;
//
//void readText(string file)
//{
//	FILE *pfile = fopen("D:\\test.txt", "rb*");
//	
//	char strBuf[30] = { 0 };
//
//	if (NULL == pfile)
//	{
//		cout << "文件读取失败";
//		return;
//	}
//
//	//操作指针，读取函数
//	fgets(strBuf,30,pfile);
//	
//	while (EOF != fgets(strBuf, 30, pfile))
//	{
//
//	}
//
//	fclose(pfile);
//}

int main()
{

	char array1[10];
	string str;
	int num;

	while (1)
	{
		cout << endl << "输入字符串长度" << endl;
		cin >> num;

		cout << endl << "输入字符串" << endl;
		cin >> str;

		/*for (int i = 0; i < num; i++)
		{
			cin >> array1[i];
		}

		cout << getArrayLen(array1) << endl;
		cout << end(array1) - begin(array1) << endl;*/

		////文件读取
		//string str = "D:\\test.txt";
		//cout << readText(str) << endl;


		DataStorage a;
		a.getData(str);
		a.dataToWeight();

	}

	system("pause");
    return 0;
}

