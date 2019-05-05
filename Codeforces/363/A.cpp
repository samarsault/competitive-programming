#include <iostream>

using namespace std;

// domain - (0, 10)
void printDigit(int n)
{
	if (n >= 5)
		cout << "-O|";
	else
		cout << "O-|";

	int i;
	for (i = 0;i < n % 5;i++)
		cout << "O";
	cout << "-";
	i = 5 - i - 1;
	while (i--)
		cout << "O";
	cout << endl;
}
int main(int argc, char const *argv[])
{
	int N; 
	cin >> N;

	if (N == 0)
		printDigit(N);

	while (N > 0)
	{
		printDigit(N % 10);
		N /= 10;
	}
	return 0;
}