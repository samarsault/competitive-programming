#include <cassert>
#include <iostream>

using namespace std;

// Add to large n-digit nos.
int* add(int *A, int *B, int n)
{
	int* sum = new int[n + 2];
	int carry = 0;
	// 3 + 4 = 7
	// 
	for (int i = n;i >= 1;i--)
	{
		sum[i] = (A[i - 1] + B[i - 1] + carry) % 10;
		if (A[i - 1] + B[i - 1] >= 10)
			carry = (A[i - 1] + B[i - 1]) / 10;
		else
			carry = 0;
	}

	if (carry > 0)
		sum[0] = carry;

	return sum;
}

// integer to digit array
int* number(int a)
{
	int b = a;
	int len = 0;
	while (a > 0)
	{
		a /= 10;
		len++;
	}
	int* digits = new int[len];
	int i = len - 1;
	while (b > 0)
	{
		digits[i] = b % 10;
		b /= 10;
		i--;
	}

	return digits;
}

int main(int argc, char const *argv[])
{
	int *A  = number(383);
	int *B  = number(678);
	int *C = 	add(A, B, 3);
	for (int i = 0;i < 4;i++)
		cout << C[i];

	return 0;
}