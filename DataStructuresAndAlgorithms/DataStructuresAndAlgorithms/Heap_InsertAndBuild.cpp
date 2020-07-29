#include <iostream>
using namespace std;

#include "Heap.h"
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

int Heap_getParent(Heap * h, int child_position)
{
	if (child_position == 0) return -1;//there is no parent for the max (or) first element

	if (child_position > h->getcount())	return -1;//someone is desperately trying to break ur program

	return (child_position - 1) / 2;

}

int Heap_getLeftChild(Heap * h, int parent_position)
{
	int left = (2 * parent_position) + 1;

	if (left >= h->getcount())	return INT8_MIN;

	return h->getElementAt(left);
}

int Heap_getRightChild(Heap * h, int parent_position)
{
	int right = (2 * parent_position) + 2;

	if (right >= h->getcount())	return INT8_MIN;

	return h->getElementAt(right);
}

int Heap_getMaxElement(Heap * h)
{
	if (h->getcount() == 0) return -1;
	return h->getElementAt(0);
}

int Heap_getLeftPosition(Heap * h, int parent_position)
{
	int left = (2 * parent_position) + 1;

	if (left >= h->getcount())	return -1;

	return left;
}

int Heap_getRightPosition(Heap * h, int parent_position)
{
	int right = (2 * parent_position) + 2;

	if (right >= h->getcount())	return -1;

	return right;
}

void Heap_PercolateUp(Heap * h, int position)
{
	int parent, left, right, leftPosition, rightPosition, temp;

	parent = h->getElementAt(position);
	left = Heap_getLeftChild(h, position);
	right = Heap_getRightChild(h, position);
	leftPosition = Heap_getLeftPosition(h, position);
	rightPosition = Heap_getRightPosition(h, position);

	if (h->getHeap_Type() == 1)
	{
		if (parent > left && parent >= right) return;
		else
		{
			if (left > right)
			{
				temp = left;
				h->setElementAt(leftPosition, parent);
				h->setElementAt(position, temp);

				Heap_PercolateUp(h, leftPosition);
			}
			else
			{
				temp = right;
				h->setElementAt(rightPosition, parent);
				h->setElementAt(position, temp);

				Heap_PercolateUp(h, rightPosition);
			}
		}
	}
	else//min heap
	{
		if (leftPosition == -1 && rightPosition == -1) return;
		else if (leftPosition == -1 && rightPosition != -1)
		{
			if (parent > right)
			{
				temp = right;
				h->setElementAt(rightPosition, parent);
				h->setElementAt(position, temp);

				Heap_PercolateUp(h, rightPosition);
			}
		}
		else if (leftPosition != -1 && rightPosition == -1)
		{
			if (parent > left)
			{
				temp = left;
				h->setElementAt(leftPosition, parent);
				h->setElementAt(position, temp);

				Heap_PercolateUp(h, leftPosition);
			}
		}
		else//both having values
		{
			if (parent < left && parent <= right) return;
			else
			{
				if (left < right)
				{
					temp = left;
					h->setElementAt(leftPosition, parent);
					h->setElementAt(position, temp);

					Heap_PercolateUp(h, leftPosition);
				}
				else
				{
					temp = right;
					h->setElementAt(rightPosition, parent);
					h->setElementAt(position, temp);

					Heap_PercolateUp(h, rightPosition);
				}
			}
		}
	}
}

void Heap_InsertElement(Heap * h, int data)
{
	//haha...bokka padindi...we can't let 0s in our vector...we need to replace them
	//h->elements.push_back(data);

	h->elements.resize(h->getcount() + 1);//heap starts at vector size 0...we increment the size as in when we get an element to insert
	h->setElementAt(h->getcount(), data);
	h->setcount(h->getcount() + 1);
}

int Heap_DeleteMaxOrMin(Heap * h)
{
	int data;

	if (h->getcount() == 0)
		return -1;

	data = h->getElementAt(0);
	h->setElementAt(0, h->getElementAt(h->getcount() - 1));//we delete the top element in the heap & replace it with the last element

	//nullifying the last element...it'll anyways be replaced by the next element...keeping it 0 till then
	//h->setElementAt(h->getcount() - 1, 0);

	//even better - imagine u had 100 elements, 99 got deleted & u r not getting any more inputs...it'll be huge space wastage.
	h->elements.resize(h->elements.size() - 1);

	h->setcount(h->getcount() - 1);

	Heap_PercolateUp(h, 0);

	return data;
}

void Heap_PrintHeap(Heap *h)
{
	if (h->getcount() == 0)
		return;

	for (int i = 0; i < h->getcount(); i++)
	{
		cout << h->getElementAt(i) << "\t";
	}
	cout << "\n";
}

void Heap_BuildHeap(Heap * h)
{
	for (int i = (h->getcount() - 1) / 2; i >= 0; i--)
	{
		Heap_PercolateUp(h, i);
	}
}

void Heap_InsertAndBuild_main()
{
#pragma region Preparation

	Heap * h = new Heap(1);//Heap * h = new Heap(-1);//-1 => min heap
	Heap_InsertElement(h, 6);
	Heap_InsertElement(h, 1);
	Heap_InsertElement(h, 17);
	Heap_InsertElement(h, 2);
	Heap_InsertElement(h, 15);
	Heap_InsertElement(h, 4);
	Heap_InsertElement(h, 3);

#pragma endregion

#pragma region Execution

	Heap_PrintHeap(h);

	Heap_BuildHeap(h);
	Heap_PrintHeap(h);

	Heap_DeleteMaxOrMin(h);
	Heap_PrintHeap(h);

	Heap_InsertElement(h, 25);
	Heap_InsertElement(h, 5);
	Heap_BuildHeap(h);
	Heap_PrintHeap(h);

	Heap_DeleteMaxOrMin(h);
	Heap_PrintHeap(h);

	Heap_DeleteMaxOrMin(h);
	Heap_PrintHeap(h);

#pragma endregion
}