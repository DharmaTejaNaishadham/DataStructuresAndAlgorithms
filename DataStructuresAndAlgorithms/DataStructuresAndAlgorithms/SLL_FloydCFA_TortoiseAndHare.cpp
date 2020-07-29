#include <iostream>
using namespace std;

#include <sstream>

#include "SLL.h"
#include "HashTable.h"


bool DoesLinkedListContainsLoop(ListNode *list)
{
	ListNode *tortoise = new ListNode();
	ListNode *hare = new ListNode();

	tortoise = list;
	hare = list;

	while (tortoise->getnext() != NULL && hare->getnext() != NULL && (hare->getnext()->getnext() != NULL))
	{
		tortoise = tortoise->getnext();
		hare = (hare->getnext())->getnext();

		if (tortoise == hare)
		{
			return true;
		}
	}
	return false;
}

void LinkedListLoopNode(ListNode *list)
{
	HashTable *table = new HashTable();

	ListNode *head = new ListNode();
	head = list;

	stringstream s;
	string headAddress;
	string result;

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

}

void SLL_FloydCFA_TortoiseAndHare_main()
{
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
	cout << DoesLinkedListContainsLoop(node) <<"\n";

	node9->setnext(node3);
	//SLL_PrintList(node);//It's circular...SOO infinite loop
	cout << DoesLinkedListContainsLoop(node) <<"\n";

	ListNode *loopElement = new ListNode();
	LinkedListLoopNode(node);
	//cout << " Node Address: " << loopElement << " Node Data = " << loopElement->getdata() << " Node Next = " << loopElement->getnext() << "\n";
}