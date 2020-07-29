#include <iostream>
using namespace std;

#include <sstream>

#include "HashTable.h"
#include "BTNQueueAndStack.h"

BinaryTreeNode * LowestCommonAncestor(BinaryTreeNode * root, BinaryTreeNode * nodeA, BinaryTreeNode * nodeB)
{
	if (root == NULL)
		return NULL;

	if (root->getdata() == nodeA->getdata() || root->getdata() == nodeB->getdata())
		return root;

	BinaryTreeNode *leftAncestor = LowestCommonAncestor(root->getleft(), nodeA, nodeB);
	BinaryTreeNode *rightAncestor = LowestCommonAncestor(root->getright(), nodeA, nodeB);

	if (leftAncestor && rightAncestor)
		return root;

	return (leftAncestor != NULL) ? leftAncestor:rightAncestor;
}

BinaryTreeNode * LowestCommonAncestor_NonRec(BinaryTreeNode * node, BinaryTreeNode * nodeA, BinaryTreeNode * nodeB)
{
	if (node == NULL)
		return NULL;

	if (nodeA == NULL || nodeB == NULL)
		return node;

	BinaryTreeNode * temp;
	
	//-----------------------------------------------
	BinaryTreeStack * stackA = new BinaryTreeStack();
	bool nodeAfound = false;

	temp = node;
	while (!nodeAfound)
	{
		while (temp)
		{
			BTNS_Push(stackA, temp);

			if (temp == nodeA)
			{
				nodeAfound = true;
				break;
			}

			temp = temp->getleft();
		}

		if (BTNS_IsEmptyStack(stackA))
		{
			break;
		}

		if (!nodeAfound)
		{
			if ((stackA->top)->getright() == NULL)
			{
				temp = BTNS_Pop(stackA);

				while (temp == stackA->top->getright())
				{
					temp = BTNS_Pop(stackA);

					if (BTNS_IsEmptyStack(stackA))
					{
						break;
					}
				}
			}

			if (!BTNS_IsEmptyStack(stackA))
			{
				temp = (stackA->top)->getright();
			}
			else
			{
				break;
			}
		}
	}
	
	//-----------------------------------------------
	BinaryTreeStack * stackB = new BinaryTreeStack();
	bool nodeBfound = false;
	
	temp = node;
	while (!nodeBfound)
	{
		while (temp)
		{
			BTNS_Push(stackB, temp);

			if (temp == nodeB)
			{
				nodeBfound = true;
				break;
			}

			temp = temp->getleft();
		}

		if (BTNS_IsEmptyStack(stackB))
			break;

		if (!nodeBfound)
		{
			if ((stackB->top)->getright() == NULL)
			{
				temp = BTNS_Pop(stackB);

				while (temp == stackB->top->getright())
				{
					temp = BTNS_Pop(stackB);

					if (BTNS_IsEmptyStack(stackB))
						break;
				}
			}

			if (!BTNS_IsEmptyStack(stackB))
			{
				temp = (stackB->top)->getright();
			}
			else
			{
				break;
			}
		}
	}
	//-----------------------------------------------

	stringstream s;
	string headAddress;
	string result;
	HashTable *table = new HashTable();

	if ((nodeAfound == true) && (nodeBfound == true))
	{		
		while (!BTNS_IsEmptyStack(stackA))
		{
			s.str("");
			temp = BTNS_Pop(stackA);
			s << temp;
			headAddress = s.str();

			result = table->addKeyValue(headAddress);
		}

		while (!BTNS_IsEmptyStack(stackB))
		{
			s.str("");
			temp = BTNS_Pop(stackB);
			s << temp;
			headAddress = s.str();

			result = table->addKeyValue(headAddress);

			if (result != "")
			{
				return temp;
			}
		}				
	}
	else
	{
		return NULL;
	}
}

void BT_LowestCommonAncestor_main()
{
	/*
									  ---- 1=root=100 ----
								/							   \
							2=200							  3=300
							/	\						/				\
						4=400	5=500				6=600				7=700
													/	 \					\
												8=800	9=900				10=1000
												/	\						/		
										11=1100	     12=1200	  	     13=1300
													/					 /
												14=1400				15=1500

	*/

#pragma region Preparation

	BinaryTreeNode *root = new BinaryTreeNode();
	root->setdata(100);

	BinaryTreeNode *node2 = new BinaryTreeNode();
	node2->setdata(200);

	BinaryTreeNode *node3 = new BinaryTreeNode();
	node3->setdata(300);

	BinaryTreeNode *node4 = new BinaryTreeNode();
	node4->setdata(400);

	BinaryTreeNode *node5 = new BinaryTreeNode();
	node5->setdata(500);

	BinaryTreeNode *node6 = new BinaryTreeNode();
	node6->setdata(600);

	BinaryTreeNode *node7 = new BinaryTreeNode();
	node7->setdata(700);

	BinaryTreeNode *node8 = new BinaryTreeNode();
	node8->setdata(800);

	BinaryTreeNode *node9 = new BinaryTreeNode();
	node9->setdata(900);

	BinaryTreeNode *node10 = new BinaryTreeNode();
	node10->setdata(1000);

	BinaryTreeNode *node11 = new BinaryTreeNode();
	node11->setdata(1100);

	BinaryTreeNode *node12 = new BinaryTreeNode();
	node12->setdata(1200);

	BinaryTreeNode *node13 = new BinaryTreeNode();
	node13->setdata(1300);

	BinaryTreeNode *node14 = new BinaryTreeNode();
	node14->setdata(1400);

	BinaryTreeNode *node15 = new BinaryTreeNode();
	node15->setdata(1500);

	root->setleft(node2);
	root->setright(node3);

	node2->setleft(node4);
	node2->setright(node5);

	node3->setleft(node6);
	node3->setright(node7);

	node6->setleft(node8);
	node6->setright(node9);

	node7->setright(node10);

	node8->setleft(node11);
	node8->setright(node12);

	node10->setleft(node13);
	node12->setleft(node14);
	node13->setleft(node15);

#pragma endregion

#pragma region Execution

	cout << "Recursive Method:\n";
	cout << "Lowest Common Ancestor of " << node7->getdata() << " and " << node8->getdata() << " = " << (LowestCommonAncestor(root, node7, node8))->getdata() << "\n";
	cout << "Lowest Common Ancestor of " << node5->getdata() << " and " << node9->getdata() << " = " << (LowestCommonAncestor(root, node5, node9))->getdata() << "\n";
	cout << "Lowest Common Ancestor of " << node9->getdata() << " and " << node15->getdata() << " = " << (LowestCommonAncestor(root, node9, node15))->getdata() << "\n";

	cout << "\nNon Recursive Method:\n";
	cout << "Lowest Common Ancestor of " << node7->getdata() << " and " << node8->getdata() << " = " << (LowestCommonAncestor_NonRec(root, node7, node8))->getdata() << "\n";
	cout << "Lowest Common Ancestor of " << node5->getdata() << " and " << node9->getdata() << " = " << (LowestCommonAncestor_NonRec(root, node5, node9))->getdata() << "\n";
	cout << "Lowest Common Ancestor of " << node9->getdata() << " and " << node15->getdata() << " = " << (LowestCommonAncestor_NonRec(root, node9, node15))->getdata() << "\n";

#pragma endregion
}