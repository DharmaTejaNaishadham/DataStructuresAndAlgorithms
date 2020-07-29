#include <iostream>
using namespace std;

#include <vector>

#include "BT.h"

vector<int> preOrder;

void PrintVectorFrom(int i)
{
	while (i < preOrder.size())
	{
		cout << preOrder[i] << "\t";
		i++;
	}
	cout << "\n";
}

void CheckIfkSum(int k)
{
	int sum = 0;
	for (int i = preOrder.size() - 1; i >= 0; i--)
	{
		sum += preOrder[i];

		if (sum == k)
			PrintVectorFrom(i);		
	}
}

void kSumPaths(BinaryTreeNode * root, int k)
{
	if (root)
	{
		preOrder.push_back(root->getdata());
		CheckIfkSum(k);

		kSumPaths(root->getleft(), k);
		kSumPaths(root->getright(), k);

		preOrder.pop_back();
	}
}

void BT_kSumPaths_main()
{
	/*
									---- 1=root=1 ----
								/						\
							2=3							3=-1
							/	\						/	\
						4=2		5=1					6=4		7=5
								/					/	\		\
								8=1				9=1		10=2	11=6
	*/

#pragma region Preparation

	BinaryTreeNode *root = new BinaryTreeNode();
	root->setdata(1);

	BinaryTreeNode *node2 = new BinaryTreeNode();
	node2->setdata(3);

	BinaryTreeNode *node3 = new BinaryTreeNode();
	node3->setdata(-1);

	BinaryTreeNode *node4 = new BinaryTreeNode();
	node4->setdata(2);

	BinaryTreeNode *node5 = new BinaryTreeNode();
	node5->setdata(1);

	BinaryTreeNode *node6 = new BinaryTreeNode();
	node6->setdata(4);

	BinaryTreeNode *node7 = new BinaryTreeNode();
	node7->setdata(5);

	BinaryTreeNode *node8 = new BinaryTreeNode();
	node8->setdata(1);

	BinaryTreeNode *node9 = new BinaryTreeNode();
	node9->setdata(1);

	BinaryTreeNode *node10 = new BinaryTreeNode();
	node10->setdata(2);

	BinaryTreeNode *node11 = new BinaryTreeNode();
	node11->setdata(6);

	root->setleft(node2);
	root->setright(node3);

	node2->setleft(node4);
	node2->setright(node5);

	node3->setleft(node6);
	node3->setright(node7);

	node5->setleft(node8);

	node6->setleft(node9);
	node6->setright(node10);

	node7->setright(node11);

#pragma endregion

#pragma region Execution

	kSumPaths(root, 5);

#pragma endregion
}