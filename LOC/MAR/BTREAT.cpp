#include <iostream>

using namespace std;

typedef long long LL;

int main(int argc, char const *argv[])
{
    int T, N;

    LL avg, total, ans;
    cin >> T;

    while(T--)
    {
        total = 0;

        cin >> N;
        int A[N];

        if (N < 0)
            break;

        for (int i = 0;i < N;i++)
        {
            cin >> A[i];
            total += A[i];
        }

        ans = 0;
        avg = (total / N);

        if (total % N == 0)
        {
            for (int i = 0;i < N;i++)
            {
                if (avg > A[i])
                    ans += (avg - A[i]);
            }

        } else {
            cout << "No Treat" << endl;
            continue;
        }

        cout << ans << endl;

    }
    return 0;
}