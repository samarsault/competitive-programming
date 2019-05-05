#include <iostream>
#include <cmath>
using namespace std;

int main(void)
{
	int n,x,p1,p2,p3,sum=0;
	cin >> n >> x;
	for (int i =0;i < n;i++)
	{
		cin >> p1 >> p2;
		if (abs(p1-p2) > x)
		{
			cin >> p3;
			sum += p3;
		}
		else
			sum += max(p1,p2);
	}
	cout << sum << endl;
	return 0;
}
