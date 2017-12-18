#include "stdafx.h"
#include "Huffman.h"
#include "DataStorage.h"
#include <iostream>
#include <algorithm>
#include<vector>
#include<list>
#include<stack>
#define dataWeightNum 20
using namespace std;

//对哈夫曼叶子结点（对象）从小到大排序
bool compare(HuffmanTreeNodes &a, HuffmanTreeNodes &b)
{
	if (a.weight < b.weight)
	{
		return true;
	}
	return false;
}

void HuffmanTree::createHuffmanTree(dataWeights dataWeight[], int num)
{
	leafNum = num;
    totalNodesNum = leafNum * 2 - 1;

	//用结构体数组建哈弗曼树
	nodes = new HuffmanTreeNodes[totalNodesNum + 1];  //nodes[0]未用,方便待会寻找双亲结点
	leafNodes = new HuffmanTreeNodes[leafNum + 1];   //leafNodes[0]未用

	int token[100];   //用token数组来记录已经作为叶子结点的结点
	for (int i = 0;i < 100; i++)
	{
		token[i] = 0;
	}

    //对叶子结点赋权值和字符（孩子，双亲默认为0）
	for (int i = 1; i < leafNum+1; i++)
	{
		leafNodes[i].data = dataWeight[i-1].data;
		leafNodes[i].weight = dataWeight[i-1].weight;

		nodes[i].data = leafNodes[i].data;
		nodes[i].weight = leafNodes[i].weight;
	}

	//对叶子结点按权值从小到大排序(用vector排序)
	//具体用途:每次找到剩余对象数组中的最小2个数，
	//再使最小的两个值相加，并使相加值放入nodes指针数组中

/*
	vector<HuffmanTreeNodes> tempVector;

	for (int i = 0; i < leafNum; i++)
	{
		tempVector.push_back(leafNodes[i+1]);
	}

	sort(tempVector.begin(), tempVector.end(), compare);

	cout << endl;
	for (int i = 1; i < leafNum + 1; i++)
	{
		cout << leafNodes[i].data << " " << leafNodes[i].weight << " "
			<< leafNodes[i].leftChild << " " << leafNodes[i].rightChild << " "
			<< leafNodes[i].parent << endl;
	}*/

	////将叶子结点赋值到所有结点
	//for (int i = 1; i < leafNum+1; i++)
	//{
	//	leafNodes[i].data = tempVector[i].data;
	//	nodes[i].data = leafNodes[i].data;

	//	leafNodes[i].weight = tempVector[i].weight;
	//	nodes[i].weight = leafNodes[i].weight;
	//}

	///*for (int i = 0; i < leafNum; i++)
	//{
	//	cout << nodes[i].data << " " << nodes[i].weight << endl;
	//}*/


	////记录第几个最小数
	//int count = 0;

	//叶子结点外其他的结点的构建
	for (int i = leafNum+1; i < totalNodesNum+1; i++)
	{
		int num1, num2;     //两个最小的权值
		int pos1=0, pos2=0;     //两个最小的权值对应的数组下标

		int flag1 = 0;   //防止取两个值相等，只进入第一个条件语句，未进入else if语句,控制第一个条件语句
		int flag2 = 0;   //防止取两个值相等，只进入第一个条件语句，未进入else if语句，控制第二个条件语句

		//每次通过count“指针”“去两个数”后，对新的数组排序，从中找最小的两个数
		vector<HuffmanTreeNodes>vector1;
		
		for (int j = 0; j < i-1; j++)
		{
			if (token[j + 1] == 0)
			{
				vector1.push_back(nodes[j + 1]);
			}
		}
		sort(vector1.begin(), vector1.end(), compare);

		//cout << i << endl;
	    //在i-1个数组元素中与已经进行weight值的大小排序，得到元素下标和权值
		
		for (int k = 1; k < i; k++)
		{
			if (flag1 == 0 && token[k] == 0 && nodes[k].weight == vector1[0].weight)
			{
				num1 = vector1[0].weight;
				pos1 = k;
				flag1 = 1;
				/*cout << vector1[count].weight << " " << k << " " << pos1 << endl;*/
				//cout << "vector1[0].weight：" <<vector1[0].weight << endl;
			}
			else if (flag2 == 0 && token[k] == 0 &&nodes[k].weight == vector1[1].weight)
			{
				num2 = vector1[1].weight;
				pos2 = k;
				flag2 = 1;
				/*cout << vector1[1].weight << " " << k << " " <<pos2 << endl;*/
				//cout << "vector1[1].weight：" << vector1[1].weight << endl;
			}
		}

		nodes[pos1].parent = i;  //将双亲结点的数组下标赋给各个结点的parent的值，方便寻找其双亲
		nodes[pos2].parent = i;
		
		token[pos1] = 1;      //两结点已经有双亲了，在下一次比较时将两个数排除
		token[pos2] = 1;

		nodes[i].weight = num1 + num2;
		
		nodes[i].leftChild = pos1;   //将孩子结点的数组下标赋值给各个内结点，方便查找
		nodes[i].rightChild = pos2;   

		//cout << "pos1:" << pos1 << " " << "pos2:" << pos2 << " " <<"parent:" << i << endl;
	}

	cout << endl;

	cout << "哈夫曼树构建成功" << endl;
	for (int i = 1; i < totalNodesNum + 1; i++)
	{
		cout << nodes[i].data << " " << nodes[i].weight << " "
			<< nodes[i].leftChild << " " << nodes[i].rightChild << " "
			<< nodes[i].parent << endl;
	}
}

void HuffmanTree::encode()
{
	vector<char> HuffmanCode[dataWeightNum];
	vector<char>::iterator iter;

	//for (int i = 0; i < totalNodesNum + 1; i++)
	//{
	//	HuffmanCode[i] =;
	//}

	for (int i = 1; i < leafNum+1; i++)
	{
		//通过父节点为0为结界进行循环编码,每次用i作为指针数组的“活动指针”
		//注意child,parent分别存的是哈夫曼指针数组的下标
		for (unsigned int child = i, parent = nodes[child].parent; parent != 0; child = parent,parent = nodes[child].parent)
		{
			if (nodes[parent].leftChild == child)
			{
				HuffmanCode[i].push_back('0');
			}
			else if (nodes[parent].rightChild == child)
			{
				HuffmanCode[i].push_back('1');
			}
		}
	}

	cout << endl << "具体字符编码如下" << endl;

	for (int i = 1; i < leafNum + 1; i++)
	{
		/*for (iter = HuffmanCode.begin(); iter != HuffmanCode.end(); iter++)
		{
			cout << *iter << " ";
		}
		cout << endl;*/
		
		//编码是从孩子结点开始插入矢量vector的，所以最后读出的码是逆序的，要使其正序，用栈存
		int count = 0;
		stack<char>stack1;
		for (iter = HuffmanCode[i].begin(); iter != HuffmanCode[i].end(); iter++)
		{
			stack1.push(*iter);
			count++;
		}

		cout << leafNodes[i].data << "  ";
		while (!stack1.empty()) {
			cout << stack1.top();
			stack1.pop();
		}

		//charCodes[i] = HuffmanTreeCode(count, leafNodes[i].data, stack1);
		
		//cout << leafNodes[i].data << endl;

		//打印charCodes（字符与编码）
		/*cout << charCodes[i].data << " ";
		for (int k = 0;k<count;k++)
		{
			cout << charCodes[i].vector2[k];
		}*/

		cout << endl;
	}
	
	/*for (int i = 1; i < totalNodesNum+1; i++)
	{
		cout << HuffmanCode[i] << endl;
	}*/
}