/*
 * Evaluating Polynomials
 * Horner's Rule
 */
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	// coefficients
	int C[] = { };
	int N = sizeof(C) / sizeof(C[0]);
	// p(x)
	int x = 3;
	// y = p(x)
	int y = 0;
	for (int i = 0;i < N;i++)
		y = C[i] + x * y;
	return 0;
}