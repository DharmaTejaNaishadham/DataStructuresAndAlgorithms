#include <iostream>
using namespace std;

#include <vector>

void printMatrix(vector<vector<int>> matrix)
{
	for (int i = 0; i < matrix.size(); i++)
	{
		for (int j = 0; j < matrix[i].size(); j++)
			cout << matrix[i][j] << "\t";
		cout << "\n";
	}
}

void RotateMatrix(vector<vector<int>> matrix)
{
	cout << "Before:\n";
	printMatrix(matrix);

	int l = matrix.size();

	int iLimit = (l % 2 == 0) ? l / 2 : (l / 2) + 1;

	for (int i = 0; i < iLimit; i++)
		for (int j = 0; j < l / 2; j++)
		{
			int temp = matrix[i][j];

			matrix[i][j] = matrix[l - j - 1][i];
			matrix[l - j - 1][i] = matrix[l - i - 1][l - j - 1];
			matrix[l - i - 1][l - j - 1] = matrix[j][l - i - 1];
			matrix[j][l - i - 1] = temp;
		}

	cout << "After:\n";
	printMatrix(matrix);
}

void RotateMatrix_main()
{
#pragma region Preparation

	vector<vector<int>> matrix;

	matrix.resize(3);
	matrix[0].resize(3);
	matrix[1].resize(3);
	matrix[2].resize(3);

	matrix[0].assign({ 1,2,3 });
	matrix[1].assign({ 4,5,6 });
	matrix[2].assign({ 7,8,9 });

#pragma endregion

#pragma region Execution

	RotateMatrix(matrix);

#pragma endregion	

#pragma region Preparation

	matrix.resize(4);
	matrix[0].resize(4);
	matrix[1].resize(4);
	matrix[2].resize(4);
	matrix[3].resize(4);

	matrix[0].assign({ 1,2,3,4 });
	matrix[1].assign({ 5,6,7,8 });
	matrix[2].assign({ 9,10,11,12 });
	matrix[3].assign({ 13,14,15,16 });

#pragma endregion

#pragma region Execution

	RotateMatrix(matrix);

#pragma endregion	
#pragma region Preparation

	matrix.resize(5);
	matrix[0].resize(5);
	matrix[1].resize(5);
	matrix[2].resize(5);
	matrix[3].resize(5);
	matrix[4].resize(5);
	
	matrix[0].assign({ 1,2,3,4,5 });
	matrix[1].assign({ 6,7,8,9,10 });
	matrix[2].assign({ 11,12,13,14,15 });
	matrix[3].assign({ 16,17,18,19,20 });
	matrix[4].assign({ 21,22,23,24,25 });

#pragma endregion

#pragma region Execution

	RotateMatrix(matrix);

#pragma endregion	
}