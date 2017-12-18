#pragma once

//构建哈夫曼树
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
	vector<char> vector2;  //存储code的指针数组

protected:
	void HuffmanTreeCodeStorage(int count, stack<char> stack1);

public:
	//创建对象得到数据字符和编码（编码存在vector中）
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


//用来给哈夫曼树结点编码的构造函数调用
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
	HuffmanTreeNodes *nodes; //构建哈夫曼树的所有结点的指针数组
	HuffmanTreeNodes *leafNodes;  //构建哈夫曼树的叶结点的指针数组
	HuffmanTreeCode *charCodes;  //构建哈夫曼树的叶结点的数值与编码的数组

	int leafNum;
	int totalNodesNum;

protected:
	void createHuffmanTree(dataWeights dataWeight[], int num);  //作为辅助函数，在创建对象时立即构建哈夫曼树

public:
	HuffmanTree(dataWeights dataWeight[],int leafNum)
	{
		createHuffmanTree(dataWeight, leafNum);
	}

	void encode();
};
