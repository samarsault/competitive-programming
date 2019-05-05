/*
 * Sandbox for solving problem
 */
#include <iostream>
#define DSIZE 200
using namespace std;

class BigInt {
private:
    int A[DSIZE]; // DSIZE = 200 digits long. May use vector<int> instead.
    int size;
public:
    BigInt(int num);
    void multiply(int with);
    void print();
};

BigInt::BigInt(int n)
{
    size = 0;
    for (int i = 0;n > 0;i++)
    {
        A[i] = n % 10;
        n /= 10;
        size++;
    }
}

void BigInt::print()
{
    for (int i = size - 1;i >= 0;i--)
        cout << A[i];
}

void BigInt::multiply(int num)
{
    int temp = 0;
    for (int i = 0;i < size;i++)
    {
        int x = num * A[i] + temp;
        A[i] = x % 10;
        temp = x / 10;
    }

    for (int i = size;temp > 0;i++)
    {
        A[i] = temp % 10;
        temp /= 10;
        size++;
    }
}

int main(int argc, char const *argv[])
{
    // speed up I/O
    ios_base::sync_with_stdio(false);

    int T, N;
    cin >> T;

    while (T--)
    {
        cin >> N;
        BigInt num (N);
        for (int i = N - 1;i > 1;i--)
            num.multiply(i);
        num.print();
        cout << endl;
    }
    return 0;
}