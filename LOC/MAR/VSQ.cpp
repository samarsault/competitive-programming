#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int main(int argc, char const *argv[])
{
    int N, Q, a, b;
    cin >> N;
    long A[N];
    for (int i = 0;i < N;i++)
        cin >> A[i];
    sort(A, A + N);
    cin >> Q;
    while (Q--)
    {
        cin >> a >> b;
        cout << distance(lower_bound(A, A + N, a), upper_bound(A, A + N, b)) << endl;
    }
    return 0;
}

