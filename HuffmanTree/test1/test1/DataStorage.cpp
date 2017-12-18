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
	int dataWeightLength = 0;   //���ַ���Ȩֵ������ĳ���

	//ֻд�벻ͬ�ַ���dataWeight������
	for (int i = 0; i < length(); i++)
	{
		int flag = 0;  //�����ж��Ƿ����ڶ���ѭ�������û�У���ִ��for����Ĳ���
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

	cout << endl << "�ַ������Ӧ���ֵ�Ƶ������" << endl;
	for (int k = 0; k < dataWeightLength; k++)
	{
		cout << dataWeight[k].data << "  " << dataWeight[k].weight << endl;
	}

	HuffmanTree a(dataWeight,dataWeightLength);

	a.encode();
}