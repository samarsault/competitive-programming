#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[])
{
	int a, b, c;
	cin >> a >> b >> c;
	// ax^2 + bx + c = 0
	// -b +/- _/ b^2 - 4ac /2
	long double dscrm = sqrt( (b * b) - (4 * a * c) );
	long double r1 = ((-b) + dscrm) / (2 * a);
	long double r2 = ((-b) - dscrm) / (2 * a);
	cout << setprecision(15);
	if (r1 > r2)
	{
		cout << r1 << endl << r2 << endl;
	}
	else
	{
		cout << r2 << endl << r1 << endl;
	}
	return 0;
}