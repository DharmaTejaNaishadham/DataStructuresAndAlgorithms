#include <iostream>
using namespace std;

class BinaryTreeNode
{
	int data;
	class BinaryTreeNode *left;
	class BinaryTreeNode *right;

	class BinaryTreeNode *next;//to be used in Binary Tree Queue/Stack
	public:
		BinaryTreeNode()
		{
			data = 0; left = NULL; right = NULL; next = NULL;
		}

		int getdata() { return data; }

		BinaryTreeNode* getleft() { return left; }
		BinaryTreeNode* getright() { return right; }
		BinaryTreeNode* getnext() { return next; }

		void setdata(int value) { data = value; }

		void setleft(BinaryTreeNode *ptr) { left = ptr; }
		void setright(BinaryTreeNode *ptr) { right = ptr; }
		void setnext(BinaryTreeNode *ptr) { next = ptr; }
};

void PreOrderRec(BinaryTreeNode *root);

void InOrderRec(BinaryTreeNode *root);

void PostOrderRec(BinaryTreeNode *root);

int BT_Height(BinaryTreeNode * root);

//BST related Functions
BinaryTreeNode * BST_FindMin_Rec(BinaryTreeNode * root);
BinaryTreeNode * BST_FindMin_NonRec(BinaryTreeNode * root);

BinaryTreeNode * BST_FindMax_Rec(BinaryTreeNode * root);
BinaryTreeNode * BST_FindMax_NonRec(BinaryTreeNode * root);

//Adding it here to avoid duplicate code blocks
int LeftOrRight(BinaryTreeNode * root, BinaryTreeNode * node);