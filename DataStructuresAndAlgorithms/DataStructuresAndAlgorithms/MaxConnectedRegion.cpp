#include <iostream>
using namespace std;

#include <vector>

int m, n;
vector<vector<int>> matrix;

vector<vector<int>> visited;
int currentRegionLength, maxRegionLength;

/*
		Given a Pixel/Element, it can be surrounded by a max of 8 Pixels/Elements

		1	2	3												(-1,1)		(0,1)		(1,1)
		4	X	5	== If we assume position of X is (0,0) ==>	(-1,0)		(0,0)		(1,0)
		6	7	8												(-1,-1)		(0,-1)		(1,-1)
*/
vector<int> rowStep{ -1,0,1,-1,1,-1,0,1 };
vector<int> colStep{ 1,1,1,0,0,0,-1,-1,-1 };

void ExpandRegionFrom(int row, int col)
{	
	visited[row][col] = 1;//marking current as visited
	
	for (int step = 0; step < 8; step++)//making the 8 max possible moves from that Element
	{	
		//ensuring we are in bounds of the matrix 0<= row < m && 0<= col < n 
		if ((row >= 0) && ((row + rowStep[step]) >= 0) && (row < m) && ((row + rowStep[step]) < m))
			if ((col >= 0) && ((col + colStep[step]) >= 0) && (col < n) && ((col + colStep[step]) < n))
			{
				//checking if the neighbour is an unvisited 1
				if (matrix[row + rowStep[step]][col + colStep[step]] == 1 && !visited[row + rowStep[step]][col + colStep[step]])
				{
					currentRegionLength++;
					ExpandRegionFrom(row + rowStep[step], col + colStep[step]);//recursively expand 1's reign like in minesweeper game
				}
			}
	}
}

void MaxConnectedRegion_main()
{	
	cin >> m >> n;	
	
	//making reqd. space for the input
	matrix.resize(m);
	visited.resize(m);

	for (int i = 0; i < m; ++i)
	{
		matrix[i].resize(n);
		visited[i].resize(n);
	}
	//--------------------------------
		
	//taking input & marking them as unvisited
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++) 
		{
			cin >> matrix[i][j];
			visited[i][j] = 0;
		}
	}
	//--------------------------------
	
	maxRegionLength = 0;
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{			
			if (matrix[i][j] == 1 && !visited[i][j])
			{		
				currentRegionLength = 1;//starting to expand a new region

				ExpandRegionFrom(i, j);
			
				maxRegionLength = (maxRegionLength > currentRegionLength) ? maxRegionLength : currentRegionLength;//updating maxRegionLength 
			}
		}
	}	

	cout << maxRegionLength << endl;
}