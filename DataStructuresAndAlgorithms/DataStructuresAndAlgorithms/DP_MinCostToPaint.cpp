#include <iostream>
using namespace std;

/*
					COST MATRIX
				Color0	Color1	Color2
		i=0		-		-		-	
		i=1		-		-		-
		...		
		i=n		-		-		-

	There are n blocks placed in a row. Each block must be colored with one of the 3 colors.
	No 2 adjacent blocks can be of the same color.
	Determine minimum cost to paint all the blocks.
*/

#pragma region Preparation

//int cost[][3] = { 1 ,2, 3,
//				  1, 2, 3,
//				  3, 3, 1 };

int cost[][3] = { 1 ,2, 3,
				  1, 25, 3,
				  3, 35, 1 };

#pragma endregion

int minCostToPaint(int n, int costAsOfNow, int colorToBeAvoided)
{
	if (n == 3)
		return costAsOfNow;

	int x, y;

	if (colorToBeAvoided == -1)
	{
		int option0 = minCostToPaint(1, cost[0][0], 0);
		int option1 = minCostToPaint(1, cost[0][1], 1);
		int option2 = minCostToPaint(1, cost[0][2], 2);

		return (option0 < option1) ? ((option0 < option2) ? option0 : option2) : ((option1 < option2) ? option1 : option2);
	}

	else if (colorToBeAvoided == 0)
	{		
		x = minCostToPaint(n + 1, costAsOfNow + cost[n][1], 1);
		y = minCostToPaint(n + 1, costAsOfNow + cost[n][2], 2);

		return (x < y) ? x : y;
	}
	
	else if (colorToBeAvoided == 1)
	{
		x = minCostToPaint(n + 1, costAsOfNow + cost[n][0], 0);
		y = minCostToPaint(n + 1, costAsOfNow + cost[n][2], 2);

		return (x < y) ? x : y;
	}

	else if (colorToBeAvoided == 2)
	{
		x = minCostToPaint(n + 1, costAsOfNow + cost[n][0], 0);
		y = minCostToPaint(n + 1, costAsOfNow + cost[n][1], 1);

		return (x < y) ? x : y;
	}		
}

void DP_MinCostToPaint_main()
{
#pragma region Execution

	int minCost = minCostToPaint(0, 0, -1);

	cout << "minimum cost to paint: " << minCost;

#pragma endregion	
}