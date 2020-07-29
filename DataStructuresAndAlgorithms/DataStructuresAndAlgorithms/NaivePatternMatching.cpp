#include <iostream>
using namespace std;

#include <string.h>

void patternMatch(char * mainString, char * pattern)
{
	int mainStringLength = strlen(mainString);
	int patternLength = strlen(pattern);


	for (int i = 0; i < mainStringLength; i++)
	{
		for (int j = 0; j < patternLength; j++)
		{
			if (i + j < mainStringLength)
			{
				if (mainString[i + j] != pattern[j])
				{
					break;//pattern mis match
				}
				else
				{
					//do nothing...see if next char also fits in the pattern
				}
			}
			else
			{
				break;//incomplete pattern found...main string ended
			}

			if (j + 1 == patternLength)
			{
				cout << "Pattern found at " << i << "\n";
			}
		}
	}
}

void NaivePatternMatching_main()
{
	int mainStringLength;	
	cout << "Enter the Main String length:";
	cin >> mainStringLength;
	
	char * mainString;
	mainString = (char*)malloc(mainStringLength + 1);
	cout << "Enter the Main String:";
	cin >> mainString;

	int patternLength;
	cout << "Enter the Pattern length:";
	cin >> patternLength;

	char * pattern;
	pattern = (char*)malloc(patternLength + 1);
	cout << "Enter the Pattern:";
	cin >> pattern;

	patternMatch(mainString, pattern);
}