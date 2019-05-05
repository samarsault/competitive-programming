#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int main(int argc, char const *argv[])
{
	int N;
	cin >> N;
	for (int i = 1;i <= N;i++)
		cout << N << " X " << i << " = " << (i * N) << endl;
	return 0;
}