/*
ID: samarjeet
LANG: C
PROG: ride
TASK: ride
*/
#include <stdio.h>
#include <string.h>

int getnum(char *str)
{
	int gn = 1;
	
	for(int i = 0, l = strlen(str);i < l;i++)
	{
		int c = (str[i] - 'A') % 26 + 1;
		gn *= c;
	}
	return gn;
}
int main(int argc, char const *argv[])
{
	FILE *fin  = fopen ("ride.in", "r");
	FILE *fout = fopen ("ride.out", "w");

	char commet[7], group[7];

	fscanf (fin, "%s\n%s", commet, group);

	// Calculate Group Number
	int cm = getnum(commet) % 47;
	int gn = getnum(group) % 47;

	if (cm == gn)
		fprintf (fout, "GO\n");
	else
		fprintf(fout, "STAY\n");


	fclose(fin);
	fclose(fout);

	return 0;
}