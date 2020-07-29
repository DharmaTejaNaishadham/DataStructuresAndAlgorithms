#include <iostream>
using namespace std;

#include "BTNQueueAndStack.h"

//simple eh be faltu ga...ekuva aalochistunav...falling right into the traps of the question...work more on non recursive traversals 
BinaryTreeNode * DeepestNode(BinaryTreeNode * root)
{
	BinaryTreeQueue *Queue = new BinaryTreeQueue();
	BinaryTreeNode * temp = new BinaryTreeNode;

	if (root == NULL) return NULL;
	BTNQ_EnQueue(Queue, root);

	while(!BTNQ_IsEmptyQueue(Queue))
	{
		temp = BTNQ_DeQueue(Queue);

		if (temp->getleft())	BTNQ_EnQueue(Queue, temp->getleft());
		if (temp->getright())	BTNQ_EnQueue(Queue, temp->getright());
	}
	BTNQ_Delete(Queue);
	return temp;
}

void BT_DeepestNode_main()
{
	/*
									---- 1=root=100 ----
								/						\
							2=200						3=300
							/	\						/	\
						4=400	5=500				6=600	7=700
													/
												8=800
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

	cout << "Deepest Node is " << DeepestNode(root)->getdata() << "\n";

#pragma endregion
}