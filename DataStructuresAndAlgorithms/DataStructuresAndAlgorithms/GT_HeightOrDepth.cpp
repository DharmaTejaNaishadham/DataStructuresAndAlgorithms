#include <iostream>
using namespace std;

#include "GenericT.h"

int GT_HeightOrDepth(GenericTreeNode * root, int height)
{
	static int maxHeight;

	if (root == NULL) return 0;
	
	if (root->getfirstChild())
		GT_HeightOrDepth(root->getfirstChild(), height + 1);
	
	if (root->getnextSibling())
		GT_HeightOrDepth(root->getnextSibling(),height);
	
	maxHeight = (maxHeight > height) ? maxHeight : height;

	return maxHeight;
}

void GT_HeightOrDepth_main()
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

	cout << "Height (or) Depth of the Generic Tree " << root->getdata() << "  = " << GT_HeightOrDepth(root,0) << "\n";
	
	//----------------------------------------------------------------------------------------------------
}