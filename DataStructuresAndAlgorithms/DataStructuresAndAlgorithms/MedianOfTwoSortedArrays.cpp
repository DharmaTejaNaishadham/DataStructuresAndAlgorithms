#include <iostream>
using namespace std;

#include <vector>

double MedianOfTwoSortedArrays(vector<int> sortedArray1, vector<int> sortedArray2)
{
	double median = 0.0;

	int size1 = sortedArray1.size();
	int size2 = sortedArray2.size();	
	int pos = (size1 + size2) / 2;
	
	int index1 = 0, index2 = 0;
	int numAtPos = 0, numAtNextPos = 0;
	while (1)
	{	
		if (index1 < size1 && sortedArray1[index1] < sortedArray2[index2])
		{
			if ((index1 + index2) == pos - 1)
			{
				numAtPos = sortedArray1[index1];
			}

			if ((index1 + index2) == pos)
			{
				numAtNextPos = sortedArray1[index1];
				break;
			}

			index1++;
		}
		else if (index2 < size2)
		{			
			if ((index1 + index2) == pos - 1)
			{
				numAtPos = sortedArray2[index2];
			}

			if ((index1 + index2) == pos)
			{
				numAtNextPos = sortedArray2[index2];
				break;
			}

			index2++;
		}					
	}		

	if ((size1 + size2) % 2 == 0)
		return ((double)numAtPos + (double)numAtNextPos) / 2;
	else
		return numAtNextPos;
}

void MedianOfTwoSortedArrays_main()
{
#pragma region Preparation

	vector<int> sortedArray1;
	sortedArray1.assign({ 1, 3, 4, 6, 7 });

	vector<int> sortedArray2;
	sortedArray2.assign({ 2, 5, 8 });

#pragma endregion

#pragma region Execution

	cout << MedianOfTwoSortedArrays(sortedArray1, sortedArray2) << "\n";

#pragma endregion	

#pragma region Preparation
	
	sortedArray1.assign({ 1, 3, 4 });
	
	sortedArray2.assign({ 2, 5, 6, 7, 8 });

#pragma endregion

#pragma region Execution

	cout << MedianOfTwoSortedArrays(sortedArray1, sortedArray2) << "\n";

#pragma endregion

#pragma region Preparation

	sortedArray1.assign({ 1, 3, 4, 6, 7 });

	sortedArray2.assign({ 2, 5 });

#pragma endregion

#pragma region Execution

	cout << MedianOfTwoSortedArrays(sortedArray1, sortedArray2) << "\n";

#pragma endregion

#pragma region Preparation

	sortedArray1.assign({ 1, 3, 5 });

	sortedArray2.assign({ 2, 4, 6, 7 });

#pragma endregion

#pragma region Execution

	cout << MedianOfTwoSortedArrays(sortedArray1, sortedArray2) << "\n";

#pragma endregion

#pragma region Preparation

	sortedArray1.assign({ 1, 3 });

	sortedArray2.assign({ 2 });

#pragma endregion

#pragma region Execution

	cout << MedianOfTwoSortedArrays(sortedArray1, sortedArray2) << "\n";

#pragma endregion
}