#include <iostream>
using namespace std;

int Knapsack_0Or1(int maxWeight, int val[], int weights[], int n)
{
	if (n == 0 || maxWeight == 0)	return 0;

	if (weights[n - 1] <= maxWeight)
	{
		//case where max weight is attained with this item in the selection
		int possibility1 = val[n - 1] + Knapsack_0Or1(maxWeight - weights[n - 1], val, weights, n - 1);

		//case where max weight is attained with not having this item in the selection
		int possibility2 = Knapsack_0Or1(maxWeight, val, weights, n - 1);

		return (possibility1 > possibility2) ? possibility1 : possibility2;
	}
	else
	{
		return Knapsack_0Or1(maxWeight, val, weights, n - 1);
	}
}

void DP_Knapsack_0Or1_main()
{
#pragma region Preparation

	int maxWeight = 50;
	int val[] = { 60, 100, 120 };
	int weights[] = { 10, 20, 30 };
	int n = 3;

#pragma endregion

#pragma region Execution

	cout << "Max value possible = " << Knapsack_0Or1(maxWeight, val, weights, n) << "\n";

#pragma endregion
}