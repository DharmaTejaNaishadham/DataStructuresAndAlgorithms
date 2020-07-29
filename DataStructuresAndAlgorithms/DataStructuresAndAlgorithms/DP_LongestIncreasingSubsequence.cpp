#include <iostream>
using namespace std;

#include <vector>

int LongestIncreasingSubsequence(vector<int> num, int n, int min)
{
	if (n == num.size() - 1)
	{
		if (num[n] > min)
			return 1;
		else
			return 0;
	}

	if (num[n] > min)
	{
		//case where LIS is attained by not having num[n] in the collection
		int possibility1 = LongestIncreasingSubsequence(num, n + 1, min);

		//case where LIS is attained by having num[n] in the collection
		int possibility2 = 1 + LongestIncreasingSubsequence(num, n + 1, num[n]);

		return (possibility1 > possibility2) ? possibility1 : possibility2;
	}
	else
		return LongestIncreasingSubsequence(num, n + 1, min);
}

void DP_LongestIncreasingSubsequence_main()
{
#pragma region Preparation

	vector<int> num;
	num.assign({ 0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15 });

#pragma endregion

#pragma region Execution

	cout << "Longest Increasing Subsequence = " << LongestIncreasingSubsequence(num, 0, INT16_MIN) << "\n";

#pragma endregion	
}