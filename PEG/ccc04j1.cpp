#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[])
{
	int N;
	cin >> N;
	cout << "The largest square has side length " << floor(sqrt(N)) << '.' << endl;
	return 0;
}
