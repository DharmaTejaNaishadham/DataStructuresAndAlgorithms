#include <iostream>
using namespace std;

int MaxProductOf3Integers(int* arr, int num)
{	
	int temp = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = i+1; j < num; j++)
		{
			if (arr[i] < arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	int result1 = arr[0] * arr[1] * arr[2];//arr[0], arr[1] & arr[2] would hold 3 biggest no.s

	int result2 = arr[0];
	for (int i = 0; i < 2; i++)
	{
		for (int j = i + 1; j < num; j++)
		{
			if (arr[i] > arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	result2 = result2 * arr[0] * arr[1]; //arr[0], arr[1] would hold 2 smallest -ve no.s (if any)

	return (result1 > result2) ? result1 : result2;
}

void MaxProductOf3Integers_main()
{
#pragma region Preparation

	int num;
	cin >> num;

	int* arr;
	arr = (int*)malloc(num * sizeof(int));

	for (int i = 0; i < num; i++)
		cin >> arr[i];

#pragma endregion

#pragma region Execution

	if (num < 3)
	{
		cout << "Two few numbers";
		return;
	}

	cout << MaxProductOf3Integers(arr, num);
	return;
	
#pragma endregion	
}