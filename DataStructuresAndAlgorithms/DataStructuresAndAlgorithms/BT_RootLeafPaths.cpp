#include <iostream>
using namespace std;

#include "BTNQueueAndStack.h"
#include "SAStack.h"

SimpleArrayStack * stack = new SimpleArrayStack;

void RootLeafPaths_NonRec(BinaryTreeNode * root)
{
	if (root == NULL)	return;

	BinaryTreeStack * stack = new BinaryTreeStack();

	while (1)
	{
		while (root)
		{
			BTNS_Push(stack, root);		
			root = root->getleft();
		}

		if (BTNS_IsEmptyStack(stack))	
			break;		

		if ((stack->top)->getright() == NULL)
		{
			if ((stack->top)->getleft() == NULL)
				BTNS_Print(stack);
			
			root = BTNS_Pop(stack);						

			while (root == (stack->top)->getright())
			{
				root = BTNS_Pop(stack);			

				if (BTNS_IsEmptyStack(stack))
					break;
			}			
		}
		
		if (!BTNS_IsEmptyStack(stack))
		{			
			root = (stack->top)->getright();
		}
		else
		{
			break;
		}
	}
}

void RootLeafPaths(BinaryTreeNode * root)
{
	if (root != NULL)
	{
		if (root->getleft() != NULL || root->getright() != NULL)
		{
			SAS_Push(stack, root->getdata());

			RootLeafPaths(root->getleft());		
			RootLeafPaths(root->getright());
						
			SAS_Pop(stack);
		}
		else
		{	
			SAS_Push(stack, root->getdata());

			SAS_Print(stack);

			SAS_Pop(stack);
		}
	} 
}

void BT_RootLeafPaths_main()
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

	//RootLeafPaths(root);
	RootLeafPaths_NonRec(root);	

#pragma endregion
}