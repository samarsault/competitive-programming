#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int main(int argc, char const *argv[])
{
	int n, k, s;
	// make s tables with k screws each
	cin >> n >> k >> s;
	int A[n];
	for (int i = 0;i < n;i++)
		cin >> A[i];
	int screws = k * s;
	sort(A, A + n);
	int mins = 0, j = n - 1;
	while (j >= 0 && screws > 0)
	{
		screws -= A[j];
		mins++;
		j--;
	}
	cout << mins << endl;
	return 0;
}