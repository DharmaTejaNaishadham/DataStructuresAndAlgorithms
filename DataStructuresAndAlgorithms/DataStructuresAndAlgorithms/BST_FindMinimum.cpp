#include <iostream>
using namespace std;

#include "BT.h"

BinaryTreeNode * BST_FindMin_Rec(BinaryTreeNode * root)
{
	if (root == NULL) return 0;

	if (root->getleft() == NULL) return root;
	else BST_FindMin_Rec(root->getleft());
}

BinaryTreeNode * BST_FindMin_NonRec(BinaryTreeNode * root)
{
	if (root == NULL) return false;

	while (root->getleft())
	{
		root = root->getleft();
	}

	return root;
}

void BST_FindMinimum_main()
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

	//InOrderRec(root);

	cout << (BST_FindMin_Rec(root))->getdata() << "\n";

	cout << (BST_FindMin_NonRec(root))->getdata() << "\n";

	//---------------------------------------------------------------------
}