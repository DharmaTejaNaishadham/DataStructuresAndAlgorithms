#include <iostream>
using namespace std;

#include "SLL.h"

ListNode * InsertionSort(ListNode * node)
{
	if (node == NULL) return NULL;

	ListNode * temp = new ListNode();
	ListNode * prev;
	ListNode * next;
	ListNode * betterNext;
	ListNode * betterNextsPrev;

	int noOfElements = 1;
	int position = 0;

	//figuring out no. of elements in linked list
	temp = node;
	while (temp->getnext())
	{
		temp = temp->getnext();
		noOfElements++;
	}

	for (int pass = 0; pass<noOfElements - 1; pass++)
		for (int i = 0; i < noOfElements - 1; i++)
		{
			temp = node;
			prev = NULL;
			next = NULL;
			betterNextsPrev = NULL;
			betterNext = NULL;

			//Navigate to node - temp becomes the node in context
			position = 0;
			while (position < i)
			{
				prev = temp;
				temp = temp->getnext();

				position++;
			}
			next = temp->getnext();


			//figuring oout if there is a better next
			betterNextsPrev = temp;
			betterNext = next;
			if(betterNext)
			while (temp->getdata() < betterNext->getdata())
			{
				i++;

				betterNextsPrev = betterNext;
				betterNext = betterNext->getnext();
			
				if (betterNext == NULL) break;
			}
			

			if (temp != NULL && next != NULL && betterNext != NULL)
			{				
					if (prev != NULL)
					{
						if(next == betterNext)
						{
							temp->setnext(betterNext->getnext());
							betterNext->setnext(temp);
							prev->setnext(betterNext);
						}
						else
						{							
							betterNextsPrev->setnext(betterNext->getnext());
							betterNext->setnext(temp);
							prev->setnext(betterNext);							
						}
					}
					else
					{
						if (next == betterNext)
						{
							temp->setnext(betterNext->getnext());
							betterNext->setnext(temp);
							node = betterNext;
						}
						else
						{
							betterNextsPrev->setnext(betterNext->getnext());
							betterNext->setnext(temp);
							node = betterNext;
						}
					}				
			}
		}
	return node;
}

void InsertionSort_main()
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

	node = InsertionSort(node);
	SLL_PrintList(node);
}