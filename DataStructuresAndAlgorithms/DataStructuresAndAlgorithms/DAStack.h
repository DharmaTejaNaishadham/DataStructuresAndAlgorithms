#include <iostream>
using namespace std;


class DynamicArrayStack
{
public:

	int top;
	int capacity;
	int *array;

	DynamicArrayStack()
	{
		top = -1;
		capacity = 5;
		array = (int*)malloc(capacity * sizeof(int));// new int;
	}
};


bool DAS_IsEmptyStack(DynamicArrayStack * Stack);

bool DAS_IsFullStack(DynamicArrayStack * Stack);

void DAS_Push(DynamicArrayStack * Stack, int data);

int DAS_Pop(DynamicArrayStack * Stack);

void DAS_Print(DynamicArrayStack * Stack);

void DAS_Delete(DynamicArrayStack * Stack);

void DAS_BasicOperations_main();

