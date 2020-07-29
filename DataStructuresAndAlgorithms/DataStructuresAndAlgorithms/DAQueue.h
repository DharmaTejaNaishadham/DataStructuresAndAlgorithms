#include <iostream>
using namespace std;


class DynamicArrayQueue
{

	int size;

public:
	int front, rear;
	int * array;
	int capacity = 5;

	DynamicArrayQueue()
	{
		array = (int *)malloc(capacity * sizeof(int));
		for (int i = 0; i < capacity; i++)
		{
			array[i] = 0;
		}

		size = capacity;
		front = -1;
		rear = -1;
	}
};

int DAQ_IsEmptyQueue(DynamicArrayQueue * Queue);

int DAQ_IsFullQueue(DynamicArrayQueue * Queue);

void DAQ_Size(DynamicArrayQueue * Queue);

void DAQ_EnQueue(DynamicArrayQueue * Queue, int data);

int DAQ_DeQueue(DynamicArrayQueue * Queue);

void DAQ_Print(DynamicArrayQueue * Queue);

void DAQ_Delete(DynamicArrayQueue * Queue);

void DAQ_BasicOperations_main();