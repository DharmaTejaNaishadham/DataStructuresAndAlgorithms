#include <iostream>
using namespace std;

//Including the class definiton and function prototypes of SAStack.h
#include "SAStack.h"

bool SAS_IsEmptyStack(SimpleArrayStack * Stack)
{
	if (Stack->top == -1) return true; else return false;
}

bool SAS_IsFullStack(SimpleArrayStack * Stack)
{
	if (Stack->top == SimpleArrayStack_Capacity-1) return true; else return false;
}

void SAS_Push(SimpleArrayStack * Stack, int data)
{
	if (!SAS_IsFullStack(Stack))
	{
		Stack->array[Stack->top + 1] = data;
		Stack->top++;
	}
	else
	{
		cout << "Stack Overflow\n";
	}
}

int SAS_Pop(SimpleArrayStack * Stack)
{
	if (!SAS_IsEmptyStack(Stack))
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

void SAS_Print(SimpleArrayStack * Stack)
{
	cout << "\n-----------------------------------------------------------\n";
	cout << "Address of Stack: " << Stack << "\n";
	cout << "Top: " << Stack->top << "\n";
	cout << "Elements: ";

	for (int i = 0; i < SimpleArrayStack_Capacity; i++)
	{
		cout << Stack->array[i] << "\t";
	}
	cout << "\n-----------------------------------------------------------\n";

}

void SAS_Delete(SimpleArrayStack * Stack)
{
	free(Stack);
}

void SAS_BasicOperations_main()
{
	SimpleArrayStack *Stack = new SimpleArrayStack();

	SAS_Pop(Stack);

	SAS_Print(Stack);

	SAS_Push(Stack, 10);
	SAS_Print(Stack);

	SAS_Push(Stack, 20);
	SAS_Print(Stack);

	SAS_Push(Stack, 30);
	SAS_Print(Stack);

	SAS_Push(Stack, 40);
	SAS_Print(Stack);

	SAS_Push(Stack, 50);
	SAS_Print(Stack);

	//--------------------------------------------------------------

	SAS_Push(Stack, 60);
	SAS_Print(Stack);
	
	//--------------------------------------------------------------

	SAS_Pop(Stack);
	SAS_Print(Stack);

	SAS_Pop(Stack);
	SAS_Print(Stack);

	SAS_Push(Stack, 10000);
	SAS_Print(Stack);

	SAS_Push(Stack, 20000);
	SAS_Print(Stack);

	SAS_Pop(Stack);
	SAS_Print(Stack);

	SAS_Pop(Stack);
	SAS_Print(Stack);

	SAS_Pop(Stack);
	SAS_Print(Stack);

	SAS_Push(Stack, 30000);
	SAS_Print(Stack);

	SAS_Pop(Stack);
	SAS_Print(Stack);

	SAS_Pop(Stack);
	SAS_Print(Stack);

	SAS_Pop(Stack);
	SAS_Print(Stack);

	SAS_Pop(Stack);
	//--------------------------------------------------------------
	SAS_Delete(Stack);
	SAS_Print(Stack);
}