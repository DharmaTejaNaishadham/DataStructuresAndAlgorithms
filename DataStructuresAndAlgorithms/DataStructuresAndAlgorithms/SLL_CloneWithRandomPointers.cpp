#include <iostream>
using namespace std;

#include "SLL.h"
#include "HashTable.h"

#include <vector>
#include <sstream>


stringstream s;
string headAddress;
HashTable * hashT = new HashTable();

vector <ListNode *> nodeVector;
vector <ListNode *> cloneVector;

vector <ListNode *> createListNodeVector(ListNode * list)
{
	vector <ListNode *> listVector;

	if (list == NULL)
	{
		listVector.clear();
	}

	listVector.push_back(list);
	while (1)
	{
		list = list->getnext();
		if (list == NULL) break;

		listVector.push_back(list);
	}

	return listVector;
}

ListNode * Clone(ListNode * node)
{
	if (node == NULL)	return NULL;

	//Creating nodeVector
	nodeVector = createListNodeVector(node);

	//Creating Hash Table with Random, parentPosition 
	for (int i = 0; i < nodeVector.size(); i++)
	{
		s.str("");
		s << nodeVector[i];
		headAddress = s.str();

		hashT->addKeyValue(headAddress, i);
	}

#pragma region Creating Clone Skeleton
	ListNode * clone = new ListNode();
	clone->setdata(node->getdata());

	ListNode * temp;
	while (1)
	{
		node = node->getnext();
		if (node == NULL)	break;

		temp = new ListNode();
		temp->setdata(node->getdata());
		SLL_AddNodeAtTheEnd(clone, temp);
	}
#pragma endregion

	
	//Creating cloneVector
	cloneVector = createListNodeVector(clone);

	//Setting Random pointers of cloneVector
	for (int i = 0; i < cloneVector.size(); i++)
	{
		s.str("");
		s << nodeVector[i]->getrandom();
		headAddress = s.str();

		cloneVector[i]->setrandom(cloneVector[hashT->getKeyValue(headAddress)]);		
	}

	return clone;
}

void SLL_CloneWithRandomPointers_main()
{
#pragma region Preparation

	//Initializing Linked list
	ListNode *node = new ListNode();
	node->setdata(125);
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
	newNode3->setdata(750);
	SLL_AddNodeAtTheEnd(node, newNode3);
	//SLL_PrintList(node);

	ListNode *newNode4 = new ListNode();
	newNode4->setdata(2000);
	SLL_AddNodeAtTheEnd(node, newNode4);
	//SLL_PrintList(node);

	node->setrandom(newNode2);
	newNode1->setrandom(newNode3);
	newNode2->setrandom(newNode1);
	newNode3->setrandom(newNode3);
	newNode4->setrandom(node);

	SLL_PrintList(node);

#pragma endregion

#pragma region Execution

	ListNode * clone = Clone(node);
	SLL_PrintList(clone);

#pragma endregion	
}