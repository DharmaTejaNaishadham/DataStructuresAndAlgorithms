#include <iostream>
using namespace std;

#include "RecursionAndBacktracking.h"

int min;
int max;

void Print(int max)
{
	if (max > min)
	{
		cout << max << "\n";
		Print(max - 1);
	}
	else
	{
		cout << max << "\n";
	}
}

void PrintNumbersBackwards_main()
{
	char esc;

	do
	{
		cout << "Enter min number: ";
		cin >> min;

		cout << "Enter max number: ";
		cin >> max;

		cout << "Numbers printed backwards \n";
		Print(max);

		cout << "\n" << "Press y - continue  n - close:";
		cin >> esc;
		cout << "\n\n";

	} while (esc != 'n' && esc != 'N');	
}

