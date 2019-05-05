#include <iostream>
#include <algorithm>
 
using namespace std;
 
typedef long long LL;
int n;
LL w, l;
pair<int, int> * T;
 
bool F(int x) // monotonic function
{
	LL sum = 0;
	for (int i = 0;i < n;i++)
		if (T[i].first + T[i].second * x >= l)
			sum += (T[i].first + T[i].second * x);
 
	return sum >= w;
}
 
int main(void)
{
	cin >> n >> w >> l;
	T = new pair<int, int>[n];
	for (int i = 0;i < n;i++)
		cin >> T[i].first >> T[i].second;
 
	// binary search
	LL low = -1, high=1, mid; 

	while (!F(high))
		high*=2;
 
	while (high - low > 1)
	{
		mid = (low + high)>>1;
		if (F(mid)) // it is possible to grow
			high = mid;
		else
			low = mid;
	}
	cout << high << endl;
 
	// free memory
	delete [] T;
}
