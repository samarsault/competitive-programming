//
// Trick: x % (x + 1) = x
// So, find the second largest no.
// If all nos. are same then, loop until you find a distinct number.
// Else, ans = 0
//
#include <iostream>
#include <algorithm>
 
using namespace std;

int main(int argc, char const *argv[])
{
	long N;
	cin >> N;

	long A[N];

	for (int i = 0;i < N;i++)
		cin >> A[i];
 
	sort(A, A + N);

	int j = N - 1;

	while (j > 0 && A[j] == A[j - 1])
		j--;

	if (j == 0)
		cout << 0 << endl;
	else
		cout << A[j - 1] << endl;

	return 0;
} 