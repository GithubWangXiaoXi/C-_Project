// test1.cpp : �������̨Ӧ�ó������ڵ㡣
//
/************************************************************************/
/*  ����������   �ȵõ�һЩ�ַ����ֵ�Ƶ�ʣ��ٸ���Ƶ�ʽ��ַ��ųɹ�������
/*��WPLֵ��С��,��������루���������ֱ�Ϊ0��1��,����1���ֽڣ�8λ�����ַ�
/* ��ѹ�����˱䳤�Ķ����ƣ����һ����7���ַ�����䳤�Ϊ3λ��
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
//		cout << "�ļ���ȡʧ��";
//		return;
//	}
//
//	//����ָ�룬��ȡ����
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
		cout << endl << "�����ַ�������" << endl;
		cin >> num;

		cout << endl << "�����ַ���" << endl;
		cin >> str;

		/*for (int i = 0; i < num; i++)
		{
			cin >> array1[i];
		}

		cout << getArrayLen(array1) << endl;
		cout << end(array1) - begin(array1) << endl;*/

		////�ļ���ȡ
		//string str = "D:\\test.txt";
		//cout << readText(str) << endl;


		DataStorage a;
		a.getData(str);
		a.dataToWeight();

	}

	system("pause");
    return 0;
}

