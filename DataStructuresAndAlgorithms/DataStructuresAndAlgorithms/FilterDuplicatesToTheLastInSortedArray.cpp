#include <iostream>
using namespace std;

#include <vector>

void FilterDuplicatesToTheLastInSortedArray_main()
{
/*
Given a sorted array nums, remove the duplicates in-place such that each element appear only once and return the new length.
Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

Ex:
Given nums = [0,0,1,1,1,2,2,3,3,4],
Your function should return length = 5, with the first five elements of nums being modified to 0, 1, 2, 3, and 4 respectively.
It doesn't matter what values are set beyond the returned length.
*/
	vector<int> arr;
	arr.assign({ 0, 0, 1, 1, 1, 2, 2, 3, 3, 4 });	

	int index = 1;

	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i] > arr[index-1])
		{
			arr[index] = arr[i];
			index++;
		}
	}

	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << " ";
	}
	cout << "\n";

	cout << "New length = " << index << "\n";
}