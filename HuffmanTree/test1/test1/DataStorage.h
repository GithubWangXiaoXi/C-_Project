#pragma once
#include "stdafx.h"
#include <iostream>
#include<string>
#define dataWeightNum 20
using namespace std;

struct dataWeights {
	char data;
	int weight;

public:
	dataWeights()
	{
		weight = 0;  //��Ȩֵ��ʼֵ��0
	}
};

class DataStorage {

public:
	char data[100];	//�õ��ַ����������ַ�������
	dataWeights dataWeight[dataWeightNum];

public:
	dataWeights *getDataWeight()
	{
		dataWeights *temp = dataWeight;
		return temp;
	}

	DataStorage()
	{
		//��ʼ����������
		for (int i=0; i < dataWeightNum; i++)
		{
			dataWeight[i].data = NULL;
			dataWeight[i].weight = NULL;
		}
	}

public:
	int dataLength = 0;  //��¼�ַ�����ĳ���

	int length();   //�����ַ�����ĳ���

	void getData(string str);   //�õ��ַ�����

	void dataToWeight();   //�����ַ���Ȩֵ
};

