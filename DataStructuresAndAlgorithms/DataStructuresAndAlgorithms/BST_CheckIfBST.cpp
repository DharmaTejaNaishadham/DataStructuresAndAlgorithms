#include <iostream>
using namespace std;

#include "BTNQueueAndStack.h"

bool BST_CheckIfBST(BinaryTreeNode * root)
{
	BinaryTreeStack * Stack = new BinaryTreeStack();

	if (root == NULL)
	{
		cout << "Binary Tree is empty\n";
		return true;
	}
	else
	{
		while (1)
		{
			while (root)
			{
				BTNS_Push(Stack, root);

				root = root->getleft();
			}

			if (BTNS_IsEmptyStack(Stack))	break;

			root = BTNS_Pop(Stack);

			if (BTNS_IsEmptyStack(Stack))	break;

			if (root->getdata() > (Stack->top)->getdata())
				return false;

			root = root->getright();
		}
	}

	return true;
}

bool BST_CheckIfBST_Recursive(BinaryTreeNode * root)
{
	if (root == NULL)
		return false;

	bool result = true;

	if (root->getleft())
		if ((root->getdata() >= (root->getleft())->getdata()) && (root->getdata() >= BST_FindMax_Rec(root->getleft())->getdata()))
		{
			result = BST_CheckIfBST_Recursive(root->getleft());
		}
		else
		{
			return false;
		}

	if (root->getright())
		if ((root->getdata() < (root->getright())->getdata()) && (root->getdata() < BST_FindMin_Rec(root->getright())->getdata()))
		{
			result = BST_CheckIfBST_Recursive(root->getright());
		}
		else
		{
			return false;
		}

	return result;
}

void BST_CheckIfBST_main()
{
	/*								Binary Search Tree

									---- 6=root=600 ----
								/						\
							4=400						8=800
							/	\						/	\
						2=200	5=500				7=700	9=900
						/	\
					1=100	3=300

				In Order: 100 - 200 - 300 - 400 - 500 - 600 - 700 - 800 - 900
	*/
#pragma region Preparation

	BinaryTreeNode *root = new BinaryTreeNode();
	root->setdata(600);

	BinaryTreeNode *node1 = new BinaryTreeNode();
	node1->setdata(100);

	BinaryTreeNode *node2 = new BinaryTreeNode();
	node2->setdata(200);

	BinaryTreeNode *node3 = new BinaryTreeNode();
	node3->setdata(300);

	BinaryTreeNode *node4 = new BinaryTreeNode();
	node4->setdata(400);

	BinaryTreeNode *node5 = new BinaryTreeNode();
	node5->setdata(500);

	BinaryTreeNode *node7 = new BinaryTreeNode();
	node7->setdata(700);

	BinaryTreeNode *node8 = new BinaryTreeNode();
	node8->setdata(800);

	BinaryTreeNode *node9 = new BinaryTreeNode();
	node9->setdata(900);

	root->setleft(node4);
	root->setright(node8);

	node4->setleft(node2);
	node4->setright(node5);

	node8->setleft(node7);
	node8->setright(node9);

	node2->setleft(node1);
	node2->setright(node3);

#pragma endregion

#pragma region Execution

	InOrderRec(root);
	cout << "------------------------\n";
	cout << BST_CheckIfBST(root) << "\n";
	cout << BST_CheckIfBST_Recursive(root) << "\n";


	node5->setdata(615);

	InOrderRec(root);
	cout << "------------------------\n";
	cout << BST_CheckIfBST(root) << "\n";
	cout << BST_CheckIfBST_Recursive(root) << "\n";

#pragma endregion
}