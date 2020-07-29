#include <iostream>
using namespace std;

#include "GenericT.h"

int GT_SumOfElements(GenericTreeNode * root)
{
	static int sum;

	if (root == NULL) return 0;//return 0 is hit only in the stupid case...first function caller sends root==NULL

	sum += root->getdata();//can be written as data + Recfn(first) + Recfn(next)

	//having these ifs to reduce some of the recursive calls...now that we don't rec. call by passing nulls, return 0 is not hit in usual cases
	if (root->getfirstChild())	GT_SumOfElements(root->getfirstChild());
	if (root->getnextSibling()) GT_SumOfElements(root->getnextSibling());

	return sum;
}

void GT_SumOfElements_main()
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

	cout<<"Sum of the elements in the Generic Tree = "<<GT_SumOfElements(root)<<"\n";

	//----------------------------------------------------------------------------------------------------
}