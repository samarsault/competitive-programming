#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main(){
	int n = 2;
	int a[4] = { 1, 2 };
	copy(a, a + n, a + n);
	for (int i = 0;i < 4;i++)
		cout << a[i] << ' ';
	return 0;
}
