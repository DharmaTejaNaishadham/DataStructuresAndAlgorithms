#include <iostream>
using namespace std;

#include "DLL.h"

void DLL_AddNodeAtTheEnd(DLListNode *mainList, DLListNode *newNode)
{
	DLListNode *head = new DLListNode();
	head = mainList;

	while (head->getnext() != NULL)
	{
		head = head->getnext();
	}
	head->setnext(newNode);
	newNode->setprev(head);
}

void DLL_AddNodeAtReqdPosition(DLListNode *mainList, DLListNode *newNode, int reqdPosition)
{
	DLListNode *head = new DLListNode();
	head = mainList;

	DLListNode *temp = new DLListNode();

	int nodePosition = 1;

	if (head->getnext() == NULL)//List containing only 1 node
	{
		if (nodePosition == reqdPosition)
		{
			head->setnext(newNode);
			newNode->setprev(head);
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
				newNode->setprev(head);
				return;
			}
			head = head->getnext();
			nodePosition++;
		}
	}
	cout << "Invalid postion :@\nList contains only " << nodePosition << " nodes\n";

}

void DLL_DeleteNodeAtTheEnd(DLListNode *mainList)
{
	DLListNode *head = new DLListNode();
	DLListNode *last = new DLListNode();
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

void DLL_DeleteNodeAtReqdPosition(DLListNode *mainList, int reqdPosition)
{
	DLListNode *head = new DLListNode();
	head = mainList;

	DLListNode *last = new DLListNode();
	last = head;

	DLListNode *next = new DLListNode();

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
				next->setprev(last);
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

void DLL_PrintList(class DLListNode *list)
{
	DLListNode *head = new DLListNode;
	int nodePosition = 1;

	head = list;

	cout << "START\n";
	while (head->getnext() != NULL)
	{
		cout << "Node Position: " << nodePosition << " Node Address: " << head << " Node Data = " << head->getdata() << " Node Next = " << head->getnext() << " Node Prev = " << head->getprev() << "\n";
		nodePosition++;
		head = head->getnext();
	}
	cout << "Node Position: " << nodePosition << " Node Address: " << head << " Node Data = " << head->getdata() << " Node Next = " << head->getnext() << " Node Prev = " << head->getprev() << "\n";
	cout << "END\n\n";
}

void DLL_BasicOperations_main()
{
	//Initializing Linked list
	DLListNode *node = new DLListNode();
	node->setdata(125);
	DLL_PrintList(node);

	DLListNode *newNode1 = new DLListNode();
	newNode1->setdata(250);
	DLL_AddNodeAtReqdPosition(node, newNode1, 3);
	DLL_PrintList(node);

	DLListNode *newNode2 = new DLListNode();
	newNode2->setdata(500);
	DLL_AddNodeAtTheEnd(node, newNode2);
	DLL_PrintList(node);

	DLListNode *newNode3 = new DLListNode();
	newNode3->setdata(750);
	DLL_AddNodeAtTheEnd(node, newNode3);
	DLL_PrintList(node);

	DLListNode *newNode4 = new DLListNode();
	newNode4->setdata(2000);
	DLL_AddNodeAtReqdPosition(node, newNode4, 7);
	DLL_PrintList(node);

	DLL_DeleteNodeAtReqdPosition(node, 2);
	DLL_PrintList(node);

	DLL_DeleteNodeAtTheEnd(node);
	DLL_PrintList(node);
}