#include <iostream>
using namespace std;

#include "RecursionAndBacktracking.h"

char *A;

void Binary(int n)
{
	if (n < 1)
		cout << A << "\n";
	else
	{
		A[n - 1] = '0';
		Binary(n - 1);
		A[n - 1] = '1';
		Binary(n - 1);
	}
}


void BackTrack_AllStrings_main()
{
#pragma region Preparation

	int n;
	cout << "enter the size of the string: ";
	cin >> n;

	A = (char*)malloc(n + 1);
	A[n] = '\0';

#pragma endregion

#pragma region Execution

	Binary(n);

#pragma endregion	
}