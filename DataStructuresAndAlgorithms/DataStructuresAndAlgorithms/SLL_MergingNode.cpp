#include <iostream>
using namespace std;

#include <sstream>

#include "SLL.h"
#include "HashTable.h"

// Uncomment when you implement Stacks using Linked Lists
//ListNode * MergingNode_UsingStacks(ListNode *List1, ListNode *List2)
//{
//	if(!List1 && !List2)	return;
//
//	while(1)
//	{
//		if(List1 == NULL) break;
//		
//		stack1->push(List1);
//		List1 = List1->getnext();
//	}
//
//	while(1)
//	{
//	if(List2 == NULL) break;
//
//	stack2->push(List1);
//	List2 = List2->getnext();
//	}
//
//	ListNode * mergingNode = new ListNode();
//	while(1)
//	{
//		if(stack1.top == stack2.top)
//		{
//			mergingNode = stack1.top;
//
//			stack1.pop();
//			stack2.pop();
//		}
//		else
//		{
//			return mergingNode;
//		}
//	}
//}

void MergingNode(ListNode *List1, ListNode *List2)
{
	HashTable *table = new HashTable();

	ListNode *head = new ListNode();

	stringstream s;
	string headAddress;
	string result;

	//-------------------------------------------------------
	head = List1;
	while (head->getnext() != NULL)
	{
		s.str("");
		s << head;

		headAddress = s.str();

		result = table->addKeyValue(headAddress);
		table->PrintHashTable();

		if (result != "")
		{
			cout << result << " - ede ra ne address :)\n";
			break;
		}

		head = head->getnext();
	}

	//you won't see this FCFA because, head->getnext() != NULL wouldn't happen there
	s.str("");
	s << head;

	headAddress = s.str();
	result = table->addKeyValue(headAddress);

	//-------------------------------------------------------
	head = List2;
	while (head->getnext() != NULL)
	{
		s.str("");
		s << head;

		headAddress = s.str();

		result = table->addKeyValue(headAddress);
		table->PrintHashTable();

		if (result != "")
		{
			cout << result << " - ede ra ne address :)\n";
			break;
		}

		head = head->getnext();
	}

	//you won't see this FCFA because, head->getnext() != NULL wouldn't happen there
	s.str("");
	s << head;

	headAddress = s.str();
	result = table->addKeyValue(headAddress);
	//-------------------------------------------------------
}

void SLL_MergingNode_main()
{
#pragma region Preparation

	ListNode *node = new ListNode();
	node->setdata(10);

	ListNode *node2 = new ListNode();
	node2->setdata(20);
	node->setnext(node2);

	ListNode *node3 = new ListNode();
	node3->setdata(30);
	node2->setnext(node3);

	ListNode *node4 = new ListNode();
	node4->setdata(40);
	node3->setnext(node4);

	ListNode *node5 = new ListNode();
	node5->setdata(50);
	node4->setnext(node5);

	ListNode *node6 = new ListNode();
	node6->setdata(60);
	node5->setnext(node6);

	ListNode *node7 = new ListNode();
	node7->setdata(70);
	node6->setnext(node7);

	ListNode *node8 = new ListNode();
	node8->setdata(80);
	node7->setnext(node8);

	ListNode *node9 = new ListNode();
	node9->setdata(90);
	node8->setnext(node9);

	SLL_PrintList(node);

	//-------------------------------------------------------
	ListNode *Another = new ListNode();
	Another->setdata(1000);

	ListNode *Another2 = new ListNode();
	Another2->setdata(2000);
	Another->setnext(Another2);

	ListNode *Another3 = new ListNode();
	Another3->setdata(3000);
	Another2->setnext(Another3);

	Another3->setnext(node5);

	SLL_PrintList(Another);

	//-------------------------------------------------------

#pragma endregion

#pragma region Execution

	MergingNode(node, Another);

#pragma endregion
}