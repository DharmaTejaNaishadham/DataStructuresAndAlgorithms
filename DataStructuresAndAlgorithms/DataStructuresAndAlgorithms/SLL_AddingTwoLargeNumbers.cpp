#include <iostream>
using namespace std;

#include "SLL.h"

ListNode * addLinkedLists(ListNode * n1, ListNode * n2)
{
	if (n1 == NULL && n2 == NULL)
		return NULL;

	//either do a inplace addition in longer list
	//or
	//build a new list and return => going with this option ;)

	ListNode *result = NULL, *temp = NULL, *newNode = NULL;
	int sum = 0, carry = 0;
	bool firstNode = true;

		
	while (n1 != NULL || n2 != NULL)
	{
		newNode = new ListNode();
		
		sum = ((n1!=NULL)?n1->getdata():0) + ((n2!=NULL)?n2->getdata():0) + carry;
		
		carry = sum / 10;
		sum = sum % 10;
		
		newNode->setdata(sum);

		if (firstNode)
		{
			result = temp = newNode;
			firstNode = false;
		}
		else
		{
			temp->setnext(newNode);
			temp = temp->getnext();
		}
		

		n1 = (n1!=NULL)?n1->getnext():NULL;
		n2 = (n2!=NULL)?n2->getnext():NULL;
	}

	if (carry != 0)//cases like 2+9...where no. of digits in sum > in input
	{
		newNode = new ListNode();
		newNode->setdata(carry);

		temp->setnext(newNode);
	}

	return result;
}

void SLL_AddingTwoLargeNumbers_main()
{
#pragma region Preparation

	//Initializing Linked list - 1
	//1->5->4->7->2 => 27451
	ListNode *node = new ListNode();
	node->setdata(1);
	//SLL_PrintList(node);

	ListNode *newNode1 = new ListNode();
	newNode1->setdata(5);
	SLL_AddNodeAtTheEnd(node, newNode1);
	//SLL_PrintList(node);

	ListNode *newNode2 = new ListNode();
	newNode2->setdata(4);
	SLL_AddNodeAtTheEnd(node, newNode2);
	//SLL_PrintList(node);

	ListNode *newNode3 = new ListNode();
	newNode3->setdata(7);
	SLL_AddNodeAtTheEnd(node, newNode3);
	//SLL_PrintList(node);

	ListNode *newNode4 = new ListNode();
	newNode4->setdata(2);
	SLL_AddNodeAtTheEnd(node, newNode4);
	//SLL_PrintList(node);

	cout << "Printing the first Linked List\n";
	SLL_PrintList(node);

	//-----------------------------------------

	//Initializing Linked list - 2
	//9->4->4->2 => 2449
	ListNode *node2 = new ListNode();
	node2->setdata(9);
	//SLL_PrintList(node);

	ListNode *newNode21 = new ListNode();
	newNode21->setdata(4);
	SLL_AddNodeAtTheEnd(node2, newNode21);
	//SLL_PrintList(node);

	ListNode *newNode22 = new ListNode();
	newNode22->setdata(4);
	SLL_AddNodeAtTheEnd(node2, newNode22);
	//SLL_PrintList(node);

	ListNode *newNode23 = new ListNode();
	newNode23->setdata(2);
	SLL_AddNodeAtTheEnd(node2, newNode23);
	//SLL_PrintList(node);

	cout << "Printing the second Linked List\n";
	SLL_PrintList(node2);

	//-----------------------------------------

#pragma endregion

#pragma region Execution

	//27451 + 2449 = 29900 => 0->0->9->9->2
	ListNode * result = addLinkedLists(node, node2);
	SLL_PrintList(result);

#pragma endregion
}