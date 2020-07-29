#include <iostream>
using namespace std;

#include <string>

int LongestSubsequence(string firstString, string secondString)
{
	int firstStringLength = firstString.length();
	int secondStringLength = secondString.length();

	if (firstStringLength == 0 || secondStringLength == 0)	return 0;

	if (firstString[firstStringLength - 1] == secondString[secondStringLength - 1])
	{
		//cout << "\ncharacter Found: " << firstString[firstStringLength - 1] << "\n";
		return 1 + LongestSubsequence(firstString.substr(0, firstStringLength-1),secondString.substr(0, secondStringLength-1));
	}
	else
	{
		int possibility1 = LongestSubsequence(firstString, secondString.substr(0, secondStringLength - 1));
		int possibility2 = LongestSubsequence(firstString.substr(0, firstStringLength - 1), secondString);
		
		return (possibility1 > possibility2) ? possibility1 : possibility2;	
	}
}

void DP_LongestSubsequence_main()
{
#pragma region Preparation

	string firstString;
	cout << "\nEnter the first String:";
	cin >> firstString;

	string secondString;
	cout << "\nEnter the second String:";
	cin >> secondString;

#pragma endregion

#pragma region Execution

	cout << "Longest Subsequence = " << LongestSubsequence(firstString, secondString) << "\n";

#pragma endregion
}