/*
 * Total Expenses
 * https://www.codechef.com/problems/FLOW009
 */
#include <stdio.h>

int main(int argc, char const *argv[])
{
	int T, quantity, price;
	double tex;
	scanf("%d", &T);

	while(T--)
	{
		scanf("%d %d", &quantity, &price);

		tex = quantity * price;
		if (quantity > 1000)
			tex -= (tex * 0.1);

		printf("%.6f\n", tex);
	}

	return 0;
}