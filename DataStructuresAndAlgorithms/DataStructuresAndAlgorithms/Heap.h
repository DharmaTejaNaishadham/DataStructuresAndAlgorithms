#include <iostream>
using namespace std;

#include <vector>

/*
	-----------------------MAX Heap----------------------------------

							  17
							/	 \
						  15      6
						 /  \    /  \
						1	 4  3    2

	-----------------------------------------------------------------
	Elements:		17	-	15	-	6	-	1	-	4	-	3	-	2
	Location:		0		1		2		3		4		5		6
	-----------------------------------------------------------------

	Parent of element at i => element at (i - 1)/2

	Given a parent at i:
	left child  = (2 * i) + 1 
	right child = (2 * i) + 2
*/

class Heap
{	
	int count;//no. of elements in the Heap
	int heap_Type;//(1 - Max Heap, -1 - Min Heap) 

	public:
	vector<int> elements;//vector to store elements

	//Heap(int hType = 1);//Max Heap by default

	Heap(int hType = 1)
	{
		elements.clear();
		count = 0;
		heap_Type = hType;
	}

	int getcount() { return count; }
	void setcount(int cnt) { count = cnt; }

	int getHeap_Type() { return heap_Type; }

	int getElementAt(int pos) { return elements[pos]; }
	void setElementAt(int pos, int value) { elements[pos] = value; }
};

int Heap_getParent(Heap * h, int child_position);

int Heap_getLeftChild(Heap * h, int parent_position);

int Heap_getRightChild(Heap * h, int parent_position);

int Heap_getMaxElement(Heap * h);

int Heap_getLeftPosition(Heap * h, int parent_position);

int Heap_getRightPosition(Heap * h, int parent_position);


void Heap_PercolateUp(Heap * h, int position);

void Heap_InsertElement(Heap * h, int data);

int Heap_DeleteMaxOrMin(Heap * h);

void Heap_PrintHeap(Heap *h);

void Heap_InsertAndBuild_main();