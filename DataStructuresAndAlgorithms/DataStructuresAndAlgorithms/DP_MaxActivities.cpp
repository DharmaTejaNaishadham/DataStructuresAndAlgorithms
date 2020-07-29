#include <iostream>
using namespace std;

#include <vector>

int MaxActivities(vector<int> aStart, vector<int> aEnd, int i, int busyTill)
{
	if (i == aStart.size() - 1)
	{
		if (aStart[i] >= busyTill)
			return 1;
		else
			return 0;
	}

	if (aStart[i] >= busyTill)
	{
		int p1 = 1 + MaxActivities(aStart, aEnd, i + 1, aEnd[i]);

		int p2 = MaxActivities(aStart, aEnd, i + 1, busyTill);

		return (p1 > p2) ? p1 : p2;
	}
	else
	{	
		return MaxActivities(aStart, aEnd, i + 1, busyTill);
	}
}

void DP_MaxActivities_main()
{
#pragma region Preparation

	vector<int> aStart, aEnd;
	aStart.assign({ 10, 12, 15, 26, 31, 41, 42, 44, 47, 1 });
	aEnd.assign({ 40, 27, 24, 30, 40, 43, 45, 46, 48, 52 });

#pragma endregion

#pragma region Execution

	cout << "max possible activities = " << MaxActivities(aStart, aEnd, 0, 0) << "\n";

#pragma endregion
}