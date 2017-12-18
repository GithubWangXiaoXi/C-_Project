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
		weight = 0;  //将权值初始值付0
	}
};

class DataStorage {

public:
	char data[100];	//得到字符，储存在字符数组中
	dataWeights dataWeight[dataWeightNum];

public:
	dataWeights *getDataWeight()
	{
		dataWeights *temp = dataWeight;
		return temp;
	}

	DataStorage()
	{
		//初始化对象数组
		for (int i=0; i < dataWeightNum; i++)
		{
			dataWeight[i].data = NULL;
			dataWeight[i].weight = NULL;
		}
	}

public:
	int dataLength = 0;  //记录字符数组的长度

	int length();   //返回字符数组的长度

	void getData(string str);   //得到字符数据

	void dataToWeight();   //保留字符的权值
};

