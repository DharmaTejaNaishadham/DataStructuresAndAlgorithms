#include <iostream>
using namespace std;

#include "GenericT.h"

int GT_NumOfChildren(GenericTreeNode * root)
{
	int num = 0;

	if (root == NULL) return 0;
	
	if (root->getfirstChild())
	{
		num++;
		root = root->getfirstChild();

		while (root->getnextSibling())
		{
			num++;
			root = root->getnextSibling();
		}
	}

	return num;
}

void GT_NumOfChildren_main()
{
	/*
	..................Generic Tree looks like this......................
	10
	/
	20	-	30	-	40	-	50
			/				/
			60              70
			/
			80
	....................................................................
	*/

	GenericTreeNode * root = new GenericTreeNode();
	GenericTreeNode * node2 = new GenericTreeNode();
	GenericTreeNode * node3 = new GenericTreeNode();
	GenericTreeNode * node4 = new GenericTreeNode();
	GenericTreeNode * node5 = new GenericTreeNode();
	GenericTreeNode * node6 = new GenericTreeNode();
	GenericTreeNode * node7 = new GenericTreeNode();
	GenericTreeNode * node8 = new GenericTreeNode();

	root->setdata(10);
	root->setfirstChild(node2);

	node2->setdata(20);
	node2->setnextSibling(node3);

	node3->setdata(30);
	node3->setfirstChild(node6);
	node3->setnextSibling(node4);

	node4->setdata(40);
	node4->setnextSibling(node5);

	node5->setdata(50);
	node5->setfirstChild(node7);

	node6->setdata(60);
	node6->setfirstChild(node8);

	node7->setdata(70);

	node8->setdata(80);


	//----------------------------------------------------------------------------------------------------

	cout << "No. of the Children of the node " << root->getdata() << " in the Generic Tree = " << GT_NumOfChildren(root) << "\n";
	cout << "No. of the Children of the node " << node3->getdata() << " in the Generic Tree = " << GT_NumOfChildren(node3) << "\n";
	cout << "No. of the Children of the node " << node4->getdata() << " in the Generic Tree = " << GT_NumOfChildren(node4) << "\n";
	cout << "No. of the Children of the node " << node8->getdata() << " in the Generic Tree = " << GT_NumOfChildren(node8) << "\n";

	//----------------------------------------------------------------------------------------------------
}