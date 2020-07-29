#include <iostream>
using namespace std;

#include<vector>

#include "RecursionAndBacktracking.h"

vector<vector<int>> subsets;

void Subsets(vector<int> arr, int position)
{
	static vector<int> subset(arr.size(), NULL);	

	if (position == arr.size())
	{
		subsets.push_back(subset);
		return;
	}

	subset.at(position) = arr[position];	
	Subsets(arr, position + 1);
	
	subset.at(position) = NULL;
	Subsets(arr, position + 1);	
}

void AllSubsetsOfASet_main()
{
#pragma region Preparation

	vector<int> arr;
	arr.assign({ 1, 2, 3, 4 });			

#pragma endregion

#pragma region Execution

	Subsets(arr, 0);

	for (int i = 0; i < subsets.size(); i++)
	{
		for (int j = 0; j < 4; j++)
			cout << subsets.at(i).at(j) << "\t";
		cout << "\n";
	}

#pragma endregion
}