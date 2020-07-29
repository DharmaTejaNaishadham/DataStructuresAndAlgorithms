#include <iostream>
using namespace std;

class GenericTreeNode
{
	int data;
	GenericTreeNode * firstChild;
	GenericTreeNode * nextSibling;

	public:
		GenericTreeNode()
		{
			data = 0; firstChild = NULL; nextSibling = NULL;
		}

		int getdata() { return data; }
		GenericTreeNode * getfirstChild() { return firstChild; }
		GenericTreeNode * getnextSibling() { return nextSibling; }

		void setdata(int value) { data = value; }
		void setfirstChild(GenericTreeNode * first) { firstChild = first; }
		void setnextSibling(GenericTreeNode * next) { nextSibling = next; }
};

void GT_HeightOrDepth_main();

void GT_NumOfChildren_main();

void GT_NumOfSiblings_main();

void GT_SumOfElements_main();