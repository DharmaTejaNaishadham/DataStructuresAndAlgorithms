#include <iostream>
using namespace std;

const int SimpleArrayStack_Capacity = 5;

class SimpleArrayStack
{
	public:

	int top;
	int array[SimpleArrayStack_Capacity];

	SimpleArrayStack()
	{
		top = -1;
		for (int i = 0; i < SimpleArrayStack_Capacity; i++)
		{
			array[i] = NULL;
		}
	}
};


bool SAS_IsEmptyStack(SimpleArrayStack * Stack);

bool SAS_IsFullStack(SimpleArrayStack * Stack);

void SAS_Push(SimpleArrayStack * Stack, int data);

int SAS_Pop(SimpleArrayStack * Stack);

void SAS_Print(SimpleArrayStack * Stack);

void SAS_Delete(SimpleArrayStack * Stack);

void SAS_BasicOperations_main();

