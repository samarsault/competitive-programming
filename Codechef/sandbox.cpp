#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
	int t, n, i;
	cin >> t;
	while (t--)
	{
		cin >> n;
		bool p[n];
		long long due = 0, months = 0;
		for (i = 0;i < n;i++)
			cin >> p[i];

		for (i=0;i<n;i++)
		{
			if (!p[i])
			{
				months++;
				due += 100;
			}
			else
			{
				if (months > 0)
				{
					due += months * 1100;
					months--;
				}
			}
		}
		
		cout << due + 1000*months<< endl;	
	}
	return 0;
}

