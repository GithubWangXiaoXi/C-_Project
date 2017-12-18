#pragma once

//������������
#include "stdafx.h"
#include "DataStorage.h"
#include <iostream>
#include <string>
#include<vector>
#include <stack>
using namespace std;


struct HuffmanTreeCode {
public:
	char data;
	vector<char> vector2;  //�洢code��ָ������

protected:
	void HuffmanTreeCodeStorage(int count, stack<char> stack1);

public:
	//��������õ������ַ��ͱ��루�������vector�У�
	HuffmanTreeCode(int count, char data1,stack<char> stack1)
	{
		data = data1;
		//HuffmanTreeCodeStorage(count, stack1);

		while (!stack1.empty())
		{
			//cout << stack1.top();

			vector2.push_back(stack1.top());

			stack1.pop();
		}

		cout << data<<" ";
		for (int i = 0; i < count; i++)
		{
			cout << vector2[i];
		}

		cout << endl;
	}
};


//��������������������Ĺ��캯������
//void HuffmanTreeCode::HuffmanTreeCodeStorage(int count, stack<char> stack1)
//{
//	while (!stack1.empty())
//	{
//		cout << stack1.top();
//
//		vector2.push_back(stack1.top());
//
//		stack1.pop();
//	}
//
//	for (int i = 0; i < count; i++)
//	{
//		cout << vector2[i];
//	}
//
//	cout << endl;
//}
//

struct HuffmanTreeNodes {
	
public:
	char data;
	int weight;
	int parent, leftChild, rightChild;
    
public:
	//HuffmanTreeNodes();
	HuffmanTreeNodes(char data1='0', int weight1=0, int par = 0, int left = 0, int right = 0)
	{
		data = data1;
		weight = weight1;
		parent = par;
		leftChild = left;
		rightChild = right;
	}
};


class HuffmanTree {
public:
	HuffmanTreeNodes *nodes; //�����������������н���ָ������
	HuffmanTreeNodes *leafNodes;  //��������������Ҷ����ָ������
	HuffmanTreeCode *charCodes;  //��������������Ҷ������ֵ����������

	int leafNum;
	int totalNodesNum;

protected:
	void createHuffmanTree(dataWeights dataWeight[], int num);  //��Ϊ�����������ڴ�������ʱ����������������

public:
	HuffmanTree(dataWeights dataWeight[],int leafNum)
	{
		createHuffmanTree(dataWeight, leafNum);
	}

	void encode();
};
