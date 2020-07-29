#include <iostream>
using namespace std;

//Including the class definiton and function prototypes of SAStack.h
#include "SAQueue.h"

int SAQ_IsEmptyQueue(SimpleArrayQueue * Queue)
{
	return (Queue->front == -1);
}

int SAQ_IsFullQueue(SimpleArrayQueue * Queue)
{
	return ((Queue->rear + 1) % SimpleArrayQueue_Capacity == Queue->front);
}

void SAQ_Size(SimpleArrayQueue * Queue)
{
	if (Queue->front == Queue->rear)
		if (Queue->front == -1)
			cout << "\nsize = 0\n";
		else
			cout << "\nsize = " << Queue->rear + 1 - Queue->front << "\n";

	if (Queue->rear > Queue->front)
		cout << "\nsize = " << Queue->rear + 1 - Queue->front << "\n";//same front==rear && both != -1

	else if (Queue->rear < Queue->front)
		cout << "\nsize = " << SimpleArrayQueue_Capacity - Queue->front + Queue->rear + 1 << "\n";

}

void SAQ_EnQueue(SimpleArrayQueue * Queue, int data)
{
	if (!SAQ_IsFullQueue(Queue))
	{
		Queue->rear = (Queue->rear + 1) % SimpleArrayQueue_Capacity;
		Queue->array[Queue->rear] = data;

		if (Queue->front == -1) Queue->front = Queue->rear;
	}
	else
	{
		cout << "\nQueue Overflow\n";
	}
}

int SAQ_DeQueue(SimpleArrayQueue * Queue)
{
	int data;
	if (!SAQ_IsEmptyQueue(Queue))
	{
		data = Queue->array[Queue->front];
		Queue->array[Queue->front] = 0;

		if (Queue->front == Queue->rear)	Queue->front = Queue->rear = -1;
		Queue->front = (Queue->front + 1) % SimpleArrayQueue_Capacity;

		return data;
	}
	else
	{
		cout << "\nEmpty Queue\n";
		return NULL;
	}
}

void SAQ_Print(SimpleArrayQueue * Queue)
{

	cout << "\n-----------------------------------------------------------\n";
	cout << "Address of Queue: " << Queue << "\n";
	cout << "front: " << Queue->front << "\n";
	cout << "rear: " << Queue->rear << "\n";
	cout << "Elements: ";

	for (int i = 0; i < SimpleArrayQueue_Capacity; i++)
	{
		cout << Queue->array[i] << "\t";
	}
	cout << "\n-----------------------------------------------------------\n";
}

void SAQ_Delete(SimpleArrayQueue * Queue)
{
	if (Queue)
	{		
		free(Queue);
		Queue->front = -1;
		Queue->rear = -1;
	}
}

void SAQ_BasicOperations_main()
{
	SimpleArrayQueue *Queue = new SimpleArrayQueue();

	SAQ_Size(Queue);
	SAQ_Print(Queue);


	SAQ_EnQueue(Queue, 10);
	SAQ_Size(Queue);
	SAQ_Print(Queue);

	SAQ_EnQueue(Queue, 20);
	SAQ_Size(Queue);
	SAQ_Print(Queue);

	SAQ_EnQueue(Queue, 30);
	SAQ_Size(Queue);
	SAQ_Print(Queue);

	SAQ_EnQueue(Queue, 40);
	SAQ_Size(Queue);
	SAQ_Print(Queue);


	SAQ_DeQueue(Queue);
	SAQ_Size(Queue);
	SAQ_Print(Queue);

	SAQ_DeQueue(Queue);
	SAQ_Size(Queue);
	SAQ_Print(Queue);

	SAQ_EnQueue(Queue, 50);
	SAQ_Size(Queue);
	SAQ_Print(Queue);

	SAQ_EnQueue(Queue, 60);
	SAQ_Size(Queue);
	SAQ_Print(Queue);


	SAQ_EnQueue(Queue, 70);
	SAQ_Size(Queue);
	SAQ_Print(Queue);

	SAQ_EnQueue(Queue, 80);
	SAQ_Size(Queue);
	SAQ_Print(Queue);


	SAQ_EnQueue(Queue, 90);
	SAQ_Size(Queue);
	SAQ_Print(Queue);


	SAQ_Delete(Queue);
	SAQ_Size(Queue);
	SAQ_Print(Queue);
}