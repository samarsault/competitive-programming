#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//
// Problem : check whether there is a path from M to D
// 

int n, m;

bool flag = false;

void DFS(char **G, int i, int j)
{
	if (flag || G[i][j] == 'x' || G[i][j] == '#')
		return;

	if (G[i][j] == 'D')
	{
		flag = true;
		return;
	}

	if (G[i][j] != 'M')
		G[i][j] = 'x';

	if (j + 1 < m)
		DFS(G, i, j + 1);

	if (i + 1 < n)
		DFS(G, i + 1, j);

	if (j - 1 >= 0)
		DFS(G, i, j - 1);

	if (i - 1 >= 0)
		DFS(G, i - 1, j);

	// jump from leftmost to rightmost
	if (j == 0)
		DFS(G, i, m - 1);

	if (i == 0)
		DFS(G, n - 1, j);
}

int main(void)
{	
	cin >> n >> m;
	char **G;

	G = new char*[n];

	for (int i = 0;i < n;i++)
		G[i] = new char[m];

	int x, y;
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < m;j++)
		{
			cin >> G[i][j];

			if (G[i][j] == 'M')
			{
				x = i;
				y = j;
			}
		}
	}

	DFS(G, x, y);

	if (flag) 
	{
		cout << "YES" << endl;
		
		for (int i = 0;i < n;i++)
		{
			for (int j = 0;j < m;j++)
			{
				cout << G[i][j];
			}
			cout << endl;
		}
	}
	else 
		cout << "NO" << endl;
}
