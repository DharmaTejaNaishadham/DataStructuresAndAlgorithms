#include <iostream>
using namespace std;

#include <vector>

int kthSmallest(vector<int> arr1, vector<int> arr2, int k)
{
	int i = 0, j = 0;

	while (i < arr1.size() || j < arr2.size())
	{
		if (((i < arr1.size()) ? arr1[i] : INT16_MAX) < ((j < arr2.size()) ? arr2[j] : INT16_MAX))
		{
			i++;
			if ((i + j) == k)
				return arr1[i-1];
		}			
		else
		{
			j++;
			if ((i + j) == k)
				return arr2[j-1];
		}				
	}

	return NULL;
}

void kthSmallInTwoSortedArrays_main()
{
#pragma region Preparation

	vector<int> arr1;
	arr1.assign({ 1, 2, 2, 13, 13, 26, 37, 38, 49, 100 });

	vector<int> arr2;
	arr2.assign({ 2, 5, 5, 11, 17, 25, 25, 48, 50, 51, 51, 52, 53, 60, 61 });

#pragma endregion

#pragma region Execution

	cout << "3rd smallest no. is " << kthSmallest(arr1, arr2, 3) << "\n";
	cout << "5th smallest no. is " << kthSmallest(arr1, arr2, 5) << "\n";
	cout << "8th smallest no. is " << kthSmallest(arr1, arr2, 8) << "\n";
	cout << "12th smallest no. is " << kthSmallest(arr1, arr2, 12) << "\n";
	cout << "18th smallest no. is " << kthSmallest(arr1, arr2, 18) << "\n";
	cout << "21st smallest no. is " << kthSmallest(arr1, arr2, 21) << "\n";
	cout << "25th smallest no. is " << kthSmallest(arr1, arr2, 25) << "\n";
	cout << "30th smallest no. is " << kthSmallest(arr1, arr2, 30) << "\n";

#pragma endregion
}