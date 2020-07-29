#include <iostream>
using namespace std;

#include "BTNQueueAndStack.h"

BinaryTreeNode * BST_KthSmallestElement(BinaryTreeNode * root, int k)
{
	BinaryTreeStack * Stack = new BinaryTreeStack();

	int countPoppedElements = 0;

	if (root == NULL)
	{
		cout << "Binary Tree is empty\n";
		return NULL;
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
			
			countPoppedElements++;
			if (countPoppedElements == k)	return root;

			root = root->getright();
		}
	}
}

void BST_KthSmallestElement_main()//BST_KthSmallest_
{
	//----------------------------------------------------------------------------------------------------
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
	//----------------------------------------------------------------------------------------------------


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

	/*BinaryTreeNode *node6 = new BinaryTreeNode();
	node6->setdata(600);*/

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

	//---------------------------------------------------------------------
	InOrderRec(root);
	cout << "----------------------------\n";


	cout << "2nd smallest Element = " << (BST_KthSmallestElement(root, 2))->getdata() << "\n";
	cout << "5th smallest Element = " << (BST_KthSmallestElement(root, 5))->getdata() << "\n";
	cout << "9th smallest Element = " << (BST_KthSmallestElement(root, 9))->getdata() << "\n";
	cout << "1st smallest Element = " << (BST_KthSmallestElement(root, 1))->getdata() << "\n";
	cout << "3rd smallest Element = " << (BST_KthSmallestElement(root, 3))->getdata() << "\n";
	//---------------------------------------------------------------------
}