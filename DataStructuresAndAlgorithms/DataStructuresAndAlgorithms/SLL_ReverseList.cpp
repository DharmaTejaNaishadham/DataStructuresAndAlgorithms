#include <iostream>
using namespace std;

#include "SLL.h"

ListNode * ReverseList(ListNode *List)
{
	ListNode *head = new ListNode();
	ListNode *prev = new ListNode();
	ListNode *next = new ListNode();

	prev = NULL;
	head = List;
	
	while (head->getnext() != NULL)
	{
		next = head->getnext();
		head->setnext(prev);
		prev = head;
		head = next;
	}
	head->setnext(prev);
	return head;
}

ListNode * ReverseList_Clean(ListNode *List)
{
	ListNode *reverse = NULL;	
	ListNode *temp = NULL;

	if (List == NULL)	return NULL;

	while (List)
	{
		temp = List;

		List = List->getnext();

		if (reverse)
		{
			temp->setnext(reverse);
			reverse = temp;
		}
		else//special case => head becoming the end
		{
			reverse = temp;
			reverse->setnext(NULL);
		}
	}

	return reverse;
}

void SLL_ReverseList_main()
{
#pragma region Preparation

	//Initializing Linked list
	ListNode *node = new ListNode();
	node->setdata(125);
	SLL_PrintList(node);

	ListNode *newNode1 = new ListNode();
	newNode1->setdata(250);
	SLL_AddNodeAtReqdPosition(node, newNode1, 3);
	SLL_PrintList(node);

	ListNode *newNode2 = new ListNode();
	newNode2->setdata(500);
	SLL_AddNodeAtTheEnd(node, newNode2);
	SLL_PrintList(node);

	ListNode *newNode3 = new ListNode();
	newNode3->setdata(750);
	SLL_AddNodeAtTheEnd(node, newNode3);
	SLL_PrintList(node);

	ListNode *newNode4 = new ListNode();
	newNode4->setdata(2000);
	SLL_AddNodeAtTheEnd(node, newNode4);
	SLL_PrintList(node);

#pragma endregion

#pragma region Execution

	ListNode *Reverse = new ListNode();
	//Reverse = ReverseList(node);
	//SLL_PrintList(Reverse);

	Reverse = ReverseList_Clean(node);
	SLL_PrintList(Reverse);

#pragma endregion	
}