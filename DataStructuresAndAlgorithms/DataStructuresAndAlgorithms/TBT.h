#include <iostream>
using namespace std;

class ThreadedBinaryTreeNode//Fully Threaded PreOrder Binary Tree
{
	int data;
	class ThreadedBinaryTreeNode *left;
	class ThreadedBinaryTreeNode *right;

	class ThreadedBinaryTreeNode *next;//to be used in Binary Tree Queue/Stack

	bool lTag;//if(lTag == 1)? left child : Thread to PreOrder predecessor
	bool rTag;//if(lTag == 1)? left child : Thread to PreOrder successor

public:
	ThreadedBinaryTreeNode()
	{
		data = 0; left = NULL; right = NULL; next = NULL; lTag = 0; rTag = 0;
	}

	int getdata() { return data; }

	ThreadedBinaryTreeNode* getleft() { return left; }
	ThreadedBinaryTreeNode* getright() { return right; }
	ThreadedBinaryTreeNode* getnext() { return next; }
	
	bool getlTag(){ return lTag; }
	bool getrTag() { return rTag; }

	void setdata(int value) { data = value; }

	void setleft(ThreadedBinaryTreeNode *ptr) { left = ptr; }
	void setright(ThreadedBinaryTreeNode *ptr) { right = ptr; }
	void setnext(ThreadedBinaryTreeNode *ptr) { next = ptr; }

	void setlTag(bool flag) { lTag = flag; }
	void setrTag(bool flag) { rTag = flag; }
};

//void PreOrderRec(ThreadedBinaryTreeNode *root);
//
//void InOrderRec(ThreadedBinaryTreeNode *root);
//
//void PostOrderRec(ThreadedBinaryTreeNode *root);
//
//int BT_Height(ThreadedBinaryTreeNode * root);

void TBT_Creation_main();