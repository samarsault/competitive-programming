#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int n;

int dp[300][300*150];// dp[index][A took_first?]

int min(int a,int b){
	return a < b? a  : b;
}
int max(int a,int b){
	return a > b? a  : b;
}
int main(int argc, char *argv[])
{
	scanf("%d", &n);

	int k = 300*150,f,g;

	for (int i = 0;i<n;i++)
		for (int j = 0;j < k;j++)
			dp[i][j] = 0;
	
	int a[n],s=0;

	for (int i = 0;i < n;i++)
	{
		scanf("%d %d",&f,&g);
		a[i] = abs(f - g);
		s += a[i];
		dp[i][a[i]] = 1;
	}

	int comp = s/2;
	int mn=1e8,req;
	for (int i = 1 ;i < n;i++)
	{
		for (int j = 0;j < k;j++)
		{
			if (j==0) {
				dp[i][j] = 1;
				continue;
			}
			if ( (dp[i-1][j]) || (j-a[i] >= 0 && dp[i-1][ j-a[i] ]) ) {
				dp[i][j] = 1;
				if ( abs(s - 2*j) <  mn) {
					mn = abs(s - 2*j);
				}
			}
		}
	}

	printf("%d\n", mn);
	return 0;
}
