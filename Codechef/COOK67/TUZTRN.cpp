#include <iostream>
#include <cmath>

using namespace std;

double polygonArea (int X[], int Y[], int numPoints) 
{ 
	int area = 0;         // Accumulates area in the loop
	int j = numPoints-1;  // The last vertex is the 'previous' one to the first

	for (int i=0; i<numPoints; i++)
	{ 
		area = area +  (X[j]+X[i]) * (Y[j]-Y[i]); 
	  	j = i;  //j is previous vertex to i
	}
	return area/2;
}

double distance(int X[], int Y[])
{
	return sqrt(pow(X[1] - X[0], 2) - pow(Y[1] - Y[0], 2));
}

pair<int, int> section(int m1, int m2, int X[], int Y[])
{
	pair<int, int> pt;
	pt.first = (m1 * X[1] + m2 * X[0])/(m1 + m2);
	pt.second = (m1 * Y[1] + m2 * Y[0])/(m1 + m2);
	return pt;
}

int main(int argc, char const *argv[])
{
	int T;
	cin >> T;

	while (T--)
	{
		int k = 3, j = 3, q = 4;

		// Coordinates
		// 1st Triangle
		int trX[3], trY[3];
		// 2nd Triangle
		int tr2X[3], tr2Y[3];
		// Quadrilateral
		int quadX[4], quadY[4];

		int i = 0;
		while (k--)
		{
			cin >> trX[i] >> trY[i];
			i++;
		}

		i = 0;

		while (j--)
		{
			cin >> tr2X[i] >> tr2Y[i];
			i++;
		}

		i = 0;

		while (q--)
		{
			cin >> quadX[i] >> quadY[i];
			i++;
		}

		// Solve
	}
	return 0;
}