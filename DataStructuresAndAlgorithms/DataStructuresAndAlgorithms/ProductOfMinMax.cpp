#include <iostream>
using namespace std;

#include <vector>

void PrintVector(vector<long> arr)
{
	for (int i = 0; i < arr.size(); i++)
		cout << arr[i] << "\t";

	cout << "\n";
}

vector<long> ProductOfMinMax(vector<string> operations,vector<int> x)
{
	vector<long> results;	

	vector<int> nums;
	vector<int>::iterator ptr;

	for (int i = 0; i < operations.size(); i++)
	{
		if (operations[i] == "push")
		{
			if (i == 0)
			{
				nums.push_back(x[0]);	
				ptr = nums.begin();

				results.push_back(*nums.begin() * *(nums.end() - 1));
			}
			else
			{
				for (int j = 0; j < nums.size(); j++)
				{
					if (x[i] < nums[j])
					{
						nums.insert(ptr + j, x[i]);
						break;
					}

					if (j == nums.size() - 1)
					{
						nums.push_back(x[i]);
						break;
					}
				}

				results.push_back(*nums.begin() * *(nums.end() - 1));
			}
		}
		else if (operations[i] == "pop")
		{
			remove(nums.begin(), nums.end(), x[i]);
			nums.pop_back();
			ptr = nums.begin();

			results.push_back(*nums.begin() * *(nums.end() - 1));
		}
	}
	
	return results;
}


void ProductOfMinMax_main()
{
#pragma region Preparation

	vector<string> operations;
	operations.assign({"push","push","push","pop", "push", "push", "pop", "pop", "push", "push"});
		
	vector<int> x;
	x.assign({ 1, 2, 3, 1, 1, 4, 1, 2, 5, 0 });

#pragma endregion

#pragma region Execution

	PrintVector(ProductOfMinMax(operations, x));

#pragma endregion
}