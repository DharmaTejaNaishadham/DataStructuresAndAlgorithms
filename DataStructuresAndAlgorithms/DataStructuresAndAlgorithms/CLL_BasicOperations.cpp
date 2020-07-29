#include <iostream>
using namespace std;

#include "CLL.h"

void CLL_AddNodeAtTheEnd(CLListNode *mainList, CLListNode *newNode)
{
	CLListNode *head = new CLListNode();
	head = mainList;

	while (head->getnext() != mainList && head->getnext() != NULL)
	{
		head = head->getnext();
	}
	head->setnext(newNode);
	newNode->setnext(mainList);
}

void CLL_AddNodeAtTheFront(CLListNode *mainList, CLListNode *newNode)
{
	CLListNode *head = new CLListNode();
	head = mainList;

	newNode->setnext(head);

	while (head->getnext() != mainList && head->getnext() != NULL)
	{
		head = head->getnext();
	}
	head->setnext(newNode);
}

void CLL_DeleteNodeAtTheEnd(CLListNode *mainList)
{
	CLListNode *head = new CLListNode();
	CLListNode *last = new CLListNode();
	head = mainList;

	if (head->getnext() == NULL)
	{
		cout << "Sorry! Your Linked list has only 1 node...I don't want to delete that\n";
		return;
	}
	else
	{
		while (head->getnext() != mainList && head->getnext() != NULL)
		{
			last = head;
			head = head->getnext();
		}
		last->setnext(mainList);
		free(head);
	}

}

CLListNode * CLL_DeleteNodeAtTheFront(CLListNode *mainList)
{
	CLListNode *head = new CLListNode();
	CLListNode *nextMain = new CLListNode();

	head = mainList;

	if (head->getnext() == NULL)
	{
		cout << "Sorry! Your Linked list has only 1 node...I don't want to delete that\n";
		return NULL;
	}
	else
	{
		nextMain = head->getnext();
		while (head->getnext() != mainList && head->getnext() != NULL)
		{
			head = head->getnext();
		}
		head->setnext(nextMain);
		free(mainList);
		return nextMain;

	}

}

void CLL_PrintList(class CLListNode *list)
{
	CLListNode *head = new CLListNode;
	int nodePosition = 1;

	head = list;

	cout << "START\n";
	while (head->getnext() != list && head->getnext() != NULL)
	{
		cout << "Node Position: " << nodePosition << " Node Address: " << head << " Node Data = " << head->getdata() << " Node Next = " << head->getnext() << "\n";
		nodePosition++;
		head = head->getnext();
	}
	cout << "Node Position: " << nodePosition << " Node Address: " << head << " Node Data = " << head->getdata() << " Node Next = " << head->getnext() << "\n";
	cout << "END\n\n";
}

void CLL_BasicOperations_main()
{
	//Initializing Linked list
	CLListNode *node = new CLListNode();
	node->setdata(125);
	CLL_PrintList(node);

	CLListNode *newNode1 = new CLListNode();
	newNode1->setdata(250);
	newNode1->setnext(node);//making a loop
	CLL_AddNodeAtTheEnd(node, newNode1);
	CLL_PrintList(node);

	CLListNode *newNode2 = new CLListNode();
	newNode2->setdata(500);
	newNode2->setnext(node);//making a loop
	CLL_AddNodeAtTheEnd(node, newNode2);
	CLL_PrintList(node);

	CLListNode *newNode3 = new CLListNode();
	newNode3->setdata(750);
	CLL_AddNodeAtTheEnd(node, newNode3);
	CLL_PrintList(node);

	CLListNode *newNode4 = new CLListNode();
	newNode4->setdata(2000);
	CLL_AddNodeAtTheFront(node, newNode4);
	CLL_PrintList(node);
	CLL_PrintList(newNode4);//be amazed by the beauty of circular linked lists :D -------Dumb DuMpI was still expecting a start and end :p

	node = CLL_DeleteNodeAtTheFront(node);
	CLL_PrintList(node);

	CLL_DeleteNodeAtTheEnd(node);
	CLL_PrintList(node);
}