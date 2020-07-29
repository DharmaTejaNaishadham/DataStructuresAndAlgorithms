#include <iostream>
using namespace std;

class ListNode
{
	int data;
	class ListNode *next;
	class ListNode *random;

public:
	ListNode() { data = 0; next = NULL; random = NULL; }

	int getdata()	{ return data; }
	ListNode* getnext() { return next; }
	ListNode* getrandom() { return random; }

	void setdata(int value)	{ data = value; }
	void setnext(ListNode *ptr)	{ next = ptr; }
	void setrandom(ListNode *ptr) { random = ptr; }
};

ListNode * minInList(ListNode * node);

ListNode * maxInList(ListNode * node);

void SLL_AddNodeAtTheEnd(ListNode *mainList, ListNode *newNode);

void SLL_AddNodeAtReqdPosition(ListNode *mainList, ListNode *newNode, int reqdPosition);

void SLL_DeleteNodeAtTheEnd(ListNode *mainList);

void SLL_DeleteNodeAtReqdPosition(ListNode *mainList, int reqdPosition);

void SLL_PrintList(class ListNode *list);

void SLL_BasicOperations_main();