#include <iostream>
using namespace std;

#include "BTNQueueAndStack.h"

BinaryTreeNode * BST_ClosestElementToKey_NonRec_Clean(BinaryTreeNode * root, int k)
{	
	if (root == NULL) return NULL;

	BinaryTreeNode * closest = new BinaryTreeNode();
	closest->setdata(INT16_MIN);

	while(root)
	{ 
		if (abs(root->getdata() - k) < abs(closest->getdata() - k))
		{
			closest = root;

			if (abs(root->getdata() - k) == 0)	break;
		}
		else
		{
			break;
		}
		
		if (root->getdata() > k)
		{
			root = root->getleft();
		}
		else
		{
			root = root->getright();
		}
	}

	return closest;
}

BinaryTreeNode * BST_ClosestElementToKey(BinaryTreeNode * root, int k)
{
	BinaryTreeStack * Stack = new BinaryTreeStack();

	BinaryTreeNode * left = new BinaryTreeNode();
	BinaryTreeNode * right = new BinaryTreeNode();
	left->setdata(INT16_MIN);
	right->setdata(INT16_MAX);

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

			if (root->getdata() < k && root->getdata() > left->getdata())
				left = root;

			if (root->getdata() > k && root->getdata() < right->getdata())
				right = root;
							
			root = root->getright();
		}

		return ((k - left->getdata()) < (right->getdata() - k)) ? left : right;
	}


}

void BST_ClosestElementToKey_main()//
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
	root->setdata(640);

	BinaryTreeNode *node1 = new BinaryTreeNode();
	node1->setdata(120);

	BinaryTreeNode *node2 = new BinaryTreeNode();
	node2->setdata(260);

	BinaryTreeNode *node3 = new BinaryTreeNode();
	node3->setdata(320);

	BinaryTreeNode *node4 = new BinaryTreeNode();
	node4->setdata(410);

	BinaryTreeNode *node5 = new BinaryTreeNode();
	node5->setdata(520);

	/*BinaryTreeNode *node6 = new BinaryTreeNode();
	node6->setdata(600);*/

	BinaryTreeNode *node7 = new BinaryTreeNode();
	node7->setdata(700);

	BinaryTreeNode *node8 = new BinaryTreeNode();
	node8->setdata(890);

	BinaryTreeNode *node9 = new BinaryTreeNode();
	node9->setdata(980);

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


	
	cout << "Closest Element to 200 = " << (BST_ClosestElementToKey_NonRec_Clean(root, 200))->getdata() << "\n";
	cout << "Closest Element to 510 = " << (BST_ClosestElementToKey_NonRec_Clean(root, 510))->getdata() << "\n";
	cout << "Closest Element to 100 = " << (BST_ClosestElementToKey_NonRec_Clean(root, 100))->getdata() << "\n";
	cout << "Closest Element to 800 = " << (BST_ClosestElementToKey_NonRec_Clean(root, 800))->getdata() << "\n";
	cout << "Closest Element to 300 = " << (BST_ClosestElementToKey_NonRec_Clean(root, 300))->getdata() << "\n";
	
	cout << "----------------------------\n";

	cout << "Closest Element to 200 = " << (BST_ClosestElementToKey(root, 200))->getdata() << "\n";
	cout << "Closest Element to 510 = " << (BST_ClosestElementToKey(root, 510))->getdata() << "\n";
	cout << "Closest Element to 100 = " << (BST_ClosestElementToKey(root, 100))->getdata() << "\n";
	cout << "Closest Element to 800 = " << (BST_ClosestElementToKey(root, 800))->getdata() << "\n";
	cout << "Closest Element to 300 = " << (BST_ClosestElementToKey(root, 300))->getdata() << "\n";
	//---------------------------------------------------------------------
}