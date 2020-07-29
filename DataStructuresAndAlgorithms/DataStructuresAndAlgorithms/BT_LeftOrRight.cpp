#include <iostream>
using namespace std;

#include <string>

#include "BTNQueueAndStack.h"

int LeftOrRight(BinaryTreeNode * root, BinaryTreeNode * node)
{
	if (root == NULL)	return 0;

	if (root == node)	return 1;

	int leftResult = 0, rightResult = 0;

	leftResult = LeftOrRight(root->getleft(), node);
	if (leftResult)	return 1;

	rightResult = LeftOrRight(root->getright(), node);
	if (rightResult) return 2;

	return 0;
}

string PrintSide(int side)
{
	switch (side)
	{
		case 0: return "no";

		case 1: return "left";

		case 2: return "right";

		default: return "";
	}
}

void BT_LeftOrRight_main()
{
	/*
								---- 1=root=100 ----								10=root=1000
							/						\
						2=200						3=300
						/	\						/	\
					4=400	5=500				6=600	7=700
							/						\
						8=800						9=900
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

	node5->setleft(node8);

	node6->setright(node9);

#pragma endregion

#pragma region Execution

	cout << "Node " << node2->getdata() << " is on " << PrintSide(LeftOrRight(root, node2)) << " side of root\n";

	cout << "Node " << node3->getdata() << " is on " << PrintSide(LeftOrRight(root, node3)) << " side of root\n";

	cout << "Node " << node8->getdata() << " is on " << PrintSide(LeftOrRight(root, node8)) << " side of root\n";

	cout << "Node " << node9->getdata() << " is on " << PrintSide(LeftOrRight(root, node9)) << " side of root\n";

	cout << "Node " << node10->getdata() << " is on " << PrintSide(LeftOrRight(root, node10)) << " side of root\n";

#pragma endregion
}