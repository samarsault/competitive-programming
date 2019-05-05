/*
 * SRM 343 Div 2
 * 250 pt
 * Ad hoc
 */

#include <iostream>

using namespace std;

class PersistentNumber {
	public:
		int getPersistence(int x);
};

int PersistentNumber::getPersistence(int x)
{
	long long prod;
	int d, counter = 0;
	do {
		prod = 1;
		d = 0;
		while (x > 0)
		{
			prod *= x % 10;
			x/=10;
			d++;
		}
		counter++;
		x = prod;
	} while (d > 1);
	
	return counter - 1;
}

int main(int argc, char *argv[])
{
	int x;
	cin >> x;

	PersistentNumber p;	
	cout << p.getPersistence(x);
	return 0;
}
