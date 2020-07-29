#include <iostream>
using namespace std;

#include "BT.h"

BinaryTreeNode * BST_InsertElement_NonRec(BinaryTreeNode * root, int data)
{
	BinaryTreeNode * currentPos;
	BinaryTreeNode * newNode = new BinaryTreeNode();

	if (root == NULL)
	{
		root = new BinaryTreeNode();
		root->setdata(data);
		return root;
	}

	currentPos = root;
	while (1)
	{
		if (currentPos->getdata() > data)
		{
			if (currentPos->getleft())
			{
				currentPos = currentPos->getleft();
			}
			else
			{
				newNode->setdata(data);
				currentPos->setleft(newNode);
				return root;
			}
		}
		else//if (currentPos->getdata() <= data)
		{
			if (currentPos->getright())
			{
				currentPos = currentPos->getright();
			}
			else
			{
				newNode->setdata(data);
				currentPos->setright(newNode);
				return root;
			}
		}
	}
}

BinaryTreeNode * BST_InsertElement_Rec(BinaryTreeNode * root, int data)
{
	if (root == NULL)
	{
		root = new BinaryTreeNode();
		root->setdata(data);
		return root;
	}

	if (root->getdata() > data)
	{
		root->setleft(BST_InsertElement_Rec(root->getleft(), data));
	}
	else
	{
		root->setright(BST_InsertElement_Rec(root->getright(), data));
	}
}

void BST_InsertElement_main()
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

	BinaryTreeNode * empty = new BinaryTreeNode();
	empty = BST_InsertElement_NonRec(NULL, 550);
	InOrderRec(empty);

	root = BST_InsertElement_NonRec(root, 550);
	root = BST_InsertElement_NonRec(root, 250);
	root = BST_InsertElement_NonRec(root, 750);
	root = BST_InsertElement_NonRec(root, 850);
	root = BST_InsertElement_NonRec(root, 650);

	cout << "------------\n";
	InOrderRec(root);


	root = BST_InsertElement_NonRec(root, 650);
	
	cout << "------------\n";
	InOrderRec(root);



	root = BST_InsertElement_Rec(root, 450);
	root = BST_InsertElement_Rec(root, 350);
	root = BST_InsertElement_Rec(root, 950);

	cout << "------------\n";
	InOrderRec(root);
	//---------------------------------------------------------------------
}