#include <iostream>
using namespace std;

#include "RecursionAndBacktracking.h"

char *Str;

void kstring(int n, int endChar)
{
	if (n < 1)
		cout << Str << "\n";
	else
	{
		for (int i = 97; i < endChar; i++)
		{
			Str[n - 1] = i;
			kstring(n - 1, endChar);
		}
	}
}


void AllStringsGivenLength_main()
{
#pragma region Preparation

	int n;
	cout << "enter the size of the string: ";
	cin >> n;


	int endChar;
	cout << "enter the end character: ";//something like 99,100,...
	cin >> endChar;

	Str = (char*)malloc(n + 1);
	Str[n] = '\0';

#pragma endregion

#pragma region Execution

	kstring(n, endChar);

#pragma endregion		
}