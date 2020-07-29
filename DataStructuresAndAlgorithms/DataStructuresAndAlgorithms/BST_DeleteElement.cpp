#include <iostream>
using namespace std;

#include "BT.h"

BinaryTreeNode * BST_DeleteElement(BinaryTreeNode * root, int data)
{
	BinaryTreeNode * DelElement = new BinaryTreeNode();
	BinaryTreeNode * DelElementParent = new BinaryTreeNode();
	int temp;

	if (root == NULL)	return NULL;

	//Navigate till the data node
	DelElement = root;
	while(DelElement->getdata() != data && DelElement)
	{
		if (DelElement->getdata() > data)
		{
			DelElementParent = DelElement;
			DelElement = DelElement->getleft();
		}
		if (DelElement->getdata() < data)
		{
			DelElementParent = DelElement;
			DelElement = DelElement->getright();
		}
	}

	//Case where we don't find the key
	if (DelElement == NULL) return NULL;

	//We found the key
	//Cases where DelElement has no child
	if(DelElement->getleft() == NULL && DelElement->getright() == NULL)
	{
		if (DelElementParent->getdata() > data)
		{
			DelElementParent->setleft(NULL);
		}
		else
		{
			DelElementParent->setright(NULL);
		}
		free(DelElement);
		return root;
	}
	
	//Cases where DelElement has only 1 child
	if (DelElement->getleft() != NULL && DelElement->getright() == NULL)//left - value && right - NULL 
	{
		if (DelElementParent->getdata() > data)
		{
			DelElementParent->setleft(DelElement->getleft());
		}
		else
		{
			DelElementParent->setright(DelElement->getleft());
		}
		
		free(DelElement);
		return root;
	}
	else if(DelElement->getleft() == NULL && DelElement->getright() != NULL)//left - NULL && right - value
	{
		if (DelElementParent->getdata() > data)
		{
			DelElementParent->setleft(DelElement->getright());
		}
		else
		{
			DelElementParent->setright(DelElement->getright());
		}
		
		free(DelElement);
		return root;
	}
	
	//Cases where DelElement has both children
	else
	{
		//Bacha fellow...ne level endo ardham indi ga :p
		/*if (DelElementParent->getdata() > data)
		{
			DelElementParent->setleft(DelElement->getright());
		}
		else
		{
			DelElementParent->setright(DelElement->getleft());
		}*/

		temp = BST_FindMax_NonRec(DelElement->getleft())->getdata();
		DelElement = BST_DeleteElement(DelElement, temp);
		DelElement->setdata(temp);

		return root;
	}
}

void BST_DeleteElement_main()
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
	node2->setdata(200);

	BinaryTreeNode *node3 = new BinaryTreeNode();
	node3->setdata(300);

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

	//---------------------------------------------------------------------
	InOrderRec(root);
	cout << "------------------------\n";
	
	root = BST_DeleteElement(root, 100);
	InOrderRec(root);
	cout << "------------------------\n";

	root = BST_DeleteElement(root, 200);
	InOrderRec(root);
	cout << "------------------------\n";

	root = BST_DeleteElement(root, 800);
	InOrderRec(root);
	cout << "------------------------\n";
	//---------------------------------------------------------------------
}