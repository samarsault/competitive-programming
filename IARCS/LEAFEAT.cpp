#include <iostream>
#include <cstring>

using namespace std;

typedef long long LL;

int gcd(int a,int b)
{
	int r;
	while(b) {
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int lcm(int a, int b)
{
	return (a * b) / gcd(a, b);
}

int main(void)
{
	int n, k;
	cin >> n >> k;

	int a[k];

	for (int i = 0;i < k;i++)
		cin >> a[i];

	bool visit[n];

	memset(visit, false, sizeof(visit));	
	LL ans = n;	

	for (int i = 0;i < k;i++)
	{

	}

	cout << ans << endl;
}
