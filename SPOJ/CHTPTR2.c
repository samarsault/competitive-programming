#include <stdio.h>

int main(int argc, const char *argv[])
{
    int T, L, C;
    char b = '*';
    char f = '.';

    scanf("%d", &T);

    while (T--)
    {
        scanf("%d %d", &L, &C);
        
        for (int i = 0; i < L; i++) 
        {
            if ((C % 2 == 0) && (i != 0) && (i != (C - 1)))
            {
                printf("%c", b);
                for (int j = 2; j < C; j++)
                {
                    printf("%c", f);
                }
                printf("%c", b);
            }
            else 
            {
                for (int j = 0; j < C; j++)
                {
                    printf("%c", b);
                }
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
