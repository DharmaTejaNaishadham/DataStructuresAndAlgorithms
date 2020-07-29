#include <iostream>
using namespace std;

#include "BTNQueueAndStack.h"

int BTNQ_IsEmptyQueue(BinaryTreeQueue * Queue)
{
	return (Queue->front == NULL);
}


void BTNQ_Size(BinaryTreeQueue * Queue)
{

}

void BTNQ_EnQueue(BinaryTreeQueue * Queue, BinaryTreeNode * node)
{	
	BinaryTreeNode *temp = new BinaryTreeNode();
	BinaryTreeNode *last = new BinaryTreeNode();

	if (Queue->front == NULL) 
	{
		node->setnext(NULL);
		Queue->rear = node; 
		Queue->front = Queue->rear;
		return;
	}
	else
	{
		node->setnext(NULL);
		Queue->rear = node;

		temp = Queue->front;
		while (temp)
		{
			last = temp;
			temp = temp->getnext();
		}
		(last)->setnext(Queue->rear);
	}

}

BinaryTreeNode * BTNQ_DeQueue(BinaryTreeQueue * Queue)
{
	BinaryTreeNode *temp = new BinaryTreeNode();
	
	if (BTNQ_IsEmptyQueue(Queue))
	{
		cout << "Queue is empty\n";
		return 0;
	}
	else
	{	
		temp = Queue->front;
		Queue->front = (Queue->front)->getnext();

		return temp;
	}
	
}

void BTNQ_Print(BinaryTreeQueue * Queue)
{
	cout << "\n-----------------------------------------------------------\n";
	cout << "Address of Queue: " << Queue << "\n";
	cout << "front: " << Queue->front << "\n";
	cout << "rear: " << Queue->rear << "\n";
	cout << "Elements: \n";

	cout << "Address = " << (Queue->front) << " Data = " << (Queue->front)->getdata() << " left = " << (Queue->front)->getleft() << "right = " << (Queue->front)->getright() << "\n";

	BinaryTreeNode *node = new BinaryTreeNode();
	node = (Queue->front)->getright();

	PreOrderRec(node);
	cout << "\n-----------------------------------------------------------\n";
}

void BTNQ_Delete(BinaryTreeQueue * Queue)
{
	BinaryTreeNode *node = new BinaryTreeNode();

	while (Queue->front) 
	{
		node = Queue->front;
		Queue->front = (Queue->front)->getright();		
		free(node);
	}
	//free(Queue->rear);
	free(Queue);
}

void BTNQ_BasicOperations_main()
{
	BinaryTreeQueue *Queue = new BinaryTreeQueue();

	BinaryTreeNode *node1 = new BinaryTreeNode();
	node1->setdata(10);
	BTNQ_EnQueue(Queue, node1);
	//BTNQ_Size(Queue);
	BTNQ_Print(Queue);

	BinaryTreeNode *node2 = new BinaryTreeNode();
	node2->setdata(20);
	BTNQ_EnQueue(Queue, node2);
	//BTNQ_Size(Queue);
	BTNQ_Print(Queue);

	BinaryTreeNode *node3 = new BinaryTreeNode();
	node3->setdata(30);
	BTNQ_EnQueue(Queue, node3);
	//BTNQ_Size(Queue);
	BTNQ_Print(Queue);

	BinaryTreeNode *node4 = new BinaryTreeNode();
	node4->setdata(40);
	BTNQ_EnQueue(Queue, node4);
	//BTNQ_Size(Queue);
	BTNQ_Print(Queue);


	BTNQ_DeQueue(Queue);
	//BTNQ_Size(Queue);
	BTNQ_Print(Queue);

	BTNQ_DeQueue(Queue);
	//BTNQ_Size(Queue);
	BTNQ_Print(Queue);

	BinaryTreeNode *node5 = new BinaryTreeNode();
	node5->setdata(50);
	BTNQ_EnQueue(Queue, node5);
	//BTNQ_Size(Queue);
	BTNQ_Print(Queue);

	BinaryTreeNode *node6 = new BinaryTreeNode();
	node6->setdata(60);
	BTNQ_EnQueue(Queue, node6);
	//BTNQ_Size(Queue);
	BTNQ_Print(Queue);

	BTNQ_DeQueue(Queue);
	//BTNQ_Size(Queue);
	BTNQ_Print(Queue);

	BinaryTreeNode *node7 = new BinaryTreeNode();
	node7->setdata(70);
	BTNQ_EnQueue(Queue, node7);
	//BTNQ_Size(Queue);
	BTNQ_Print(Queue);

	BinaryTreeNode *node8 = new BinaryTreeNode();
	node8->setdata(80);
	BTNQ_EnQueue(Queue, node8);
	//BTNQ_Size(Queue);
	BTNQ_Print(Queue);

	BTNQ_DeQueue(Queue);
	//BTNQ_Size(Queue);
	BTNQ_Print(Queue);

	BinaryTreeNode *node9 = new BinaryTreeNode();
	node9->setdata(90);
	BTNQ_EnQueue(Queue, node9);
	//BTNQ_Size(Queue);
	BTNQ_Print(Queue);


	BTNQ_Delete(Queue);
	//BTNQ_Size(Queue);
}