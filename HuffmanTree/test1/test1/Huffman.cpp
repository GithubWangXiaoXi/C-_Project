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

//�Թ�����Ҷ�ӽ�㣨���󣩴�С��������
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

	//�ýṹ�����齨��������
	nodes = new HuffmanTreeNodes[totalNodesNum + 1];  //nodes[0]δ��,�������Ѱ��˫�׽��
	leafNodes = new HuffmanTreeNodes[leafNum + 1];   //leafNodes[0]δ��

	int token[100];   //��token��������¼�Ѿ���ΪҶ�ӽ��Ľ��
	for (int i = 0;i < 100; i++)
	{
		token[i] = 0;
	}

    //��Ҷ�ӽ�㸳Ȩֵ���ַ������ӣ�˫��Ĭ��Ϊ0��
	for (int i = 1; i < leafNum+1; i++)
	{
		leafNodes[i].data = dataWeight[i-1].data;
		leafNodes[i].weight = dataWeight[i-1].weight;

		nodes[i].data = leafNodes[i].data;
		nodes[i].weight = leafNodes[i].weight;
	}

	//��Ҷ�ӽ�㰴Ȩֵ��С��������(��vector����)
	//������;:ÿ���ҵ�ʣ����������е���С2������
	//��ʹ��С������ֵ��ӣ���ʹ���ֵ����nodesָ��������

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

	////��Ҷ�ӽ�㸳ֵ�����н��
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


	////��¼�ڼ�����С��
	//int count = 0;

	//Ҷ�ӽ���������Ľ��Ĺ���
	for (int i = leafNum+1; i < totalNodesNum+1; i++)
	{
		int num1, num2;     //������С��Ȩֵ
		int pos1=0, pos2=0;     //������С��Ȩֵ��Ӧ�������±�

		int flag1 = 0;   //��ֹȡ����ֵ��ȣ�ֻ�����һ��������䣬δ����else if���,���Ƶ�һ���������
		int flag2 = 0;   //��ֹȡ����ֵ��ȣ�ֻ�����һ��������䣬δ����else if��䣬���Ƶڶ����������

		//ÿ��ͨ��count��ָ�롱��ȥ���������󣬶��µ��������򣬴�������С��������
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
	    //��i-1������Ԫ�������Ѿ�����weightֵ�Ĵ�С���򣬵õ�Ԫ���±��Ȩֵ
		
		for (int k = 1; k < i; k++)
		{
			if (flag1 == 0 && token[k] == 0 && nodes[k].weight == vector1[0].weight)
			{
				num1 = vector1[0].weight;
				pos1 = k;
				flag1 = 1;
				/*cout << vector1[count].weight << " " << k << " " << pos1 << endl;*/
				//cout << "vector1[0].weight��" <<vector1[0].weight << endl;
			}
			else if (flag2 == 0 && token[k] == 0 &&nodes[k].weight == vector1[1].weight)
			{
				num2 = vector1[1].weight;
				pos2 = k;
				flag2 = 1;
				/*cout << vector1[1].weight << " " << k << " " <<pos2 << endl;*/
				//cout << "vector1[1].weight��" << vector1[1].weight << endl;
			}
		}

		nodes[pos1].parent = i;  //��˫�׽��������±긳����������parent��ֵ������Ѱ����˫��
		nodes[pos2].parent = i;
		
		token[pos1] = 1;      //������Ѿ���˫���ˣ�����һ�αȽ�ʱ���������ų�
		token[pos2] = 1;

		nodes[i].weight = num1 + num2;
		
		nodes[i].leftChild = pos1;   //�����ӽ��������±긳ֵ�������ڽ�㣬�������
		nodes[i].rightChild = pos2;   

		//cout << "pos1:" << pos1 << " " << "pos2:" << pos2 << " " <<"parent:" << i << endl;
	}

	cout << endl;

	cout << "�������������ɹ�" << endl;
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
		//ͨ�����ڵ�Ϊ0Ϊ������ѭ������,ÿ����i��Ϊָ������ġ��ָ�롱
		//ע��child,parent�ֱ����ǹ�����ָ��������±�
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

	cout << endl << "�����ַ���������" << endl;

	for (int i = 1; i < leafNum + 1; i++)
	{
		/*for (iter = HuffmanCode.begin(); iter != HuffmanCode.end(); iter++)
		{
			cout << *iter << " ";
		}
		cout << endl;*/
		
		//�����ǴӺ��ӽ�㿪ʼ����ʸ��vector�ģ���������������������ģ�Ҫʹ��������ջ��
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

		//��ӡcharCodes���ַ�����룩
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