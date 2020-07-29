#include <iostream>
using namespace std;

#include "BT.h"

int max(int num1, int num2)
{
	return (num1 >= num2) ? num1 : num2;
}

int Diameter(BinaryTreeNode * root)
{
	if (root == NULL)
		return 0;
	/*
	The diameter of a tree (sometimes called the width) is the number of nodes on the longest path between two leaves in the tree. 
	-------------------------------------------------------------------
	The diameter of a tree T is the largest of the following quantities:
	* the diameter of T’s left subtree
	* the diameter of T’s right subtree
	* the longest path between leaves that goes through the root of T (this can be computed from the heights of the subtrees of T) => left height + right height + 1
	*/

	int lHeight = 0, rHeight = 0, lDiameter = 0, rDiameter = 0;

	if (root->getleft())
		lHeight = BT_Height(root->getleft());
	else
		lHeight = 0;

	if (root->getright())
		rHeight = BT_Height(root->getright());
	else
		rHeight = 0;

	lDiameter = Diameter(root->getleft());
	rDiameter = Diameter(root->getright());

	return max(lHeight + rHeight + 1, max(lDiameter, rDiameter));
}

void BT_DiameterOrWidth_main()
{
	/*
									---- 1=root=100 ----
								/						\
							2=200						3=300
							/	\						/	\                 Diameter = 6(5,2,1,3,6,8)
						4=400	5=500				6=600	7=700
													/
												8=800
					------------------------------------------------
									---- 1=root=100 ----
								/							   \
							2=200							  3=300
							/	\						/				\
						4=400	5=500				6=600				7=700
													/	 \					\
												8=800	9=900				10=1000			Diamter = 9(14,12,8,6,3,7,10,13,15)		
												/	\						/		
										11=1100	     12=1200	  	     13=1300
													/					 /
												14=1400				15=1500
										
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

	cout << "Diameter is " << Diameter(root) << "\n";

#pragma endregion

#pragma region Preparation

	BinaryTreeNode *node9 = new BinaryTreeNode();
	node9->setdata(900);

	BinaryTreeNode *node10 = new BinaryTreeNode();
	node10->setdata(1000);

	BinaryTreeNode *node11 = new BinaryTreeNode();
	node11->setdata(1100);

	BinaryTreeNode *node12 = new BinaryTreeNode();
	node12->setdata(1200);

	BinaryTreeNode *node13 = new BinaryTreeNode();
	node13->setdata(1300);

	BinaryTreeNode *node14 = new BinaryTreeNode();
	node14->setdata(1400);

	BinaryTreeNode *node15 = new BinaryTreeNode();
	node15->setdata(1500);

	node6->setright(node9);
	node7->setright(node10);
	node8->setleft(node11);
	node8->setright(node12);
	node10->setleft(node13);
	node12->setleft(node14);
	node13->setleft(node15);

#pragma endregion

#pragma region Execution

	cout << "Diameter is " << Diameter(root) << "\n";

#pragma endregion
}