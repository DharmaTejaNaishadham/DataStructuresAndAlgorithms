#include <iostream>
using namespace std;

#include "SLL.h"

ListNode * NthElementFromEnd(ListNode *list, int n)
{
	ListNode *pTemp = new ListNode();
	ListNode *pNthNode = new ListNode();

	int nTemp = 1;
	pTemp = list; pNthNode = list;

	while (pTemp->getnext() != NULL)
	{
		if (nTemp >= n)
		{
			pTemp = pTemp->getnext();
			pNthNode = pNthNode->getnext();
			nTemp++;
		}
		else
		{
			pTemp = pTemp->getnext();
			nTemp++;
		}
	}

	if (nTemp >= n) return pNthNode;
	else return NULL;
}

void SLL_NthElementFromEnd_main()
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

#pragma endregion

#pragma region Execution

	ListNode *ans = new ListNode();

	ans = NthElementFromEnd(node, 7);
	cout << "Printing the mentioned node:\n";
	SLL_PrintList(ans);

	ans = NthElementFromEnd(node, 11);
	if (ans != NULL)
		SLL_PrintList(ans); 
	else 
		cout << "We don't have so many nodes :p\n";

#pragma endregion
	

	
}
