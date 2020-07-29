#include <iostream>
using namespace std;

#include <vector>

int MaxGap(vector<int> arr)
{
	int maxGap = -1;

	//create LMin vector
	vector<int> lMin;
	lMin.resize(arr.size());
	lMin[0] = arr[0];
	for (int i = 1; i < arr.size(); i++)
	{
		lMin[i] = (arr[i] < lMin[i - 1]) ? arr[i] : lMin[i - 1];
	}

	//create rMax vector
	vector<int> rMax;
	rMax.resize(arr.size());
	rMax[arr.size() - 1] = arr[arr.size() - 1];
	for (int i = arr.size() - 2; i >= 0; i--)
	{
		rMax[i] = (arr[i] > rMax[i + 1]) ? arr[i] : rMax[i + 1];
	}

	int i = arr.size() - 2, j = arr.size() - 1;

	while (i >= 0 && j > 0)
	{
		if (lMin[i] < rMax[j])
		{
			maxGap = ((j - i) > maxGap) ? (j - i) : maxGap;
			i--;
		}
		else
			j--;
	}

	return maxGap;
}

int MaxGapOwnIdea(vector<int> arr)
{
	int n = arr.size();
	int Maxj_i = 0;

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = n - 1; j - i > Maxj_i; j--)
		{
			if (arr[i] < arr[j])
			{
				Maxj_i = (Maxj_i > j - i) ? Maxj_i : j - i;
				break;
			}
		}
	}

	return Maxj_i;
}

void DP_Max_j_Minus_i_main()
{
	//input 1
#pragma region Preparation

	vector<int> arr;	
	arr.assign({34, 8, 10, 3, 2, 80, 30, 33, 1});	

#pragma endregion

#pragma region Execution

	cout << "Max j-i such that arr[j]>arr[i] is " << MaxGap(arr) << "\n";
	cout << "Max j-i such that arr[j]>arr[i] is " << MaxGapOwnIdea(arr) << "\n";

#pragma endregion
	
	//input 2
#pragma region Preparation

	arr.clear();
	arr.assign({9, 2, 3, 4, 5, 6, 7, 8, 18, 0});	

#pragma endregion

#pragma region Execution

	cout << "Max j-i such that arr[j]>arr[i] is " << MaxGap(arr) << "\n";
	cout << "Max j-i such that arr[j]>arr[i] is " << MaxGapOwnIdea(arr) << "\n";

#pragma endregion	
	
	//input 3
#pragma region Preparation

	arr.clear();
	arr.assign({1, 2, 3, 4, 5, 6});	

#pragma endregion

#pragma region Execution

	cout << "Max j-i such that arr[j]>arr[i] is " << MaxGap(arr) << "\n";
	cout << "Max j-i such that arr[j]>arr[i] is " << MaxGapOwnIdea(arr) << "\n";

#pragma endregion
	
	//input 4
#pragma region Preparation

	arr.clear();
	arr.assign({6, 5, 4, 3, 2, 1});

#pragma endregion

#pragma region Execution

	cout << "Max j-i such that arr[j]>arr[i] is " << MaxGap(arr) << "\n";
	cout << "Max j-i such that arr[j]>arr[i] is " << MaxGapOwnIdea(arr) << "\n";

#pragma endregion	
}