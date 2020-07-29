#include <iostream>
using namespace std;

#include "BT.h"

BinaryTreeNode * BST_LCA_ShortestPath(BinaryTreeNode * root, BinaryTreeNode * alpha, BinaryTreeNode * beta)
{
	if (root && alpha && beta)
	{
		while (1)
		{
			/*
			kinda If condition ni chala better cheyochu...ela savagotte badulu
			if(alpha > beta)
			{
				if(beta < root < alpha) return root;
			}
			else
			{
				if(alpha < root < beta) return root;
			}
			
			ela chetha laga rayadam valla, we are missing the last case BST_LCA_ShortestPath(root, node9, root)
			Ideally the LCA should be 600...but we are getting 800.
			*/
			if ((alpha->getdata() < root->getdata() && root->getdata() <= beta->getdata()) || (beta->getdata() < root->getdata() && root->getdata() <= alpha->getdata()))
				return root;

			if (alpha->getdata() < root->getdata())
			{
				root = root->getleft();
			}
			else
			{
				root = root->getright();
			}
		}
	}
	else
	{
		return NULL;
	}
}

void BST_LCA_ShortestPath_main()
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
	cout << "------------------------\n";

	cout << "LCA of nodes " << node1->getdata() << " and " << node5->getdata() << " : " << (BST_LCA_ShortestPath(root, node1, node5))->getdata() << "\n";
	cout << "LCA of nodes " << node3->getdata() << " and " << node8->getdata() << " : " << (BST_LCA_ShortestPath(root, node3, node8))->getdata() << "\n";
	cout << "LCA of nodes " << node1->getdata() << " and " << root->getdata() << " : " << (BST_LCA_ShortestPath(root, node1, root))->getdata() << "\n";
	cout << "LCA of nodes " << node7->getdata() << " and " << node5->getdata() << " : " << (BST_LCA_ShortestPath(root, node7, node5))->getdata() << "\n";
	cout << "LCA of nodes " << node9->getdata() << " and " << root->getdata() << " : " << (BST_LCA_ShortestPath(root, node9, root))->getdata() << "\n";
	//---------------------------------------------------------------------
}