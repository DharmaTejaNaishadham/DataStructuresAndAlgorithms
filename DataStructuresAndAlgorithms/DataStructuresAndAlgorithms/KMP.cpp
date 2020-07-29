#include <iostream>
using namespace std;

#include <string>

template <class T> void PrintPointers(T * P, int Length)
{
	for (int i = 0; i < Length; i++)
	{
		cout << *(P + i) << "\t";
	}
}

void ComputeLPS(char * pattern, int * LPS)
{
	int patternLength = strlen(pattern);
	int longestPrefix;

	char * prefix = new char[patternLength]();
	char * suffix = new char[patternLength]();
	string sSubString, sPrefix, sSuffix;

	*LPS = 0;//Always the first LPS is 0

	for (int i = 1; i < patternLength; i++)
	{
		longestPrefix = 0;

		sSubString = pattern;
		sSubString = sSubString.substr(0, i + 1);

		for (int j = 0; j < i; j++)
		{
			cout << "\nSubString: ";
			PrintPointers(pattern, i + 1);

			//prefix of length j+1
			sPrefix = sSubString;
			prefix = (char*)sPrefix.c_str();
			sPrefix = sPrefix.substr(0, j + 1);
			cout << "\nPreffix: ";
			PrintPointers(prefix, j + 1);

			//suffix of length j+1
			sSuffix = sSubString;
			suffix = (char*)sSuffix.c_str();
			sSuffix = sSuffix.substr(strlen(suffix) - j - 1);
			cout << "\nSuffix: ";
			PrintPointers(suffix, j + 1);

			cout << "\n-------------";

			if (strcmp(prefix, suffix) == 0)
			{
				longestPrefix = j + 1;
			}
		}
		*(LPS + i) = longestPrefix;
		cout << "\n==============================\n";
	}
}


void KMP(char * mainString, char * pattern)
{

#pragma region Compute LPS (Longest Proper Prefix which is also a Suffix)
	
	int patternLength = strlen(pattern);

	int *LPS;
	LPS = (int*)malloc(patternLength);

	ComputeLPS(pattern, LPS);

	cout << "\nLPS: ";
	PrintPointers(LPS, patternLength);
	cout << "\n";

#pragma endregion


#pragma region Use LPS to improve Naive Search

	int mainStringLength = strlen(mainString);

	int i = 0, j = 0;
	while (i + j < mainStringLength)
	{
		if (mainString[i + j] != pattern[j])//pattern mis match
		{
			i++;
			j = 0;			
		}
		else
		{
			if (j + 1 == patternLength)//pattern match
			{
				cout << "Pattern found at " << i << "\n";
				i = i + *(LPS + j) + 1;
				j = *(LPS + j);
			}

			j++;//do nothing...see if next char also fits in the pattern
						
		}

	}

#pragma endregion

}

void KMP_main()
{
	/*
	T: AAAAA - 5
	P: ABXAB - 5

	T: ABXABXAB - 8
	P: ABXAB - 5

	T: ABXABXACABXAB - 13
	P: ABXAB - 5

	T: ABABXABXAABXABXX - 16
	P: ABXAB - 5

	T: ABXABXACABXABXAABXAB - 20
	P: ABXAB - 5
	*/
	int mainStringLength;
	cout << "\nEnter the Main String length:";
	cin >> mainStringLength;

	char * mainString;
	mainString = (char*)malloc(mainStringLength + 1);
	cout << "\nEnter the Main String:";
	cin >> mainString;

	int patternLength;
	cout << "\nEnter the Pattern length:";
	cin >> patternLength;

	char * pattern;
	pattern = (char*)malloc(patternLength + 1);
	cout << "\nEnter the Pattern:";
	cin >> pattern;

	KMP(mainString, pattern);
}