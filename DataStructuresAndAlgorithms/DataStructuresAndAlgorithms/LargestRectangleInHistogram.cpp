#include <iostream>
using namespace std;

#include <vector>

int LargestRectangleInHistogram(vector<int> histogram)
{
	int largest = 0; int height;

	for (int i = 0; i < histogram.size(); i++)
	{
		largest = (largest > histogram[i]) ? largest : histogram[i];
		height = histogram[i];

		for (int j = i + 1; j < histogram.size(); j++)
		{
			height = (histogram[j] < height) ? histogram[j] : height;

			if ((height * (histogram.size() - i)) < largest)
				break;

			largest = (largest > (height * (j - i + 1))) ? largest : (height * (j - i + 1));
		}
	}

	return largest;
}

void LargestRectangleInHistogram_main()
{
#pragma region Preparation

	vector<int> histogram;
	histogram.assign({ 2,1,5,6,2,3 });

#pragma endregion

#pragma region Execution

	cout << "Largest Rectangle = "<<LargestRectangleInHistogram(histogram)<<"\n";

#pragma endregion

#pragma region Preparation

	histogram.assign({ 2,1,5,6,2,3,1,1,1,1,1 });

#pragma endregion

#pragma region Execution

	cout << "Largest Rectangle = " << LargestRectangleInHistogram(histogram) << "\n";

#pragma endregion

#pragma region Preparation

	histogram.assign({ 2,1,5,6,2,100,90,3,1,1,1,1,1 });

#pragma endregion

#pragma region Execution

	cout << "Largest Rectangle = " << LargestRectangleInHistogram(histogram) << "\n";

#pragma endregion
}