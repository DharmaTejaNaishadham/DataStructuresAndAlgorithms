#include <iostream>
using namespace std;

#include <vector>

vector<long int> arr;

long int MaxSumContiguous()
{
	long currentSum = 0;
	long maxSum = INT16_MIN;
	for (int i = 0; i < arr.size(); i++)
	{
		currentSum += arr[i];

		maxSum = (maxSum > currentSum) ? maxSum : currentSum;
		
		if (currentSum < 0)//we don't have to carry the negative sum, we can pretty much go for a fresh start
		{
			currentSum = 0;
		}
	}

	return maxSum;
}

long int MaxSumNonContiguous()
{
	/*
	if array has at least one postive no., then Max sum should be >= that no.
	else, max negative no. present in array such be the Max sum 
	*/
	if (arr.size() == 0)	return 0;

	int max = arr[0];
	for (int i = 1; i < arr.size(); i++)
	{
		if ((arr[i] + max) > max)
			max = arr[i] + max;

		if (arr[i] > max)
			max = arr[i];
	}	

	return max;
}

void MaxContiguousOrNonContiguousSum_main()
{
	int testCases;
	cin >> testCases;

	long int size;

	for (int tCase = 0; tCase < testCases; tCase++)
	{
		cin >> size;
		arr.resize(size);

		for (int i = 0; i < size; i++)
		{
			cin >> arr[i];
		}

		cout << MaxSumContiguous() << " " << MaxSumNonContiguous() << endl;
	}
}