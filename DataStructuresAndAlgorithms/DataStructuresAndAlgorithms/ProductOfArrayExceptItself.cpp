#include <iostream>
using namespace std;

#include <vector>

void PrintVector(vector<int> arr)
{
	for (int i = 0; i < arr.size(); i++)
		cout << arr[i] << "\t";

	cout << "\n";
}

vector<int> ProductOfArrayExceptItself(vector<int> arr)
{
	int productOfAllExcept0 = 1;	

	int zerosCount = 0;

	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i] != 0)
			productOfAllExcept0 *= arr[i];			
		else
			zerosCount++;
	}

	vector<int> productArr;

	for (int i = 0; i < arr.size(); i++)
	{	
		if (zerosCount == 0)		
			productArr.push_back(productOfAllExcept0 / arr[i]);

		else if (zerosCount == 1)
		{
			if(arr[i]==0)
				productArr.push_back(productOfAllExcept0);
			else
				productArr.push_back(0);
		}

		else if (zerosCount > 1)
			productArr.push_back(0);
	}

	return productArr;
}


void ProductOfArrayExceptItself_main()
{
#pragma region Preparation

	vector<int> arr;
	arr.assign({ 1, 2, 3, 4, 5 });

#pragma endregion

#pragma region Execution
	
	vector<int> productArr;
	productArr = ProductOfArrayExceptItself(arr);
	PrintVector(productArr);

#pragma endregion	

#pragma region Preparation

	arr.assign({ 1, -2, 3, -4, 5 });

#pragma endregion

#pragma region Execution

	productArr = ProductOfArrayExceptItself(arr);
	PrintVector(productArr);

#pragma endregion	

#pragma region Preparation

	arr.assign({ 1, 0, 3, 4, 5 });

#pragma endregion

#pragma region Execution

	productArr = ProductOfArrayExceptItself(arr);
	PrintVector(productArr);

#pragma endregion

#pragma region Preparation

	arr.assign({ 1, 0, -3, 4, 0 });

#pragma endregion

#pragma region Execution

	productArr = ProductOfArrayExceptItself(arr);
	PrintVector(productArr);

#pragma endregion
}