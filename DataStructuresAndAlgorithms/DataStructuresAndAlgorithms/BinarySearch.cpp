#include <iostream>
using namespace std;

#include <vector>

int BinarySearch(vector<int> arr, int searchFor, int start, int end)
{
	int middle = (start + end) / 2;

	if (arr[middle] == searchFor)
		return middle;

	if (start == end)//start==middle==end
		return -1;

	if (arr[middle] > searchFor)
		return BinarySearch(arr, searchFor, start, middle - 1);

	else
		return BinarySearch(arr, searchFor, middle + 1, end);

}

int BinarySearchNonRec(vector<int> arr, int searchFor, int start, int end)
{
	while (start <= end)
	{
		int middle = (start + end) / 2;

		if (arr[middle] == searchFor)
			return middle;

		if (arr[middle] > searchFor)
			end = middle - 1;

		else
			start = middle + 1;		
	}

	return -1;
}

void BinarySearch_main()
{
#pragma region Preparation

	vector<int> arr;
	arr.assign({ 0, 1, 2, 4, 5, 6, 7 });

#pragma endregion

#pragma region Execution

	cout << BinarySearchNonRec(arr, 3, 0, arr.size() - 1) << "\n";
	cout << BinarySearch(arr, 3, 0, arr.size() - 1) << "\n";

#pragma endregion	

#pragma region Execution

	cout << BinarySearchNonRec(arr, 6, 0, arr.size() - 1) << "\n";
	cout << BinarySearch(arr, 6, 0, arr.size() - 1) << "\n";

#pragma endregion	

#pragma region Execution

	cout << BinarySearchNonRec(arr, 0, 0, arr.size() - 1) << "\n";
	cout << BinarySearch(arr, 0, 0, arr.size() - 1) << "\n";

#pragma endregion	

#pragma region Execution

	cout << BinarySearchNonRec(arr, 7, 0, arr.size() - 1) << "\n";
	cout << BinarySearch(arr, 7, 0, arr.size() - 1) << "\n";

#pragma endregion	

#pragma region Execution

	cout << BinarySearchNonRec(arr, -1, 0, arr.size() - 1) << "\n";
	cout << BinarySearch(arr, -1, 0, arr.size() - 1) << "\n";

#pragma endregion	

#pragma region Execution

	cout << BinarySearchNonRec(arr, 9, 0, arr.size() - 1) << "\n";
	cout << BinarySearch(arr, 9, 0, arr.size() - 1) << "\n";

#pragma endregion	
}