#include <iostream>
using namespace std;

#include "BTNQueueAndStack.h"

void LevelOrderReverse(BinaryTreeNode *root)
{
	BinaryTreeQueue * queue = new BinaryTreeQueue();
	BinaryTreeStack * stack = new BinaryTreeStack();
	BinaryTreeNode * temp = new BinaryTreeNode();

	if (root == NULL) return;
	BTNQ_EnQueue(queue, root);

	while (!BTNQ_IsEmptyQueue(queue))
	{
		temp = BTNQ_DeQueue(queue);

		if (temp->getleft())		BTNQ_EnQueue(queue, temp->getleft());
		if (temp->getright())	BTNQ_EnQueue(queue, temp->getright());

		BTNS_Push(stack, temp);		
	}

	while (!BTNS_IsEmptyStack(stack))
	{
		temp = BTNS_Pop(stack);
		cout << temp->getdata() << "\n";
	}
}

void BT_LevelOrderTraversalReverse_main()
{
	/*
						---- 1=root=100 ----
					/						\
				2=200						3=300
				/	\						/	\
			4=400	5=500				6=600	7=700
					/							\
				8=800							9=900
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

	node7->setright(node9);

#pragma endregion

#pragma region Execution

	LevelOrderReverse(root);

#pragma endregion
}