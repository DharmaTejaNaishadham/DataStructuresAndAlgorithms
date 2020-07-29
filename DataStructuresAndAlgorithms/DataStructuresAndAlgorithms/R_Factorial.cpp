#include <iostream>
using namespace std;

#include "RecursionAndBacktracking.h"

int factorial(int n)
{
	if (n > 0)
	{
		return n * factorial(n - 1);
	}
	else
	{
		return 1;
	}
}

void R_Factorial_main()
{	
	int number;
	char esc;

	do
	{
		cout << "\nEnter any number: ";
		cin >> number;

		cout << number << "! = " << factorial(number) << "\n";

		cout << "\n" << "Press y - continue  n - close:";
		cin >> esc;
		cout << "\n\n";

	} while (esc != 'n' && esc != 'N');		
}

