#include <iostream>
using namespace std;

#include <vector>
#include "BTNQueueAndStack.h"
#include "TBT.h"

BinaryTreeNode * PreOrderSuccessor(BinaryTreeNode * root, BinaryTreeNode * node)
{
	BinaryTreeStack * StackRead = new BinaryTreeStack();
	BinaryTreeStack * StackProcessed = new BinaryTreeStack();

	BinaryTreeNode * temp = new BinaryTreeNode();

	if (root == NULL) return NULL;
	BTNS_Push(StackRead, root);

	while (!BTNS_IsEmptyStack(StackRead))
	{
		temp = BTNS_Pop(StackRead);

		if (temp->getright())	BTNS_Push(StackRead, temp->getright());
		if (temp->getleft())	BTNS_Push(StackRead, temp->getleft());

		if (StackProcessed->top == node)
		{
			return temp;
		}
		else
		{
			BTNS_Push(StackProcessed, temp);
		}
	}

	return NULL;//Where there is no Pre Order Successor Super Right Leaf :p
}

BinaryTreeNode * PreOrderPredecessor(BinaryTreeNode * root, BinaryTreeNode * node)
{
	BinaryTreeStack * StackRead = new BinaryTreeStack();
	BinaryTreeStack * StackProcessed = new BinaryTreeStack();

	BinaryTreeNode * temp = new BinaryTreeNode();

	if (root == NULL) return NULL;
	BTNS_Push(StackRead, root);

	while (!BTNS_IsEmptyStack(StackRead))
	{
		temp = BTNS_Pop(StackRead);

		if (temp->getright())	BTNS_Push(StackRead, temp->getright());
		if (temp->getleft())	BTNS_Push(StackRead, temp->getleft());

		if (temp == node) return BTNS_Pop(StackProcessed);

		BTNS_Push(StackProcessed, temp);
	}
}

ThreadedBinaryTreeNode * CreateThreadedBinaryTree(BinaryTreeNode * root)
{
	BinaryTreeQueue * readQueue = new BinaryTreeQueue();
	vector<ThreadedBinaryTreeNode *> TBTVector;

	ThreadedBinaryTreeNode * tempTBT;
	ThreadedBinaryTreeNode * tempTBTleft;
	ThreadedBinaryTreeNode * tempTBTright;

	BinaryTreeNode * tempBT;
	BinaryTreeNode * tempBTPre;
	BinaryTreeNode * tempBTSuc;

	if (root == NULL) return NULL;

	BTNQ_EnQueue(readQueue, root);

	while (!BTNQ_IsEmptyQueue(readQueue))
	{
		tempBT = new BinaryTreeNode();
		tempBT = BTNQ_DeQueue(readQueue);

		//copying data
		tempTBT = new ThreadedBinaryTreeNode();
		tempTBT->setdata(tempBT->getdata());


		//left node of Threaded BT
		tempTBTleft = new ThreadedBinaryTreeNode();
		if (tempBT->getleft())
		{
			BTNQ_EnQueue(readQueue, tempBT->getleft());

			//setting lTag
			tempTBT->setlTag(true);
			
			//determining the data of left
			tempTBTleft->setdata((tempBT->getleft())->getdata());
		}
		else
		{
			//setting lTag
			tempTBT->setlTag(false);

			//determining the data of left
			tempBTPre = new BinaryTreeNode();
			tempBTPre = PreOrderPredecessor(root, tempBT);
			tempTBTleft->setdata((tempBTPre==NULL)?0:tempBTPre->getdata());
		}
		tempTBT->setleft(tempTBTleft);

		//-------------------------------------------------------------------

		//right node of Threaded BT
		tempTBTright = new ThreadedBinaryTreeNode();
		if (tempBT->getright())
		{
			BTNQ_EnQueue(readQueue, tempBT->getright());

			//setting rTag
			tempTBT->setrTag(true);

			//determining the data of right
			tempTBTright->setdata((tempBT->getright())->getdata());
		}
		else
		{
			//setting rTag
			tempTBT->setrTag(false);

			//determining the data of left
			tempBTSuc = new BinaryTreeNode();
			tempBTSuc = PreOrderSuccessor(root, tempBT);
			tempTBTright->setdata((tempBTSuc==NULL)?0:tempBTSuc->getdata());
		}
		tempTBT->setright(tempTBTright);

		//-------------------------------------------------------------------

		TBTVector.push_back(tempTBT);
	}

}

