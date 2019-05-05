#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

const int mx =10;
int n,k;
int p[mx];
bool maxima[mx],minima[mx];

int main(int argc, char *argv[])
{
	scanf("%d %d", &n, &k);	

	for (int i = 0;i < n;i++) {
		maxima[i] = minima[i] = false;
	}

	for (int i = 0;i < n;i++)
		scanf("%d",&p[i]);

	for (int i = 0;i < n-1;i++) 
	{
		if (p[i+1] > p[i]) // up
		{
			// potential minima
			minima[i] = true;	
			// find corresponding maxima
			int j = i + 1;
			while (j + 1 < n && p[j+1] > p[j])
				j++;
			if (j+1 < n )
				maxima[j] = true;
			else
				maxima[n-1]= true;
			i = j;
		} else if(p[i+1]<p[i]) { // down
			// potential maxima
			maxima[i] = true;	
			// find corresponding minima
			int j = i + 1;
			while (j < n && p[j] < p[j-1])
				j++;
			if (j < n)
				minima[j-1] = true;
			else
				minima[n-1]=true;
			i = j;
		}
	}

	for (int i = 0;i < n;i++)
	{
		if (maxima[i]) 
			printf("Maxima at %d\n", p[i]);
		if (minima[i])
			printf("Minima at %d\n", p[i]);
	}
	return 0;
}
