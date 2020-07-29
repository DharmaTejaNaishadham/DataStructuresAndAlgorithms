#include <iostream>
using namespace std;

#include <vector>

int FirstMissingPositive(vector<int> arr)
{
	if (arr.size() == 0)
		return 0;

	for (int i = 0; i < arr.size(); i++)
		if ((arr[i] <= 0) || (arr[i] > arr.size()))
			arr[i] = (arr.size() + 100);

	for (int i = 0; i < arr.size(); i++)
	{
		int absolute = abs(arr[i]);

		if (absolute <= arr.size())
		{
			if (absolute == arr.size())
				arr[0] = (arr.size() + 100) * -1;

			else if (arr[absolute] == 0)
				arr[absolute] = (arr.size() + 100) * -1;

			else if (arr[absolute] > 0)
				arr[absolute] *= -1;
		}
	}

	for (int i = 1; i < arr.size(); i++)
		if (arr[i] > 0)
			return i;

	if (arr[0] > 0)
		return arr.size();
	else
		return arr.size() + 1;
}

void FirstMissingPositive_main()
{
#pragma region Preparation

	vector<int> arr;
	arr.assign({ 1, 2, 0 });

#pragma endregion

#pragma region Execution

	cout << FirstMissingPositive(arr) << "\n";

#pragma endregion	

#pragma region Preparation

	arr.assign({ 3, 4, -1, 1 });

#pragma endregion

#pragma region Execution

	cout << FirstMissingPositive(arr) << "\n";

#pragma endregion	

#pragma region Preparation

	arr.assign({ 7, 8, 9, 20, 11, 13 });

#pragma endregion

#pragma region Execution

	cout << FirstMissingPositive(arr) << "\n";

#pragma endregion	

#pragma region Preparation

	arr.assign({ 2, 3, 5, 6, 0, 1 });

#pragma endregion

#pragma region Execution

	cout << FirstMissingPositive(arr) << "\n";

#pragma endregion

#pragma region Preparation

	arr.assign({ 2, 3, 4, 1, 7, 10 });

#pragma endregion

#pragma region Execution

	cout << FirstMissingPositive(arr) << "\n";

#pragma endregion

#pragma region Preparation

	arr.assign({ 1, 2, 3, 4, 7, 8, 9, 20, 11, 13 });

#pragma endregion

#pragma region Execution

	cout << FirstMissingPositive(arr) << "\n";

#pragma endregion	
}