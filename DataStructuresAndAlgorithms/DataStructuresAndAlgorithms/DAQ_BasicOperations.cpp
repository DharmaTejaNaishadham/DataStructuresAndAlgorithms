#include <iostream>
using namespace std;

//Including the class definiton and function prototypes of SAStack.h
#include "DAQueue.h"

int DAQ_IsEmptyQueue(DynamicArrayQueue * Queue)
{
	return (Queue->front == -1);
}

int DAQ_IsFullQueue(DynamicArrayQueue * Queue)
{
	return ((Queue->rear + 1) % Queue -> capacity == Queue->front);
}

void DAQ_Size(DynamicArrayQueue * Queue)
{
	if (Queue->front == Queue->rear)
		if (Queue->front == -1)
			cout << "\nsize = 0\n";
		else
			cout << "\nsize = " << Queue->rear + 1 - Queue->front << "\n";

	if (Queue->rear > Queue->front)
		cout << "\nsize = " << Queue->rear + 1 - Queue->front << "\n";//same front==rear && both != -1

	else if (Queue->rear < Queue->front)
		cout << "\nsize = " << Queue -> capacity - Queue->front + Queue->rear + 1 << "\n";

}

void DAQ_EnQueue(DynamicArrayQueue * Queue, int data)
{
	int size;

	if (DAQ_IsFullQueue(Queue))
	{
		size = Queue->capacity;
		Queue->capacity = Queue->capacity * 2;

		Queue->array = (int *)realloc(Queue->array, Queue->capacity);
		if (!Queue->array)
		{
			cout << "\nError occurred during memory reallocation :(\n";
			return;
		}

		if (Queue->front > Queue->rear)
		{
			for (int i = Queue->front; i < size - 1; i++)
			{
				Queue->array[size + i] = Queue->array[i];
				Queue->array[i] = 0;
			}
			Queue->front = Queue->front + size;
		}
	}

	Queue->rear = (Queue->rear + 1) % Queue->capacity;
	Queue->array[Queue->rear] = data;

	if (Queue->front == -1) Queue->front = Queue->rear;
}

int DAQ_DeQueue(DynamicArrayQueue * Queue)
{
	int data;
	if (!DAQ_IsEmptyQueue(Queue))
	{
		data = Queue->array[Queue->front];
		Queue->array[Queue->front] = 0;

		if (Queue->front == Queue->rear)	Queue->front = Queue->rear = -1;
		Queue->front = (Queue->front + 1) % Queue -> capacity;

		return data;
	}
	else
	{
		cout << "\nEmpty Queue\n";
		return NULL;
	}
}

void DAQ_Print(DynamicArrayQueue * Queue)
{

	cout << "\n-----------------------------------------------------------\n";
	cout << "Address of Queue: " << Queue << "\n";
	cout << "front: " << Queue->front << "\n";
	cout << "rear: " << Queue->rear << "\n";
	cout << "Elements: ";

	for (int i = 0; i < Queue -> capacity; i++)
	{
		cout << Queue->array[i] << "\t";
	}
	cout << "\n-----------------------------------------------------------\n";
}

void DAQ_Delete(DynamicArrayQueue * Queue)
{
	if (Queue)
	{		
		free(Queue);
		Queue->front = -1;
		Queue->rear = -1;
	}
}

void DAQ_BasicOperations_main()
{
	DynamicArrayQueue *Queue = new DynamicArrayQueue();

	DAQ_Size(Queue);
	DAQ_Print(Queue);


	DAQ_EnQueue(Queue, 10);
	DAQ_Size(Queue);
	DAQ_Print(Queue);

	DAQ_EnQueue(Queue, 20);
	DAQ_Size(Queue);
	DAQ_Print(Queue);

	DAQ_EnQueue(Queue, 30);
	DAQ_Size(Queue);
	DAQ_Print(Queue);

	DAQ_EnQueue(Queue, 40);
	DAQ_Size(Queue);
	DAQ_Print(Queue);


	DAQ_DeQueue(Queue);
	DAQ_Size(Queue);
	DAQ_Print(Queue);

	DAQ_DeQueue(Queue);
	DAQ_Size(Queue);
	DAQ_Print(Queue);

	DAQ_EnQueue(Queue, 50);
	DAQ_Size(Queue);
	DAQ_Print(Queue);

	DAQ_EnQueue(Queue, 60);
	DAQ_Size(Queue);
	DAQ_Print(Queue);


	DAQ_EnQueue(Queue, 70);
	DAQ_Size(Queue);
	DAQ_Print(Queue);

	DAQ_EnQueue(Queue, 80);
	DAQ_Size(Queue);
	DAQ_Print(Queue);


	DAQ_EnQueue(Queue, 90);
	DAQ_Size(Queue);
	DAQ_Print(Queue);

	DAQ_EnQueue(Queue, 100);
	DAQ_Size(Queue);
	DAQ_Print(Queue);


	DAQ_Delete(Queue);
	DAQ_Size(Queue);
	DAQ_Print(Queue);
}