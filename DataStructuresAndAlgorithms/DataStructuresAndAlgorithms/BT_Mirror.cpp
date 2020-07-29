#include <iostream>
using namespace std;

#include "BT.h"

void Mirror(BinaryTreeNode * root)
{
	BinaryTreeNode * temp = new BinaryTreeNode();

	if (root != NULL)
	{
		temp = root->getright();
		root->setright(root->getleft());
		root->setleft(temp);

		Mirror(root->getleft());
		Mirror(root->getright());
	}
}

void BT_Mirror_main()
{
	/*
										---- 1=root=100 ----
									/						\
								2=200						3=300
								/	\						/	\
							4=400	5=500				6=600	7=700
									/							\
								8=800							9=900
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

	root->setleft(node2);
	root->setright(node3);

	node2->setleft(node4);
	node2->setright(node5);

	node3->setleft(node6);
	node3->setright(node7);

	node5->setleft(node8);

	node7->setright(node9);

#pragma endregion

#pragma region Execution

	cout << "Before: \n";
	InOrderRec(root);

	Mirror(root);

	cout << "\nAfter: \n";
	InOrderRec(root);

#pragma endregion
}