#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

typedef struct Date {
	int y;
	int m;
	int d;
} Date;

bool solve(Date born)
{
	// Election - Feb 27, 2007
	if ((2007 - born.y) > 18)
		return true;
	else if ((2007 - born.y) == 18)
	{
		if (born.m < 2 || (born.m == 2 && born.d <= 27))
			return true;
		else
			return false;
	}
	else
		return false;
}

int main(int argc, char const *argv[])
{
	int T;
	cin >> T;
	while (T--)
	{
		Date d;
		cin >> d.y >> d.m >> d.d;
		if (solve(d))
			cout << "Yes" << endl;
		else
			cout <<"No"<< endl;
	}
	return 0;
}