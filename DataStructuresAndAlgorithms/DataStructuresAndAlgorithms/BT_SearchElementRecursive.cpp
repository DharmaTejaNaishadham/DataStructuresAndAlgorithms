#include <iostream>
using namespace std;

#include "BT.h"

bool BT_SearchElementRecursive(BinaryTreeNode* root, int searchFor)
{
	if (root != NULL)
	{
		if (root->getdata() == searchFor)
			return true;

		bool left = BT_SearchElementRecursive(root->getleft(), searchFor);
		bool right = BT_SearchElementRecursive(root->getright(), searchFor);

		if (left || right)
			return true;
	}

	return false;
}

void BT_SearchElementRecursive_main()
{
	/*
							---- 1=root=100 ----
						/							\
					2=200							3=300
					/	\							/	\
				4=400	5=500					6=600	7=700
							\					/
							9=900			8=800
	*/

#pragma region Preparation

	BinaryTreeNode* root = new BinaryTreeNode();
	root->setdata(100);

	BinaryTreeNode* node2 = new BinaryTreeNode();
	node2->setdata(200);

	BinaryTreeNode* node3 = new BinaryTreeNode();
	node3->setdata(300);

	BinaryTreeNode* node4 = new BinaryTreeNode();
	node4->setdata(400);

	BinaryTreeNode* node5 = new BinaryTreeNode();
	node5->setdata(500);

	BinaryTreeNode* node6 = new BinaryTreeNode();
	node6->setdata(600);

	BinaryTreeNode* node7 = new BinaryTreeNode();
	node7->setdata(700);

	BinaryTreeNode* node8 = new BinaryTreeNode();
	node8->setdata(800);

	BinaryTreeNode* node9 = new BinaryTreeNode();
	node9->setdata(900);

	root->setleft(node2);
	root->setright(node3);

	node2->setleft(node4);
	node2->setright(node5);

	node3->setleft(node6);
	node3->setright(node7);

	node6->setleft(node8);

	node5->setright(node9);

	int searchFor;
	cout << "Enter the no. that you want to search for : ";
	cin >> searchFor;

#pragma endregion

#pragma region Execution

	cout << "Did we find " << searchFor << " : " << BT_SearchElementRecursive(root, searchFor) << "\n";

#pragma endregion
}