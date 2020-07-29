#include <iostream>
using namespace std;

#include "SLL.h"

ListNode * SelectionSort(ListNode * node)
{
	if (node == NULL) return NULL;

	ListNode * temp = new ListNode();
	ListNode * prev = new ListNode();
	ListNode * min = new ListNode();
	ListNode * minPrev = new ListNode();
	ListNode * minNext = new ListNode();


	int noOfElements = 1;
	int position = 0;

	//figuring out no. of elements in linked list
	temp = node;
	while (temp->getnext())
	{
		temp = temp->getnext();
		noOfElements++;
	}

	for (int pass = 0; pass < noOfElements - 1; pass++)
	{
		prev = NULL;
		temp = node;
		position = 0;

		while (position < pass)
		{
			prev = temp;
			temp = temp->getnext();

			position++;
		}

		min = minInList(temp);
		minNext = min->getnext();
		
		minPrev = temp;
		//finding out minPrev 
		while(minPrev->getnext() != min)
		{
			minPrev = minPrev->getnext();
		}

		if (prev == NULL)//1st pass; 1st swap;
		{
			min->setnext(temp->getnext());
			temp->setnext(minNext);
			minPrev->setnext(temp);
			node = min;
		}
		else
		{
			if (minPrev != temp)
			{
				prev->setnext(min);
				min->setnext(temp->getnext());
				temp->setnext(minNext);
				minPrev->setnext(temp);
			}
			else//last pass; last swap;
			{
				prev->setnext(min);
				min->setnext(temp);
				temp->setnext(NULL);
			}			
		}		
	}
	return node;
}

void SelectionSort_main()
{
	//Initializing Linked list
	ListNode *node = new ListNode();
	node->setdata(1250);
	//SLL_PrintList(node);

	ListNode *newNode1 = new ListNode();
	newNode1->setdata(250);
	SLL_AddNodeAtTheEnd(node, newNode1);
	//SLL_PrintList(node);

	ListNode *newNode2 = new ListNode();
	newNode2->setdata(500);
	SLL_AddNodeAtTheEnd(node, newNode2);
	//SLL_PrintList(node);

	ListNode *newNode3 = new ListNode();
	newNode3->setdata(7500);
	SLL_AddNodeAtTheEnd(node, newNode3);
	//SLL_PrintList(node);

	ListNode *newNode4 = new ListNode();
	newNode4->setdata(2000);
	SLL_AddNodeAtTheEnd(node, newNode4);
	//SLL_PrintList(node);

	ListNode *newNode5 = new ListNode();
	newNode5->setdata(200);
	SLL_AddNodeAtTheEnd(node, newNode5);
	//SLL_PrintList(node);

	ListNode *newNode6 = new ListNode();
	newNode6->setdata(8000);
	SLL_AddNodeAtTheEnd(node, newNode6);
	//SLL_PrintList(node);

	ListNode *newNode7 = new ListNode();
	newNode7->setdata(10);
	SLL_AddNodeAtTheEnd(node, newNode7);
	SLL_PrintList(node);

	node = SelectionSort(node);
	SLL_PrintList(node);
}