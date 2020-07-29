#include <iostream>
using namespace std;

#include "SLL.h"

ListNode * minInList(ListNode * node)
{
	ListNode * min = new ListNode();

	if (node == NULL) return NULL;

	min = node;

	while (node)
	{
		if (min->getdata() > node->getdata())
		{
			min = node;
		}

		node = node->getnext();
	}

	return min;
}

ListNode * maxInList(ListNode * node)
{
	ListNode * min = new ListNode();

	if (node == NULL) return NULL;

	min = node;

	while (node)
	{
		if (min->getdata() < node->getdata())
		{
			min = node;
		}

		node = node->getnext();
	}

	return min;
}

void SLL_AddNodeAtTheEnd(ListNode *mainList, ListNode *newNode)
{
	ListNode *head = new ListNode();
	head = mainList;

	while (head->getnext() != NULL)
	{
		head = head->getnext();
	}
	head->setnext(newNode);
}

void SLL_AddNodeAtReqdPosition(ListNode *mainList, ListNode *newNode, int reqdPosition)
{
	ListNode *head = new ListNode();
	head = mainList;

	ListNode *temp = new ListNode();

	int nodePosition = 1;

	if (head->getnext() == NULL)//List containing only 1 node
	{
		if (nodePosition == reqdPosition)
		{
			head->setnext(newNode);
			return;
		}
		else
		{
			cout << "Invalid postion :@\nList contains only 1 node\n";
			return;
		}
	}
	else
	{
		while (head->getnext() != NULL)
		{
			if (nodePosition == reqdPosition)
			{
				temp = head->getnext();
				head->setnext(newNode);
				newNode->setnext(temp);
				return;
			}
			head = head->getnext();
			nodePosition++;
		}
	}
	cout << "Invalid postion :@\nList contains only " << nodePosition << " nodes\n";

}

void SLL_DeleteNodeAtTheEnd(ListNode *mainList)
{
	ListNode *head = new ListNode();
	ListNode *last = new ListNode();
	head = mainList;

	if (head->getnext() == NULL)
	{
		cout << "Sorry! Your Linked list has only 1 node...I don't want to delete that\n";
		return;
	}
	else
	{
		while (head->getnext() != NULL)
		{
			last = head;
			head = head->getnext();
		}
		last->setnext(NULL);
		free(head);
	}

}

void SLL_DeleteNodeAtReqdPosition(ListNode *mainList, int reqdPosition)
{
	ListNode *head = new ListNode();
	head = mainList;

	ListNode *last = new ListNode();
	last = head;

	ListNode *next = new ListNode();

	int nodePosition = 1;

	if (head->getnext() == NULL)//List containing only 1 node
	{
		if (reqdPosition == 1)
		{
			cout << "Sorry! Your Linked list has only 1 node...I don't want to delete that\n";
			return;
		}
		else
		{
			cout << "Invalid postion :@\nList contains only 1 node\n";
			return;
		}
	}
	else
	{
		while (head->getnext() != NULL)
		{
			next = head->getnext();
			if (nodePosition == reqdPosition)
			{
				last->setnext(next);
				free(head);
				return;
			}
			last = head;
			head = head->getnext();
			nodePosition++;
		}
	}
	cout << "Invalid postion :@\nList contains only " << nodePosition << " nodes\n";
}

void SLL_PrintList(class ListNode *list)
{
	ListNode *head = new ListNode;
	int nodePosition = 1;

	head = list;

	cout << "START\n";
	while (head->getnext() != NULL)
	{
		cout << "Node Position: " << nodePosition << " Address: " << head << " Data = " << head->getdata() << " Next = " << head->getnext() << " Random = " << head->getrandom() << "\n";
		nodePosition++;
		head = head->getnext();
	}
	cout << "Node Position: " << nodePosition << " Address: " << head << " Data = " << head->getdata() << " Next = " << head->getnext() << " Random = " << head->getrandom() << "\n";
	cout << "END\n\n";
}

void SLL_BasicOperations_main()
{
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
	SLL_AddNodeAtReqdPosition(node, newNode4, 7);
	SLL_PrintList(node);

	SLL_DeleteNodeAtReqdPosition(node, 2);
	SLL_PrintList(node);

	SLL_DeleteNodeAtTheEnd(node);
	SLL_PrintList(node);
}