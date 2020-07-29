#include <iostream>
using namespace std;

#include "BTNQueueAndStack.h"

bool BTNS_IsEmptyStack(BinaryTreeStack * Stack)
{
	return (Stack->top == NULL);
}

void BTNS_Push(BinaryTreeStack * Stack, BinaryTreeNode * newNode)
{
	BinaryTreeNode *temp = new BinaryTreeNode();

	if (!BTNS_IsEmptyStack(Stack))
	{
		temp = Stack->top;
		Stack->top = newNode;
		(Stack->top)->setnext(temp);
	}
	else
	{
		Stack->top = newNode;
		(Stack->top)->setnext(NULL);//just in case newNode comes in with next pointer already set :p (It happened! Remember? = Threaded trees...finding successor :p
	}
}

BinaryTreeNode * BTNS_Pop(BinaryTreeStack * Stack)
{
	BinaryTreeNode *temp = new BinaryTreeNode();

	if (!BTNS_IsEmptyStack(Stack))
	{
		temp = Stack->top;
		Stack->top = (Stack->top)->getnext();
		return temp;
	}
	else
	{
		cout << "Stack is empty\n";
		return 0;
	}

}

void BTNS_Print(BinaryTreeStack * Stack)
{
	BinaryTreeNode *temp = new BinaryTreeNode();
	temp = Stack->top;

	cout << "Stack as of now:\n";
	while (temp)
	{
		cout << temp->getdata() << "\n";
		temp = temp->getnext();
	}

}

void BTNS_Delete(BinaryTreeStack * Stack)
{
	BinaryTreeNode *temp = new BinaryTreeNode();
	while (Stack->top)
	{
		temp = Stack->top;
		Stack->top = (Stack->top)->getnext();

		free(temp);
	}
}

void BTNS_BasicOperations_main()
{
	BinaryTreeStack *Stack = new BinaryTreeStack();

	BinaryTreeNode *node1 = new BinaryTreeNode();
	node1->setdata(10);
	BTNS_Push(Stack, node1);
	//BTNQ_Size(Stack);
	BTNS_Print(Stack);

	BinaryTreeNode *node2 = new BinaryTreeNode();
	node2->setdata(20);
	BTNS_Push(Stack, node2);
	//BTNQ_Size(Stack);
	BTNS_Print(Stack);

	BinaryTreeNode *node3 = new BinaryTreeNode();
	node3->setdata(30);
	BTNS_Push(Stack, node3);
	//BTNQ_Size(Stack);
	BTNS_Print(Stack);

	BinaryTreeNode *node4 = new BinaryTreeNode();
	node4->setdata(40);
	BTNS_Push(Stack, node4);
	//BTNQ_Size(Stack);
	BTNS_Print(Stack);


	BTNS_Pop(Stack);
	//BTNQ_Size(Stack);
	BTNS_Print(Stack);

	BTNS_Pop(Stack);
	//BTNQ_Size(Stack);
	BTNS_Print(Stack);

	BinaryTreeNode *node5 = new BinaryTreeNode();
	node5->setdata(50);
	BTNS_Push(Stack, node5);
	//BTNQ_Size(Stack);
	BTNS_Print(Stack);

	BinaryTreeNode *node6 = new BinaryTreeNode();
	node6->setdata(60);
	BTNS_Push(Stack, node6);
	//BTNQ_Size(Stack);
	BTNS_Print(Stack);

	BTNS_Pop(Stack);
	//BTNQ_Size(Stack);
	BTNS_Print(Stack);

	BinaryTreeNode *node7 = new BinaryTreeNode();
	node7->setdata(70);
	BTNS_Push(Stack, node7);
	//BTNQ_Size(Stack);
	BTNS_Print(Stack);

	BinaryTreeNode *node8 = new BinaryTreeNode();
	node8->setdata(80);
	BTNS_Push(Stack, node8);
	//BTNQ_Size(Stack);
	BTNS_Print(Stack);

	BTNS_Pop(Stack);
	//BTNQ_Size(Stack);
	BTNS_Print(Stack);

	BinaryTreeNode *node9 = new BinaryTreeNode();
	node9->setdata(90);
	BTNS_Push(Stack, node9);
	//BTNQ_Size(Stack);
	BTNS_Print(Stack);


	BTNS_Delete(Stack);
	//BTNQ_Size(Stack);
}