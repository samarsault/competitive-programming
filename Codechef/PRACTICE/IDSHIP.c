#include <stdio.h>
#include <stdlib.h>

typedef struct Map {
	int head;
	char ID[4];
	char *SHIP[4];
} Map;

void map_add(Map *m, char id, char *sclass)
{
	m->ID[m->head] = id;
	m->SHIP[m->head] = malloc(sizeof(char) * 12);
	m->SHIP[m->head] = sclass;
	m->head++;
}

char* find_s(Map *mp, char key)
{
	for (int i = 0;i < 4;i++)
	{
		if (mp->ID[i] == key)
			return mp->SHIP[i];
	}
	return "\0";
}

int main(int argc, char const *argv[])
{
	Map *h = malloc(sizeof(Map));
	h->head = 0;

	map_add(h, 'B', "BattleShip");
	map_add(h, 'C', "Cruiser");
	map_add(h, 'D', "Destroyer");
	map_add(h, 'F', "Frigate");

	int T;
	char c;

	scanf("%d", &T);

	while (T--)
	{
		scanf(" %c", &c);

		if (c >= 'Z')
		{
			// lower case
			c -= 'a' - 'A';
		}

		printf("%s\n", find_s(h, c));
	}
	return 0;
}