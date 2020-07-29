#include <iostream>
using namespace std;

#include "BT.h"

bool BST_FindElement_Rec(BinaryTreeNode * root, int key)
{
	if (root == NULL) return false;
		
	if (root->getdata() == key) return true;	
	else if (root->getdata() > key)	return BST_FindElement_Rec(root->getleft(), key);
	else return BST_FindElement_Rec(root->getright(), key);
}

bool BST_FindElement_NonRec(BinaryTreeNode * root, int key)
{
	if (root == NULL) return false;

	while (root)
	{
		if (root->getdata() == key)	return true;
		else if (root->getdata() > key) root = root->getleft();
		else root = root->getright();
	}

	return false;
}

void BST_FindElement_main()
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

	cout << BST_FindElement_Rec(root, 300) << "\n";
	cout << BST_FindElement_Rec(root, 600) << "\n";
	cout << BST_FindElement_Rec(root, 800) << "\n";
	cout << BST_FindElement_Rec(root, 250) << "\n";

	cout << BST_FindElement_NonRec(root, 700) << "\n";
	cout << BST_FindElement_NonRec(root, 600) << "\n";
	cout << BST_FindElement_NonRec(root, 100) << "\n";
	cout << BST_FindElement_NonRec(root, 250) << "\n";

	//---------------------------------------------------------------------
}