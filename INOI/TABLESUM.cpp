#include <iostream>
#include <set>
#include <climits>

using namespace std;

int main(int argc, char *argv[])
{
	int n;
	cin >> n;
	int a[n], lmax=0,lI=-1;
	multiset<int> S;
	for (int i = 0;i < n;i++)
	{
		cin >> a[i];
		S.insert(a[i] + i + 1);
	}
	
	int curr = n - 1;
	for (int j = 0;j < n;j++)
	{
		cout << *S.rbegin() + j << ' ';
		int depreciated = a[curr] + curr + 1;
		S.erase(S.equal_range(depreciated).first);
		curr--;
		S.insert(depreciated - n);
	}

	cout << endl;
	
	return 0;
}
