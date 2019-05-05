#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int a, b, c;
	cin >> a >> b >> c;
	if (c != 0)
	{
		if (c > 0)
		{
			if (b < a)
			{
				cout << "NO" << endl;
			}
			else
			{
				if((b - a) % c == 0)
					cout << "YES" << endl;
				else
					cout << "NO" << endl;
			}
		}
		else
		{
			// C is negative
			if (b > a)
			{
				cout << "NO" << endl;
			}
			else 
			{
				if ((b - a) % c == 0)
					cout << "YES" << endl;
				else
					cout << "NO" << endl;
			}
		}
	}
	else {
		if (a == b)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}