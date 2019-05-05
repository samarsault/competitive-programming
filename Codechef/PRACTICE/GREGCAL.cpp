/*
 *
 * Gregorian Calendar
 * https://www.codechef.com/problems/FLOW015
 *
 */
#include <iostream>

using namespace std;

bool leap(int x)
{
    return (x % 4 == 0) && (x % 100 != 0 || x % 400 == 0);
}

int main(int argc, char const *argv[])
{
	int T, N;
	cin >> T;
	string days[] = { "monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday" };

	while (T--)
	{
		// 1 Jan 1900 = Monday
		int di = 0; // current day
		cin >> N;
		int year = 1900;

		if (N >= 2001)
			year = 2001;

		for (;year < N;year++)
		{
			if (leap(year))
				di = (di + 366) % 7;
			else
				di = (di + 365) % 7;
		}
		cout << days[di] << endl;
	}
	return 0;
}