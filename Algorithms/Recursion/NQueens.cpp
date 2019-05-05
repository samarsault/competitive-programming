#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> pii; // row,col

bool NQueens(int n, int row, pii pos[])// row = level
{
	if (row == n) {
		return true;
	} else {
		for (int col = 0;col < n;col++)
		{
			bool colSafe = true; // whether column is safe
			for (int i = 0;i < row;i++)
			{
				if (row == pos[i].first || col == pos[i].second ||
					row + col == pos[i].first + pos[i].second || row - col == pos[i].first - pos[i].second ) {
						colSafe = false;
						break;
					}
				}
				
				if (colSafe) {
					// place queen
					pos[row] = make_pair(row, col);
					if (NQueens(n, row + 1, pos))
					return true;
				}
			}
		}
		return false;
	}
	
	int main(void)
	{
		int n;
		cin >> n;
		pii *  pos = new pii[n];
		bool hasSoln = NQueens(n, 0, pos);
		if (hasSoln) {
			char M[n][n];
			for (int i = 0;i < n;i++)
				for (int j =0 ;j < n;j++)
					M[i][j] = '.';

			for (int i = 0;i < n;i++)
				M[pos[i].first][pos[i].second] = 'Q';
			
			
			for (int i = 0;i < n;i++) {
				for (int j =0 ;j < n;j++) {
					cout << M[i][j] << ' ';
				}
				cout << endl;
			}
		} else {
			cout << "No solution" << endl;
		}
	}