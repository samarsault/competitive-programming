#include <iostream>

using namespace std;


int main(int argc, char const *argv[])
{
	int T, N, K;
	cin >> T;
	char c = 'X';
	char inverse  = 'O';
	while (T--)
	{
		bool win = false;
		cin >> N >> K;
		
		char board[N+1][N+1];

		for (int i = 0;i < N;i++)
		{
			cin >> board[i];
		}

		int scount = 0, hcount = 0, dcountl = 0, dcountr = 0;
		// straight
		for (int i = 0;i < N;i++)
		{
			// board[0][0], board[1][0], board[2][0]X
			// board[0][0], board[0][1]
			// board[0][0], board[1][1]
			scount = 0;
			hcount = 0;
			for (int k = 0;k < N;k++)
			{
				if (board[k][i] == c && board[k + 1][i + 1] != inverse)
					scount++;
				if (board[i][k] == c && board[i + 1][k + 1] != inverse)
					hcount++;
			}
		}

		for (int i = 0;i < N;i++)
		{
			if (board[i][i] == c && board[i + 1][i + 1] != inverse)
				dcountl++;

			if (board[i][N - i - 1] == c && board[i + 1][N - i - 2] != inverse)
				dcountr++;
		}

		int j = K - 1;

		if (scount == j || dcountl == j || dcountr == j || hcount == j)
			win = true;

		if (win)
			cout << "YES" <<endl;
		else
			cout << "NO" << endl;

	}
	return 0;
}