#include <iostream>
using namespace std;

#include <string>

string kangaroo(int x1, int v1, int x2, int v2)
{
	if (v1 > v2)
	{		
		if (((x1*v2) - (x2*v1)) % (v2 - v1) == 0)
		{
			int y = ((x1*v2) - (x2*v1)) / (v2 - v1);
			int jumps = (y-x1) % (v1);

			if (jumps == 0)
			{
				return "YES";
			}
			else
			{
				return "NO";
			}			
		}
		else
		{
			return "NO";
		}
	}
	else
	{
		return "NO";
	}
}

void KangarooOnXAxis_main()
{
	int x1;
	int v1;
	int x2;
	int v2;

	cout << "enter x1, v1, x2 & v2\n";
	cin >> x1 >> v1 >> x2 >> v2;
	string result = kangaroo(x1, v1, x2, v2);

	cout << result << endl;
}