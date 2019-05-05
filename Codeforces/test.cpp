#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <climits>
 
using namespace std;
 
int main(int argc, char *argv[])
{
	int n, j;
	cin >> n;
	if (n == 0){ cout<<1; return 0; }
	// 8, 4, 2, 6
	switch (n%4){
		case 1:
			cout << 8;
			break;
		case 2:
			cout << 4;
			break;
		case 3:
			cout << 2;
			break;
		case 0:
			cout << 6;
			break;
	}
	return 0;
}
