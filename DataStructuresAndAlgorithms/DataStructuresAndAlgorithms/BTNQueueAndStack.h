#include <iostream>
using namespace std;

#include "BT.h"

class BinaryTreeQueue
{
public:

	BinaryTreeNode *front;
	BinaryTreeNode *rear;

	BinaryTreeQueue()
	{
		front = NULL; rear = NULL;
	}
};

int BTNQ_IsEmptyQueue(BinaryTreeQueue * Queue);

void BTNQ_Size(BinaryTreeQueue * Queue);

void BTNQ_EnQueue(BinaryTreeQueue * Queue, BinaryTreeNode * node);

BinaryTreeNode * BTNQ_DeQueue(BinaryTreeQueue * Queue);

void BTNQ_Print(BinaryTreeQueue * Queue);

void BTNQ_Delete(BinaryTreeQueue * Queue);


//-----------------------------------------------------------------------//

class BinaryTreeStack
{
public:

	BinaryTreeNode *top;

	BinaryTreeStack()
	{
		top = NULL;
	}
};



bool BTNS_IsEmptyStack(BinaryTreeStack * Stack);

void BTNS_Push(BinaryTreeStack * Stack, BinaryTreeNode * newNode);

BinaryTreeNode * BTNS_Pop(BinaryTreeStack * Stack);

void BTNS_Print(BinaryTreeStack * Stack);

void BTNS_Delete(BinaryTreeStack * Stack);