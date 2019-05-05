#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int T, N, M;

    cin >> T;

    while (T--)
    {
        cin >> N >> M;
        // matrix
        int MX[N][M];
        for (int i = 0;i < N;i++)
            for (int j = 0;j < M;j++)
                cin >> MX[i][j];


        for (int slice = 0; slice < (M + N) - 1; slice++) 
        {
            int z1 = slice < M ? 0 : slice - M + 1;
            int z2 = slice < N ? 0 : slice - N + 1;
            
            for (int j = z1;j <= (slice - z2);j++)
            {
                cout <<  MX[j][slice - j] << " ";
            }

        }

        cout << endl;
    }
    return 0;
}