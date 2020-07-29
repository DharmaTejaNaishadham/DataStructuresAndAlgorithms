#include <iostream>
using namespace std;

#include "BT.h"

void PreOrderRec(BinaryTreeNode *root)
{
	if (root != NULL)
	{
		cout << "Address = " << root << " Data = " << root->getdata() << "\t" << " left = " << root->getleft() << "\t" << "right = " << root->getright() << "\n";
		PreOrderRec(root->getleft());
		PreOrderRec(root->getright());
	}
}

void InOrderRec(BinaryTreeNode *root)
{
	if (root != NULL)
	{
		InOrderRec(root->getleft());
		cout << "Address = " << root << " Data = " << root->getdata() << "\t" << " left = " << root->getleft() << "\t" << "right = " << root->getright() << "\n";
		InOrderRec(root->getright());
	}
}

void PostOrderRec(BinaryTreeNode *root)
{
	if (root != NULL)
	{
		PostOrderRec(root->getleft());
		PostOrderRec(root->getright());
		cout << "Address = " << root << " Data = " << root->getdata() << "\t" << " left = " << root->getleft() << "\t" << "right = " << root->getright() << "\n";
	}
}

void BT_RecursiveTraversals_main()
{
	/*
						  ---- 1=root=100 ----
						/						\
					2=200						3=300
					/	\						/	\
				4=400	5=500				6=600	7=700
											/
										 8=800
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

	root->setleft(node2);
	root->setright(node3);

	node2->setleft(node4);
	node2->setright(node5);

	node3->setleft(node6);
	node3->setright(node7);

	node6->setleft(node8);

#pragma endregion

#pragma region Execution

	cout << "Pre Order :\n";
	PreOrderRec(root);

	cout << "In Order :\n";
	InOrderRec(root);

	cout << "Post Order :\n";
	PostOrderRec(root);

#pragma endregion
}