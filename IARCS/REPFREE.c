#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

int cmp(const void * a, const void * b){
	return *(int*)a < *(int*)b;
}


int main(void)
{
	char s[10];
	scanf("%s",s);
	int n = strlen(s);
	char L[10]; // free chars
	int k = 0;
	bool valid;

	for (int i = '0';i<='9';i++)
	{
		valid = true;
		for (int j = 0;j < n;j++)
			if (s[j] == (char)i)
				valid = false;

		if (valid)
			L[k++] = (char)i;
	}

	int j = 0, m = strlen(L); // duplicates
	int dup[10], p=0;

	for (int i = 0;i < n;i++)
	{
		for (int k = i + 1;k < n;k++){
			if (s[i] == s[k]) {
				j++;
				dup[p++]=k;
			}
		}
	}

	qsort(dup, p, sizeof(int), cmp);

	if (j > m) {
		printf("0\n");
		return 0;
	}

	for (int i = 0;i < p;i++) 
	{
		if (s[dup[i]] < '9') {
			int sm=0;
			for (int q = 0; q < m;q++) {
				if (L[q] >= s[dup[i]])
					s[dup[i]]++;
			}
		}
	}
	printf("%s\n",s);
	return 0;
}
