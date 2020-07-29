#include <iostream>
using namespace std;

#include <vector>

void Filter0sToTheLast_main()
{
	int count = 0;
	cout << "enter the count of the no.s : ";
	cin >> count;

	vector<int> arr;

	for (int i = 0; i < count; i++)
	{
		int input;
		cin >> input;
		arr.push_back(input);
	}

	int Zs = -1, Ze = -1;

	/*
		arr[] = {0, 1, 4, 5, 0, 0, 7, 6, 0, 3, 4, 2, 1, 0, 8, 9}
				 0  1  2  3  4  5  6  7  8  9  10 11 12 13 14 15
		arr[] = {1, 4, 5, 7, 6, 3, 4, 2, 1, 8, 9, 0, 0, 0, 0, 0}
		i = 15
		Zs = 11
		Ze = 15;
	*/

	for (int i = 0; i < count; i++)
	{
		if (arr[i] != 0)
		{
			arr[Zs] = arr[i];
			arr[i] = 0;

			Zs++; Ze++;
		}
		else
		{
			if (Zs == -1)
			{
				Zs = i;
				Ze = i;
			}
			else
			{
				Ze++;
			}
		}
	}

	for (int i = 0; i < count; i++)
	{
		cout << arr[i] << " ";
	}
	cout << "\n";
}