#include <iostream>
using namespace std;

#include <string>

bool MatchesPattern(string input, string pattern)
{
	int inputSize = input.size(), patternSize = pattern.size();
	int inputIndex = 0, patternIndex = 0;
	char charInputIndex = ' ', charPatternIndex = ' ', charPatternNextIndex = ' ';

	while (1)
	{		
		if (inputIndex < inputSize)
			charInputIndex = input.at(inputIndex);
		else
			charInputIndex = ' ';

		if (patternIndex < patternSize)
			charPatternIndex = pattern.at(patternIndex);
		else
			charPatternIndex = ' ';

		if ((patternIndex + 1) < patternSize)
			charPatternNextIndex = pattern.at(patternIndex + 1);
		else
			charPatternNextIndex = ' ';

		if (charInputIndex == ' ' && charPatternIndex == ' ')
			break;

		if (charPatternNextIndex == '*')
		{
			if (charInputIndex == charPatternIndex)
			{
				inputIndex++;
			}
			else
			{
				patternIndex+=2;
			}
		}

		else if (charPatternIndex == '?')
		{
			inputIndex++;
			patternIndex++;
		}

		else
		{
			if (charInputIndex == charPatternIndex)
			{
				inputIndex++;
				patternIndex++;
			}
			else
				return false;
		}
	}

	return true;
}

void RegularExpression_main()
{
/*
'?' Matches any single character from a-z
'*' Matches any no. of occurrences of preceding character (a-z) (including no occurrence).
*/
#pragma region Preparation

	string input = "aab";
	string pattern = "c*a*b";

#pragma endregion

#pragma region Execution

	cout << input << " matches " << pattern << " : " << MatchesPattern(input, pattern) << "\n";

#pragma endregion	

#pragma region Preparation

	input = "caaabab";
	pattern = "c*a*b?b";

#pragma endregion

#pragma region Execution

	cout << input << " matches " << pattern << " : " << MatchesPattern(input, pattern) << "\n";

#pragma endregion

#pragma region Preparation

	input = "aa";
	pattern = "a";

#pragma endregion

#pragma region Execution

	cout << input << " matches " << pattern << " : " << MatchesPattern(input, pattern) << "\n";

#pragma endregion

#pragma region Preparation

	input = "aa";
	pattern = "a*";

#pragma endregion

#pragma region Execution

	cout << input << " matches " << pattern << " : " << MatchesPattern(input, pattern) << "\n";

#pragma endregion

#pragma region Preparation

	input = "mississippi";
	pattern = "mis*is*p*?";

#pragma endregion

#pragma region Execution

	cout << input << " matches " << pattern << " : " << MatchesPattern(input, pattern) << "\n";

#pragma endregion

#pragma region Preparation

	input = "mississippi";
	pattern = "mis*is*ip*?";

#pragma endregion

#pragma region Execution

	cout << input << " matches " << pattern << " : " << MatchesPattern(input, pattern) << "\n";

#pragma endregion
}