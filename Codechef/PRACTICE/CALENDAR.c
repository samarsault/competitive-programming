/*
 * Calendar
 * https://www.codechef.com/problems/FLOW015
 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int T, year;
	char const *days[7] = { "monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday" };
	scanf("%d", &T);

	while(T--)
	{
		scanf("%d", &year);
		int diff = abs(year - 2001);

		if (year % 4 == 0)
		{
			// leap year
			printf("%s\n", days[(diff % 7) - 1]);
		}
		else
		{
			printf("%s\n", days[(diff % 7)]);
		}
	}

	return 0;
}
