#include <iostream>
using namespace std;

#include <vector>

int min(int a, int b)
{
	return (a < b) ? a : b;
}

int MinimumJumps(vector<int> possibleJumps)
{
	int length = possibleJumps.size();

	if (length == 0)
	{
		return 0;
	}

	if (possibleJumps[0] == 0)
	{
		return -1;
	}

	int *minJumps;
	minJumps = (int *)malloc(length);

	minJumps[0] = 0;
	for (int i = 1; i < length; i++)
	{
		minJumps[i] = INT16_MAX;
	}

	for (int i = 1; i < length; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (i <= possibleJumps[j] && minJumps[j] != INT16_MAX)
			{
				minJumps[i] = min(minJumps[i], minJumps[j] + 1);
				break;
			}
		}
	}

	if (minJumps[length - 1] == INT16_MAX)
	{
		return -1;
	}
	else
	{
		return (minJumps[length - 1]);
	}

}

void MinJumpsToReachEnd_main()
{
#pragma region Preparation

	vector<int> possibleJumps;
	possibleJumps.assign({ 7, 3, 5, 1, 1, 0, 1, 0, 1 });

#pragma endregion

#pragma region Execution

	cout << MinimumJumps(possibleJumps) << "\n";

#pragma endregion	
}