#include <stdio.h>

int main(int argc, const char *argv[])
{
    int T, L, C;
    char black = '*';
    char white = '.';

    scanf("%d", &T);

    while (T--)
    {
        scanf("%d %d", &L, &C);
        for (int i = 0; i < L; i++) 
        {
            if (i % 2 == 0)
            {
                for (int j = 0; j < C; j++)
                {
                    if (j % 2 == 0)
                        printf("%c", black);
                    else
                        printf("%c", white);
                }
            }
            else
            {
                for (int j = 0; j < C; j++)
                {
                    if (j % 2 == 0)
                        printf("%c", white);
                    else
                        printf("%c", black);
                }
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
