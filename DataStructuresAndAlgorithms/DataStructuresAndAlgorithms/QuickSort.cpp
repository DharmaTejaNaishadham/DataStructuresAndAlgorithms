#include <iostream>
using namespace std;

#include <vector>

vector<int> QuickSort(vector<int> num, int startPosition, int pivotPosition)
{
	if (startPosition > pivotPosition)
		return num;

	int i = startPosition;
	int endPosition = pivotPosition;

	while (i != pivotPosition)
	{
		if (num[i] > num[pivotPosition])
		{
			int temp = num[i];
			num[i] = num[pivotPosition - 1];
			num[pivotPosition - 1] = num[pivotPosition];
			num[pivotPosition] = temp;
			pivotPosition--;
		}
		else
		{
			i++;
		}
	}

	num = QuickSort(num, startPosition, pivotPosition - 1);
	num = num = QuickSort(num, pivotPosition + 1, endPosition);

	return num;
}

void QuickSort_main()
{
#pragma region Preparation

	vector<int> num;
	num.assign({ 0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 15, 7, 11 });

#pragma endregion

#pragma region Execution

	num = QuickSort(num, 0, num.size() - 1);

	for (int i = 0; i < num.size(); i++)
		cout << num[i] << "\t";

#pragma endregion	
}