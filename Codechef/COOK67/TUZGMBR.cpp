#include <iostream>
#include <cmath>

using namespace std;

bool perfsq(int n)
{
	int m = (int) sqrt(n);
	return (m*m) == n;
}

double dist(int X[], int Y[])
{
	return sqrt(pow(X[1] - X[0], 2) - pow(Y[1] - Y[0], 2));
}

int main(int argc, char const *argv[])
{
	int T;
	long N, M;
	cin >> T;
	while (T--)
	{
		cin >> N >> M;
		int X[] = { 1, N };
		int Y[] = { 2, M };
		double m = dist(X, Y);
		if (m == (int)m)
		{
			cout << "Vanya" << endl;
		}
		else
		{
			cout << "Tuzik" << endl;
		}
	}
	return 0;
}