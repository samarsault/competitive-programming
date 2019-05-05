#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

typedef pair<int,int> pii;

int main(int argc, char *argv[])
{
	int n,q,t;
	cin >> n >> q;
	while (q--) 
	{
		int block_size = ceil(sqrt(n)),a,b;
		// { heads up )
		vector<int> state(block_size, 0)
		cin >> t>>a>>b;
		if (t==0) {
			// update
			int block_a = a/block_size;
			int block_b = b/block_size;
			if (block_a == block_b) {

			}
		} else {
			// query
		}
	}
	return 0;
}
