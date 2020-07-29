#include <iostream>
using namespace std;

#include "BT.h"

//naming it as size will not work as there could be some other fun/var in std namespace.
//http://stackoverflow.com/questions/11271889/global-variable-count-ambiguous
static int BT_size;

int BT_SizeRecursive(BinaryTreeNode * root)
{
	//Yes, kind of pre order traversal
	if (root != NULL)
	{
		BT_size++;

		BT_SizeRecursive(root->getleft());
		BT_SizeRecursive(root->getright());
	}

	return BT_size;
}

void BT_SizeRecursive_main()
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

	root->setleft(node2);
	root->setright(node3);

	node2->setleft(node4);
	node2->setright(node5);

	node3->setleft(node6);
	node3->setright(node7);

	node6->setleft(node8);

	node5->setright(node9);

#pragma endregion

#pragma region Execution

	BT_size = 0;
	cout << "Size of the tree = " << BT_SizeRecursive(root) << "\n";

#pragma endregion

#pragma region Preparation

	BinaryTreeNode *node10 = new BinaryTreeNode();
	node10->setdata(1000);

	node7->setleft(node10);

#pragma endregion

#pragma region Execution

	BT_size = 0;
	cout << "Size of the tree = " << BT_SizeRecursive(root) << "\n";

#pragma endregion
}