#include <iostream>
using namespace std;

#include "BTNQueueAndStack.h"

int currentDistance = INT16_MAX;

int leftOrRightValue = 0;

//Needs correction
void NodesAtDistanceK(BinaryTreeNode * root, BinaryTreeNode * node, int k)
{
	if (root == NULL)	return;
	
	if (currentDistance != INT16_MAX)
	{
		if (currentDistance >= 0)
			currentDistance++;
		else
			currentDistance--;		
	}

	if (currentDistance == k || currentDistance == -k)
		cout << root->getdata() << "\n";

	if (root == node)	currentDistance = 0;
	
	if (leftOrRightValue == 1)
	{
		NodesAtDistanceK(root->getleft(), node, k);
		NodesAtDistanceK(root->getright(), node, k);
	}
	else if (leftOrRightValue == 2)
	{
		NodesAtDistanceK(root->getright(), node, k);
		NodesAtDistanceK(root->getleft(), node, k);
	}
	else
	{
		return;
	}

	if (currentDistance != INT16_MAX)
	{
		if (currentDistance >= 0)
			currentDistance--;
		else
			currentDistance++;	
	}
}

void PrintNodesAtDistanceK(BinaryTreeNode * root, BinaryTreeNode * node, int k)
{
	currentDistance = INT16_MAX;

	leftOrRightValue = LeftOrRight(root, node);

	NodesAtDistanceK(root, node, k);
}

void BT_NodesAtDistanceK_main()
{
	/*
								---- 1=root=100 ----
						   	/						\
						2=200						3=300
						/	\						/	\
					4=400	5=500				6=600	7=700
							/						\
						8=800						9=900
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

	BinaryTreeNode *node9 = new BinaryTreeNode();
	node9->setdata(900);

	root->setleft(node2);
	root->setright(node3);

	node2->setleft(node4);
	node2->setright(node5);

	node3->setleft(node6);
	node3->setright(node7);

	node5->setleft(node8);

	node6->setright(node9);

#pragma endregion

#pragma region Execution

	cout << "Nodes at distance k from the given node are: \n";
	PrintNodesAtDistanceK(root, node2, 2);

	cout << "Nodes at distance k from the given node are: \n";
	PrintNodesAtDistanceK(root, node3, 2);

	cout << "Nodes at distance k from the given node are: \n";
	PrintNodesAtDistanceK(root, node8, 2);

	cout << "Nodes at distance k from the given node are: \n";
	PrintNodesAtDistanceK(root, node8, 5);

#pragma endregion
}