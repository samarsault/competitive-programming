#include <fstream>
#include <cmath>
#include <climits>

using namespace std;

inline int dist(int x1, int y1, int x2, int y2)
{
	return abs(x1 - x2) + abs(y1 - y2);
}

int main(void)
{
	ifstream fin("marathon.in");
	ofstream fout("marathon.out");

	int n;
	fin >> n;

	int cX[n], cY[n];
	int tot = 0;
	
	for (int i = 0;i < n;i++)
	{
		fin >> cX[i] >> cY[i];
		if (i >= 1)
			tot += dist(cX[i - 1], cY[i - 1], cX[i], cY[i]);
	}

	int ans = INT_MAX;
	for (int i = 1;i < (n - 1);i++)
	{
		// on skipping i
		ans = min(ans, tot - dist(cX[i - 1], cY[i - 1], cX[i], cY[i]) - dist(cX[i], cY[i], cX[i + 1], cY[i + 1]) + dist(cX[i - 1], cY[i - 1], cX[i + 1], cY[i + 1]));
	}

	fout << ( ans ) << endl;
}
