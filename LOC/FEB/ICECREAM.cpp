#include <iostream>
#include <iomanip>
#include <cmath>

#define PI 3.14159265359

using namespace std;

int main(int argc, char const *argv[])
{
	int T;
	long double r1, r2, h1, h2;
	cin >> T;
	while (T--)
	{
		cin >> r1 >> h1 >> r2 >> h2;
		long double volCone = (1.0/3 * PI * r1 * r1 * h1) + (2.0/3 * PI * r1 * r1 * r1);
		long double volCyl = PI * r2 * r2 * h2;

		cout << setprecision(40) << volCone << " " << volCyl << endl;
	}
	return 0;
}