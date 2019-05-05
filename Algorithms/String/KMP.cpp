/*
 * Knuth-Morris-Pratt Pattern Search Algorithm
 */
#include <cstdio>
#include <cstring>

void buildTable	(const char * pattern, int M, int *lps)
{
	int len = 0;
	int i = 1;

	lps[0] = 0;

	while (i < M)
	{
		if (pattern[i] == pattern[len])
		{
			len++;
			lps[i] = len;
			i++;
		}
		else 
		{
			if (len != 0)
				len = lps[len - 1];
			else
			{
				lps[i] = 0;
				i++;
			}
		}
	}
}

void KMPSearch(const char *text, const char *pattern)
{
	size_t M = strlen(pattern);
	size_t N = strlen(text);

	int *lps = new int[M];
	int j = 0; // pattern[j]

	buildTable(pattern, M, lps);

	int i = 0;
	while (i < N)
	{
		if (pattern[j] == text[i])
		{
			j++;
			i++;
		}

		if (j == M)
		{
			printf("Found pattern at index %d\n", i - j);
			j = lps[j - 1];
		}
		else if (i < N && pattern[j] != text[i])
		{
			if (j != 0)
				j = lps[j - 1];
			else
				i++;
		}
	}

	delete [] lps;
}

int main(int argc, char const *argv[])
{
	KMPSearch("AABAACAADAABAAABAA", "AABA");
	return 0;
}