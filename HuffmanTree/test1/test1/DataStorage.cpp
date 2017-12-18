#include"stdafx.h"
#include"DataStorage.h"
#include "Huffman.h"

int DataStorage::length()
{
	return dataLength;
}

void DataStorage::getData(string str)
{
	dataLength = str.length();
	for (int i = 0; i < dataLength; i++)
	{
		data[i] = str[i];
		cout << data[i] << ",";
	}
	cout << endl;
}

void DataStorage::dataToWeight()
{
	int dataWeightLength = 0;   //存字符和权值的数组的长度

	//只写入不同字符到dataWeight数组中
	for (int i = 0; i < length(); i++)
	{
		int flag = 0;  //用来判断是否进入第二个循环，如果没有，则执行for下面的步骤
		for (int j = 0; dataWeight[j].data != NULL; j++)
		{
			if (dataWeight[j].data == data[i])
			{
				dataWeight[j].weight++;
				flag = 1;
				break;
			}
		}

		if(!flag)
		{
			dataWeight[dataWeightLength].data = data[i];
			dataWeight[dataWeightLength].weight++;
			dataWeightLength++;
		}
	}

	cout << endl << "字符与其对应出现的频率如下" << endl;
	for (int k = 0; k < dataWeightLength; k++)
	{
		cout << dataWeight[k].data << "  " << dataWeight[k].weight << endl;
	}

	HuffmanTree a(dataWeight,dataWeightLength);

	a.encode();
}