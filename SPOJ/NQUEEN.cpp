#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

typedef pair<int,int> pii;

int placed[51], pos[51];

int n, plen = 0;

bool NQueens(int row = 0)
{
    if (row == n)
        return true; // finished
    else {
        for (int col = 0;col < n;col++)
        {
            // check safety
            bool isSafe = true;
            for (int q = 0;q < row;q++)
            {
                if (q == row || pos[q] == col ||
                    q + pos[q] == col + row || q - pos[q] == row - col)
                {
                    isSafe = false;
                    break;
                }
            }

            if (isSafe) {
                for (int i = 0;i < row;i++)
                {
                    if (placed[i] >= 0)
                    {
                        if (i == row || placed[i] == col || i + placed[i] == row + col || i - placed[i] == row - col) {
                            isSafe = false;
                            break;
                        }
                    }
                }
            }

            if (isSafe)
            {
                // place
                pos[row] = col;
                if (NQueens(row + 1))
                    return true;
            }
        }
    }
    return false;
}

int main (void)
{
    int x;
    cin >> n;
    for (int row = 0;row < n;row++) {
        cin >> x;
        if (x >= 0)
            placed[row] = x - 1;
        else 
            placed[row] = -1;
    }

    NQueens();
    char M[n][n];
    for (int i = 0;i < n;i++)
        for (int j =0 ;j < n;j++)
            M[i][j] = '.';

    for (int i = 0;i < n;i++) {
        M[i][pos[i]] = 'Q';
        M[i][placed[i]] = 'Q';
    }8 2 0 0 0 4 0 0 0
    
    for (int i = 0;i < n;i++) {
        for (int j =0 ;j < n;j++) {
            cout << M[i][j] << ' ';
        }
        cout << endl;
    }
}