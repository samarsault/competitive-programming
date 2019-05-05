#include <stdio.h>

typedef int BOOL;

int main(int argc, char const *argv[])
{
	int T, grade;
	float hardness, cc, tensile;
	scanf("%d", &T);

	while (T--)
	{
		scanf("%f %f %f", &hardness, &cc, &tensile);

		BOOL c1, c2, c3;
		c1 =  hardness > 50;
		c2 = cc < 0.7;
		c3 = tensile > 5600;

		if (c1 && c2 && c3)
			grade = 10;
		else if (c1 && c2)
			grade = 9;
		else if (c2 && c3)
			grade = 8;
		else if (c1 && c3)
			grade = 7;
		else if (c1 || c2 || c3)
			grade = 6;
		else
			grade = 5;

		printf("%d\n", grade);
	}
	return 0;
}