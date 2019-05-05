#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
	int n, i, j;
	cin >> n;
	int T[n][n], tmp[n][n];
	for(i = 0;i < n;i++)
		for(j=0;j<n;j++)
			T[i][j] = -1;

	for(i =0 ;i<n;i++)
		for (j=0;j<=i;j++)
			cin >> tmp[i][j];

	for (i = n - 1;i >= 0;i--)
		for (j = n - i - 1;j <= i;j++)
			T[i][j] = tmp[i][j];

	for (i=0;i<n;i++)

	{
		for(j=0;j<n;j++)
		{
			if (T[i][j] != -1)cout<< T[i][j];
			cout << ' ';
		}
		cout << endl;
	}
	return 0;
}
