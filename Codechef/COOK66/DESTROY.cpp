#include <iostream>
#include <algorithm>
#include <map>
#include <iterator>

using namespace std;

typedef map<int, int>::iterator it_type;

int main(int argc, char const *argv[])
{
	int T, N;
	cin >> T;

	while (T--)
	{
		cin >> N;
		long K;

		// store no. frequencies
		map<int, int> store;

		for (int i = 0;i < N;i++)
		{
			cin >> K;
			if (store.count(K))
				store[K]++;
			else
				store[K] = 0;
		}

		for (it_type iterator = store.begin(); iterator != store.end(); iterator++) 
		{
			cout << iterator->first << " " << iterator->second << endl;
		}
	}
	return 0;
}