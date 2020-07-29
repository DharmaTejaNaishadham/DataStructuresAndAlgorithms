#include <iostream>
using namespace std;

const int SimpleArrayQueue_Capacity = 5;

class SimpleArrayQueue
{
	
	int size;

public:
	int front, rear;
	int array[SimpleArrayQueue_Capacity];

	SimpleArrayQueue()
	{
		for (int i = 0; i < SimpleArrayQueue_Capacity; i++)
		{
			array[i] = 0;
		}
		
		size = SimpleArrayQueue_Capacity;
		front = -1;
		rear = -1;
	}
};

int SAQ_IsEmptyQueue(SimpleArrayQueue * Queue);

int SAQ_IsFullQueue(SimpleArrayQueue * Queue);

void SAQ_Size(SimpleArrayQueue * Queue);

void SAQ_EnQueue(SimpleArrayQueue * Queue, int data);

int SAQ_DeQueue(SimpleArrayQueue * Queue);

void SAQ_Print(SimpleArrayQueue * Queue);

void SAQ_Delete(SimpleArrayQueue * Queue);

void SAQ_BasicOperations_main();