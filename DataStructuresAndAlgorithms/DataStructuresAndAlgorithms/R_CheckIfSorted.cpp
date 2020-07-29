#include <iostream>
using namespace std;

#include "RecursionAndBacktracking.h"

int CheckIfSorted(int a[], int size)
{
	if (size == 1)
	{
		return 1;
	}
	else
		return (a[size - 1] > a[size - 2]) ? 0 : CheckIfSorted(a, size - 1);
}


void R_CheckIfSorted_main()
{	
#pragma region Preparation

	int size;
	cout << "enter the no. of numbers in the array: ";
	cin >> size;

	int *arr;
	arr = (int*)malloc(size);

	cout << "enter " << size << " numbers (seperated by space): ";
	for (int i = 0; i < size; i++)
		cin >> arr[i];

	for (int i = 0; i < size; i++)
		cout << arr[i] << "\n";

#pragma endregion

#pragma region Execution

	int result;
	result = CheckIfSorted(arr, size);

	if (result == 1) cout << "The array is sorted in DESCENDING ORDER";
	else cout << "The array is NOT sorted in Descending Order";

#pragma endregion	
}