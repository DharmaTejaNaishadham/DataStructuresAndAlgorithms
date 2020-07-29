#include <iostream>
using namespace std;

#include "BT.h"
#include <vector>

vector<BinaryTreeNode *> inOrder;

void CreateInOrderVector(BinaryTreeNode *root)
{
	static int elementNo;
	
	if (root != NULL)
	{
		CreateInOrderVector(root->getleft());
		
		//process
		inOrder.push_back(root);

		CreateInOrderVector(root->getright());
	}	
}

void CorrectVecorWithExactly2Bad()
{
	int i = 0, j = inOrder.size() - 1;
	bool iStop = false, jStop = false;
	
	int temp;

	while (1)
	{
		if (!iStop)
		{
			if (inOrder[i]->getdata() > inOrder[i + 1]->getdata())
			{
				iStop = true;
			}
			else
			{
				i++;
			}
		}

		if (!jStop)
		{
			if (inOrder[j - 1]->getdata() > inOrder[j]->getdata())
			{
				jStop = true;
			}
			else
			{
				j--;
			}
		}

		if ((i + 1 == j) || (iStop && jStop))
		{
			break;
		}
	}

	temp = inOrder[i]->getdata();
	inOrder[i]->setdata(inOrder[j]->getdata());
	inOrder[j]->setdata(temp);
}

//------------------

void Swap2Bad(BinaryTreeNode *root)
{
	static bool stop = false;
	
	static BinaryTreeNode * prev;
	static BinaryTreeNode * Bad1;
	static BinaryTreeNode * Bad2;
	
	int temp;

	if (root != NULL)
	{
		if (!stop)	Swap2Bad(root->getleft());
				
		if ((!stop) && (root->getdata() < ((prev == NULL) ? 0 : prev->getdata())))
		{
			if (Bad1 == NULL)
			{
				Bad1 = prev;
			}
			else
			{
				Bad2 = root;

				//Swapping Values
				temp = Bad2->getdata();				
				Bad2->setdata(Bad1->getdata());				
				Bad1->setdata(temp);
				
				stop = true;//As we cannot exit from recursion to main...just avoiding some unnecessary processing
			}			
		}
		prev = root;

		if (!stop)	Swap2Bad(root->getright());
	}
}


void BST_Swap2Bad_main()
{
	//----------------------------------------------------------------------------------------------------
	/*								Binary Search Tree

									---- 6=root=600 ----
								/						\
							4=400						8=800
							/	\						/	\
						2=200	5=500				7=700	9=900
						/	\
					1=100	3=300

				In Order: 100 - 200 - 300 - 400 - 500 - 600 - 700 - 800 - 900
	*/
	//----------------------------------------------------------------------------------------------------


	BinaryTreeNode *root = new BinaryTreeNode();
	root->setdata(600);

	BinaryTreeNode *node1 = new BinaryTreeNode();
	node1->setdata(100);

	BinaryTreeNode *node2 = new BinaryTreeNode();
	node2->setdata(300);

	BinaryTreeNode *node3 = new BinaryTreeNode();
	node3->setdata(200);

	BinaryTreeNode *node4 = new BinaryTreeNode();
	node4->setdata(400);

	BinaryTreeNode *node5 = new BinaryTreeNode();
	node5->setdata(500);

	/*BinaryTreeNode *node6 = new BinaryTreeNode();
	node6->setdata(600);*/

	BinaryTreeNode *node7 = new BinaryTreeNode();
	node7->setdata(700);

	BinaryTreeNode *node8 = new BinaryTreeNode();
	node8->setdata(800);

	BinaryTreeNode *node9 = new BinaryTreeNode();
	node9->setdata(900);

	root->setleft(node4);
	root->setright(node8);

	node4->setleft(node2);
	node4->setright(node5);

	node8->setleft(node7);
	node8->setright(node9);

	node2->setleft(node1);
	node2->setright(node3);

	//-------------------------------------------------------------------

	InOrderRec(root);

	/*cout << "\nAfter fix :\n";
	Swap2Bad(root);
	InOrderRec(root);*/


	CreateInOrderVector(root);
	CorrectVecorWithExactly2Bad();
	
	cout << "\nAfter fix :\n";
	InOrderRec(root);
}