void TBT_Creation_main()
{
	//----------------------------------------------------------------------------------------------------
	/*									Binary Tree
								   ---- 1=root=100 ----
								/						\
							2=200						3=300
							/	\						/	\
						4=400	5=500				6=600	7=700
								/								\
							8=800								9=900


				In Order: 400 - 200 - 800 - 500 - 100 - 600 - 300 - 700 - 900
			   Pre Order: 100 - 200 - 400 - 500 - 800 - 300 - 600 - 700 - 900
	*/
	//----------------------------------------------------------------------------------------------------


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

	root->setleft(node2);
	root->setright(node3);

	node2->setleft(node4);
	node2->setright(node5);

	node3->setleft(node6);
	node3->setright(node7);

	node5->setleft(node8);

	node7->setright(node9);


	//----------------------------------------------------------------------------------------------------
	cout << "PreOrder Predecessor of " << root->getdata() << " = " << (PreOrderPredecessor(root, root)) << "\n";//returns NULL...so, not doing getdata() here
	cout << "PreOrder Predecessor of " << node2->getdata() << " = " << (PreOrderPredecessor(root, node2))->getdata() << "\n";
	cout << "PreOrder Predecessor of " << node3->getdata() << " = " << (PreOrderPredecessor(root, node3))->getdata() << "\n";
	cout << "PreOrder Predecessor of " << node4->getdata() << " = " << (PreOrderPredecessor(root, node4))->getdata() << "\n";
	cout << "PreOrder Predecessor of " << node5->getdata() << " = " << (PreOrderPredecessor(root, node5))->getdata() << "\n";
	cout << "PreOrder Predecessor of " << node6->getdata() << " = " << (PreOrderPredecessor(root, node6))->getdata() << "\n";
	cout << "PreOrder Predecessor of " << node7->getdata() << " = " << (PreOrderPredecessor(root, node7))->getdata() << "\n";
	cout << "PreOrder Predecessor of " << node8->getdata() << " = " << (PreOrderPredecessor(root, node8))->getdata() << "\n";
	cout << "PreOrder Predecessor of " << node9->getdata() << " = " << (PreOrderPredecessor(root, node9))->getdata() << "\n";
	//----------------------------------------------------------------------------------------------------
	cout << "-----------------------------------------\n";
	//----------------------------------------------------------------------------------------------------
	cout << "PreOrder Successor of " << root->getdata() << " = " << (PreOrderSuccessor(root, root))->getdata() << "\n";
	cout << "PreOrder Successor of " << node2->getdata() << " = " << (PreOrderSuccessor(root, node2))->getdata() << "\n";
	cout << "PreOrder Successor of " << node3->getdata() << " = " << (PreOrderSuccessor(root, node3))->getdata() << "\n";
	cout << "PreOrder Successor of " << node4->getdata() << " = " << (PreOrderSuccessor(root, node4))->getdata() << "\n";
	cout << "PreOrder Successor of " << node5->getdata() << " = " << (PreOrderSuccessor(root, node5))->getdata() << "\n";
	cout << "PreOrder Successor of " << node6->getdata() << " = " << (PreOrderSuccessor(root, node6))->getdata() << "\n";
	cout << "PreOrder Successor of " << node7->getdata() << " = " << (PreOrderSuccessor(root, node7))->getdata() << "\n";
	cout << "PreOrder Successor of " << node8->getdata() << " = " << (PreOrderSuccessor(root, node8))->getdata() << "\n";
	cout << "PreOrder Successor of " << node9->getdata() << " = " << (PreOrderSuccessor(root, node9)) << "\n";//returns NULL...so, not doing getdata() here
	//----------------------------------------------------------------------------------------------------
	//----------------------------------------------------------------------------------------------------

	CreateThreadedBinaryTree(root);
}