#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	long long ans = 0;
	for (int i = 1;i <= n;i++)
		ans += pow(2, i);
	
	cout << ans << endl;
	return 0;
}