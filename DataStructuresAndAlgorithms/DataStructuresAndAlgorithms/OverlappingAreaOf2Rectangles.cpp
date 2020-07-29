#include <iostream>
using namespace std;

int OverlappingAreaOf2Rectangles(int x1, int y1, int w1, int l1, int x2, int y2, int w2, int l2)
{
	int r1Width = x1 + w1;
	int r1Length = y1 + l1;

	int r2Width = x2 + w2;
	int r2Length = y2 + l2;

	int intersectionW = 0;
	if (x2 >= x1 && x2 <= r1Width)
		intersectionW = (r2Width < r1Width) ? r2Width - x2 : r1Width - x2;
	else if (x1 >= x2 && x1 <= r2Width)
		intersectionW = (r2Width < r1Width) ? r2Width - x1 : r1Width - x1;
	
	int intersectionL = 0;
	if (y2 >= y1 && y2 <= r1Length)		
		intersectionL = (r2Length < r1Length) ? r2Length - y2 : r1Length - y2;
	else if (y1 >= y2 && y1 <= r2Length)		
		intersectionL = (r2Length < r1Length) ? r2Length - y1 : r1Length - y1;

	return intersectionW * intersectionL;
}

void OverlappingAreaOf2Rectangles_main()
{
#pragma region Preparation
	
	int x1, y1, l1, w1;
	cin >> x1 >> y1 >> w1 >> l1;

	int x2, y2, l2, w2;
	cin >> x2 >> y2 >> w2 >> l2;

#pragma endregion

#pragma region Execution

	cout << OverlappingAreaOf2Rectangles(x1,y1,w1,l1,x2,y2,w2,l2);

#pragma endregion	
}