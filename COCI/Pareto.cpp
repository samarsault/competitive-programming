#include <iostream>
#include <cmath>
#include <unordered_map>
using namespace std;

int main(void)
{
	int n;
	cin >> n;
	int a[n];
	long long total = 0;
	for (int i = 0;i < n;i++)
	{
		cin >> a[i];
		total += a[i];
	}
	sort(a,a+n);
	double A = 0, B = 0;
	int mid = n/2; 
	if (!(n%2))mid--;
	for (int l = 0, r = n - 1;l < mid && r >mid;l++,r--)
	{
		if (a[r] - a[l] >= a[mid])
		{
			A++;
			B += a[r];
		}
		else
			break;
	}
	A = 1.0*A/n * 100;
	B = 1.0*B/total * 100;
	cout << A << endl << B << endl;
	return 0;
}

