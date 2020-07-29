#include <iostream>
using namespace std;

class DLListNode
{
	int data;
	class DLListNode *next;
	class DLListNode *prev;

public:
	DLListNode() { data = 0; next = NULL; prev = NULL; }

	int getdata()	{ return data; }
	DLListNode* getnext() { return next; }
	DLListNode* getprev() { return prev; }

	void setdata(int value)	{ data = value; }
	void setnext(DLListNode *ptr)	{ next = ptr; }
	void setprev(DLListNode *ptr)	{ prev = ptr; }
};


void DLL_AddNodeAtTheEnd(DLListNode *mainList, DLListNode *newNode);

void DLL_AddNodeAtReqdPosition(DLListNode *mainList, DLListNode *newNode, int reqdPosition);

void DLL_DeleteNodeAtTheEnd(DLListNode *mainList);

void DLL_DeleteNodeAtReqdPosition(DLListNode *mainList, int reqdPosition);

void DLL_PrintList(class DLListNode *list);

void DLL_BasicOperations_main();