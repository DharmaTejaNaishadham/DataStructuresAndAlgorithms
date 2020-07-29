#include <iostream>
using namespace std;

#include "BT.h"

int BT_Sum(BinaryTreeNode * root)
{
	int static sum;

	if (root != NULL)	sum += root->getdata();
	if (root->getleft() != NULL)	BT_Sum(root->getleft());
	if (root->getright() != NULL)	BT_Sum(root->getright());

	return sum;
}

int BT_Max(BinaryTreeNode * root)
{
	int static max;

	if (root != NULL)	max = (max >= root->getdata()) ? max : root->getdata();
	if (root->getleft() != NULL)	BT_Max(root->getleft());
	if (root->getright() != NULL)	BT_Max(root->getright());

	return max;
}

int BT_Min(BinaryTreeNode * root)
{
	int static min;

	if (root != NULL)
	{
		if (min == 0)	min = root->getdata();
		min = (min <= root->getdata()) ? min : root->getdata();
	}
	if (root->getleft() != NULL)	BT_Max(root->getleft());
	if (root->getright() != NULL)	BT_Max(root->getright());

	return min;
}


void BT_Sum_Max_Min_main()
{
	/*
							---- 1=root=100 ----
						/							\
					2=200							3=300
					/	\							/	\
				4=400	5=500					6=600	7=700
							\					/        /
							9=900			8=800      10=1000
	*/

#pragma region Preparation

	BinaryTreeNode *root = new BinaryTreeNode();
	root->setdata(100);

	BinaryTreeNode *node2 = new BinaryTreeNode();
	node2->setdata(200);

	BinaryTreeNode *node3 = new BinaryTreeNode();
	node3->setdata(300);

	BinaryTreeNode *node4 = new BinaryTreeNode();
	node4->setdata(400);

	BinaryTreeNode *node5 = new BinaryTreeNode();
	node5->setdata(500);

	BinaryTreeNode *node6 = new BinaryTreeNode();
	node6->setdata(600);

	BinaryTreeNode *node7 = new BinaryTreeNode();
	node7->setdata(700);

	BinaryTreeNode *node8 = new BinaryTreeNode();
	node8->setdata(800);

	BinaryTreeNode *node9 = new BinaryTreeNode();
	node9->setdata(900);

	BinaryTreeNode *node10 = new BinaryTreeNode();
	node10->setdata(1000);

	root->setleft(node2);
	root->setright(node3);

	node2->setleft(node4);
	node2->setright(node5);

	node3->setleft(node6);
	node3->setright(node7);

	node6->setleft(node8);

	node5->setright(node9);

	node7->setleft(node10);

#pragma endregion

#pragma region Execution

	cout << "Sum of the data in the nodes = " << BT_Sum(root) << "\n";

	cout << "Max of data values in the nodes = " << BT_Max(root) << "\n";

	cout << "Max of data values in the nodes = " << BT_Min(root) << "\n";

#pragma endregion
}