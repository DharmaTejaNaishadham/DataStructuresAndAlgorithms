#include <iostream>
using namespace std;

#include "BTNQueueAndStack.h"

void PreOrderNonRec(BinaryTreeNode *root)//got lucky...commented part works...as it is the simplest traversal
{
	BinaryTreeStack *Stack = new BinaryTreeStack();

	if (root == NULL)
	{
		cout << "Binary Tree is empty\n";
	}
	else
	{
		/*BTNS_Push(Stack, root);

		while (!BTNS_IsEmptyStack(Stack))
		{
			forPrint = BTNS_Pop(Stack);
			cout << forPrint->getdata() << "\n";

			if (forPrint->getright() != NULL)	BTNS_Push(Stack, forPrint->getright());
			if (forPrint->getleft() != NULL)	BTNS_Push(Stack, forPrint->getleft());
		}*/

		while (1)//aagakunda tree anta tiragamani...we exit out of this, when there is nothing left to pop from stack
		{
			while (root)//this will end when we reach the end of the branch
			{
				cout << root->getdata() << "\n";//printing/processing the node

				BTNS_Push(Stack, root);//pushing all the left nodes of the tree in stack

				root = root->getleft();//this is to explore the left tree of the root/processed node
			}

			if (BTNS_IsEmptyStack(Stack))	break;//cases in which there is no left tree

			root = BTNS_Pop(Stack);//all left nodes are pushed in stack...this is to traverse the remaining tree of those left nodes

			root = root->getright();//remaining tree = right tree
		}
	}
}

void InOrderNonRec(BinaryTreeNode *root)
{
	BinaryTreeStack *Stack = new BinaryTreeStack();

	if (root == NULL)
	{
		cout << "Binary Tree is empty\n";
	}
	else
	{

		while (1)
		{
			while (root)
			{
				/*only diff. in implmenting Pre & In order - head is processed in between left and right.
				hence, the print is moved to the line just before we start processing the right tree of each node.
				------look at the comments of pre order in case of any confusion-------
				*/
				//cout << root->getdata() << "\n";//printing/processing the node

				BTNS_Push(Stack, root);

				root = root->getleft();
			}

			if (BTNS_IsEmptyStack(Stack))	break;

			root = BTNS_Pop(Stack);

			cout << root->getdata() << "\n";//printing/processing the node

			root = root->getright();
		}
	}
}

/*
it is the complicated traversal among the 3.
Reason - We have to POP the element out of Stack iff left and right trees/nodes are processed.
Meaning - We cannot POP the element after mere left tree completion
Difficulty - When you are about to POP the element, how would you know whether you are coming from left or right
Solution - check if the element u r coming from and the Right of the (top = element that would be popped) of the stack are same
Example -	consider 4->2<-5 nodes
			when we visit 2 from 4:
			element we are coming from - 4
			top of the stack - 2
			right of stack - 5

			when we visit 2 from 5:
			element we are coming from - 5
			top of the stack - 2
			right of stack - 5
			This is when you know that right tree has finished. You can now pop 2.

*/
void PostOrderNonRec(BinaryTreeNode *root)
{
	BinaryTreeStack *Stack = new BinaryTreeStack();

	if (root == NULL)
		cout << "Binary Tree is empty\n";
	
	while (1)
	{
		while (root)//traversing just the left tree/nodes
		{
			BTNS_Push(Stack, root);
			root = root->getleft();
		}

		if (BTNS_IsEmptyStack(Stack))
		{
			break;//one would break from this only when the provided root/tree is empty
		}

		if ((Stack->top)->getright() == NULL)//you've reached the leaf nodes
		{
			root = BTNS_Pop(Stack);
			cout << root->getdata() << "\n";//printing/processing the node

			while (root == (Stack->top)->getright())//condition that gets trigerred while returning from right trees to root
			{
				cout << (Stack->top)->getdata() << "\n";//printing/processing the node
				root = BTNS_Pop(Stack);

				if (BTNS_IsEmptyStack(Stack))
				{
					break;//
				}
			}
		}

		if (!BTNS_IsEmptyStack(Stack))//cases to handle root - no left tree, but has right tree
		{
			root = (Stack->top)->getright();
		}
		else
		{
			break;
		}
	}
}

void BT_NonRecursiveTraversals_main()
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

	cout << "Pre Order :\n";
	PreOrderNonRec(root);

	cout << "In Order :\n";
	InOrderNonRec(root);

	cout << "Post Order :\n";
	PostOrderNonRec(root);

#pragma endregion
}