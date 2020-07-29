#include <iostream>
using namespace std;

//Including the class definiton and function prototypes of SAStack.h
#include "DAStack.h"

bool DAS_IsEmptyStack(DynamicArrayStack * Stack)
{
	if (Stack->top == -1) return true; else return false;
}

bool DAS_IsFullStack(DynamicArrayStack * Stack)
{
	if (Stack->top == Stack->capacity - 1) return true; else return false;
}

void DAS_Push(DynamicArrayStack * Stack, int data)
{
	if (!DAS_IsFullStack(Stack))
	{
		Stack->array[Stack->top + 1] = data;
		Stack->top++;
	}
	else
	{
		Stack->capacity *= 2;
		
		int * newpointer;
		newpointer = (int*) realloc(Stack->array, Stack->capacity);

		if (newpointer == NULL)
		{
			cout << "So, that's why u r seeing garbage values\n";
		}
		else
		{
			Stack->array = newpointer;
		}
		
		if (Stack != NULL)
		{
			Stack->array[Stack->top + 1] = data;
			Stack->top++;
		}
		
		//It's all about avoiding this
		//cout << "Stack Overflow\n";
	}
}

int DAS_Pop(DynamicArrayStack * Stack)
{
	if (!DAS_IsEmptyStack(Stack))
	{
		int elementAtTop = Stack->array[Stack->top];
		Stack->array[Stack->top] = NULL;
		Stack->top--;

		return elementAtTop;
	}
	else
	{
		cout << "Stack Underflow\n";
		return NULL;
	}
}

void DAS_Print(DynamicArrayStack * Stack)
{
	cout << "\n-----------------------------------------------------------\n";
	cout << "Address of Stack: " << Stack << "\n";
	cout << "Top: " << Stack->top << "\n";
	cout << "Elements: ";

	for (int i = 0; i < Stack->capacity; i++)
	{
		cout << Stack->array[i] << "\t";
	}
	cout << "\n-----------------------------------------------------------\n";

}

void DAS_Delete(DynamicArrayStack * Stack)
{
	free(Stack);
}



void DAS_BasicOperations_main()
{
	DynamicArrayStack *Stack = new DynamicArrayStack();

	DAS_Print(Stack);

	DAS_Push(Stack, 10);
	DAS_Print(Stack);

	DAS_Push(Stack, 20);
	DAS_Print(Stack);

	DAS_Push(Stack, 30);
	DAS_Print(Stack);

	DAS_Push(Stack, 40);
	DAS_Print(Stack);

	DAS_Push(Stack, 50);
	DAS_Print(Stack);

	DAS_Push(Stack, 60);
	DAS_Print(Stack);

	DAS_Push(Stack, 70);
	DAS_Print(Stack);

	DAS_Push(Stack, 80);
	DAS_Print(Stack);

	DAS_Push(Stack, 90);
	DAS_Print(Stack);

	DAS_Push(Stack, 100);
	DAS_Print(Stack);

	//--------------------------------------------------------------

	DAS_Push(Stack, 110);
	DAS_Print(Stack);

	DAS_Push(Stack, 120);
	DAS_Print(Stack);


	//--------------------------------------------------------------

	DAS_Pop(Stack);
	DAS_Print(Stack);

	DAS_Pop(Stack);
	DAS_Print(Stack);

	DAS_Push(Stack, 10000);
	DAS_Print(Stack);

	DAS_Push(Stack, 20000);
	DAS_Print(Stack);

	DAS_Pop(Stack);
	DAS_Print(Stack);

	DAS_Pop(Stack);
	DAS_Print(Stack);

	DAS_Pop(Stack);
	DAS_Print(Stack);

	DAS_Push(Stack, 30000);
	DAS_Print(Stack);

	//--------------------------------------------------------------
	DAS_Delete(Stack);
	DAS_Print(Stack);
}