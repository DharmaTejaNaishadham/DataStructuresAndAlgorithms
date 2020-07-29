#include <iostream>
using namespace std;

class CLListNode
{
	int data;
	class CLListNode *next;

public:
	CLListNode() { data = 0; next = NULL; }

	int getdata()	{ return data; }
	CLListNode* getnext() { return next; }

	void setdata(int value)	{ data = value; }
	void setnext(CLListNode *ptr)	{ next = ptr; }
};


void CLL_AddNodeAtTheEnd(CLListNode *mainList, CLListNode *newNode);

void CLL_AddNodeAtTheFront(CLListNode *mainList, CLListNode *newNode);

void CLL_DeleteNodeAtTheEnd(CLListNode *mainList);

CLListNode * CLL_DeleteNodeAtTheFront(CLListNode *mainList);

void CLL_PrintList(class CLListNode *list);

void CLL_BasicOperations_main();