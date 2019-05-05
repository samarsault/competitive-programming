#include <stdio.h>

int main(void) 
{
	int w;
	float amt, fin;
	scanf("%d %f", &w, &amt);

	if ((w % 5) == 0)
	{
		fin = w + 0.5;
		if (fin <= amt)
			printf("%.2f\n", amt - fin);
		else
			printf("%.2f\n", amt);
	} 
	else
	{
		printf("%.2f\n", amt);
	}

	return 0;
}