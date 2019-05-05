#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;
typedef long long LL;

int main(int argc, char const *argv[])
{
	int n;
	LL t;
	double ans;
	const double ps = 1.000000011;
	cin >> n >> t;
	ans = pow(ps, t);
	ans *= n;
	cout << setprecision(30) << ans << endl;
	return 0;
}