#include <iostream>
using namespace std;

#include <vector>

#include "RandomProblems.h"

int SearchInRotatedSortedArray(vector<int> arr, int searchFor)
{
	int rangeStart = 0, rangeEnd = arr.size() - 1;
	int pivot = 0;

	//We are figuring out the pivot which is also the smallest no.
	while (1)
	{
		pivot = (rangeStart + rangeEnd) / 2;

		//trying over luck :p
		//if we can find searchFor before pivot that calls for a party :D
		if (arr[pivot] == searchFor) 
			return pivot;

		if (arr[pivot] < arr[pivot - 1] && arr[pivot] < arr[pivot + 1])
			break;

		if (arr[pivot] > arr[rangeStart])
			rangeStart = pivot;
		else
			rangeEnd = pivot;
	}		

	if (searchFor >= arr[0])
		return BinarySearchNonRec(arr, searchFor, 0, pivot - 1);
	else
		return BinarySearchNonRec(arr, searchFor, pivot + 1, arr.size() - 1);
}

void SearchInRotatedSortedArray_main()
{
	/*
	Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

	(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

	You are given a target value to search. If found in the array return its index, otherwise return -1.

	You may assume no duplicate exists in the array.

	Your algorithm's runtime complexity must be in the order of O(log n).
	*/
#pragma region Preparation

	vector<int> arr;
	arr.assign({ 4, 5, 6, 7, 8, 9, 10, 11, 12, 0, 1, 2 });

#pragma endregion

#pragma region Execution

	cout << SearchInRotatedSortedArray(arr, 3) << "\n";

#pragma endregion	

#pragma region Preparation

	arr.assign({ 10, 11, 12, 13, 14, 15, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 });

#pragma endregion

#pragma region Execution

	cout << SearchInRotatedSortedArray(arr, 3) << "\n";

#pragma endregion	

#pragma region Preparation

	arr.assign({ 10, 11, 12, 13, 14, 15, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 });

#pragma endregion

#pragma region Execution

	cout << SearchInRotatedSortedArray(arr, 10) << "\n";

#pragma endregion	

#pragma region Preparation

	arr.assign({ 10, 11, 12, 13, 14, 15, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 });

#pragma endregion

#pragma region Execution

	cout << SearchInRotatedSortedArray(arr, 9) << "\n";

#pragma endregion	
}