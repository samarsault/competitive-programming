#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int maxsubarr(int A[], int n)
{
    if (n == 1) // base case
        return A[0];

    int m = n / 2;
    int left_MSS = maxsubarr(A, m);
    int right_MSS = maxsubarr(A + m, n - m);
    // max crossing subarray
    int sum = 0;
    int left_sum, right_sum;
    left_sum = right_sum = INT_MIN;
    
    for (int i = m; i < n; i++) 
    {
        sum += A[i];        
        right_sum = max(right_sum, sum);
    }

    sum = 0;

    for (int i = m - 1; i >= 0 ; i--){
        sum += A[i];
        left_sum = max(left_sum, sum);        
    }
    int ans = max(left_MSS, right_MSS);
    return max(ans, left_sum + right_sum);
}

int subdp(int A[], int n)
{
    int max_so_far = INT_MIN, sum = 0;
    for (int j = 0;j < n;j++)
    {
        sum += A[j];
        max_so_far = max(max_so_far, sum);
    } 
    return max_so_far;
}

int main(int argc, const char *argv[])
{
    int A[] = { 13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7 };
    int n = sizeof(A) / sizeof(A[0]);
    cout << maxsubarr(A, n) << endl;    
    cout << subdp(A, n) << endl;
    return 0;
}
