#include <iostream>
using namespace std;

#include "BTNQueueAndStack.h"

int BT_Height(BinaryTreeNode* root)
{
	int leftHeight, rightHeight;

	if (root == NULL)
	{
		return 0;
	}
	else
	{
		if (root->getleft() != NULL)	leftHeight = BT_Height(root->getleft());
		else leftHeight = 0;
		if (root->getright() != NULL)	rightHeight = BT_Height(root->getright());
		else rightHeight = 0;

		if (leftHeight > rightHeight)
			return leftHeight + 1;
		else
			return rightHeight + 1;
	}
}

int BT_Height_NonRec(BinaryTreeNode* root)
{
	if (root == NULL)	return 0;

	int maxHeight = 0, currentHeight = 0;

	BinaryTreeStack* stack = new BinaryTreeStack();

	while (1)
	{
		while (root)
		{
			BTNS_Push(stack, root);
			currentHeight++;
			root = root->getleft();
		}

		if (BTNS_IsEmptyStack(stack))
			break;

		if (stack->top->getright() == NULL)
		{
			root = BTNS_Pop(stack);
			maxHeight = (maxHeight < currentHeight) ? currentHeight : maxHeight;
			currentHeight--;

			while (stack->top->getright() == root)
			{
				root = BTNS_Pop(stack);
				currentHeight--;

				if (BTNS_IsEmptyStack(stack))
					break;				
			}
		}

		if (!BTNS_IsEmptyStack(stack))
			root = stack->top->getright();
		else
			break;
	}

	return maxHeight;
}

void BT_Height_OR_Depth_main()
{
	/*
							---- 1=root=100 ----
						/							\
					2=200							3=300
					/	\							/	\
				4=400	5=500					6=600	7=700
							\					/        /
							9=900			8=800      10=1000
							/
						 11=1100
	*/

#pragma region Preparation

	BinaryTreeNode* root = new BinaryTreeNode();
	root->setdata(100);

	BinaryTreeNode* node2 = new BinaryTreeNode();
	node2->setdata(200);

	BinaryTreeNode* node3 = new BinaryTreeNode();
	node3->setdata(300);

	BinaryTreeNode* node4 = new BinaryTreeNode();
	node4->setdata(400);

	BinaryTreeNode* node5 = new BinaryTreeNode();
	node5->setdata(500);

	BinaryTreeNode* node6 = new BinaryTreeNode();
	node6->setdata(600);

	BinaryTreeNode* node7 = new BinaryTreeNode();
	node7->setdata(700);

	BinaryTreeNode* node8 = new BinaryTreeNode();
	node8->setdata(800);

	BinaryTreeNode* node9 = new BinaryTreeNode();
	node9->setdata(900);

	BinaryTreeNode* node10 = new BinaryTreeNode();
	node10->setdata(1000);

	root->setleft(node2);
	root->setright(node3);

	node2->setleft(node4);
	node2->setright(node5);

	node3->setleft(node6);
	node3->setright(node7);

	node6->setleft(node8);

	node5->setright(node9);

	node7->setleft(node10);
#pragma endregion

#pragma region Execution

	cout << "Height of the Binary Tree = " << BT_Height(root) << "\n";
	cout << "Height of the Binary Tree = " << BT_Height_NonRec(root) << "\n";

#pragma endregion

#pragma region Preparation

	BinaryTreeNode* node11 = new BinaryTreeNode();
	node11->setdata(1100);

	node9->setleft(node11);

#pragma endregion

#pragma region Execution

	cout << "Height of the Binary Tree = " << BT_Height(root) << "\n";
	cout << "Height of the Binary Tree = " << BT_Height_NonRec(root) << "\n";

#pragma endregion
}