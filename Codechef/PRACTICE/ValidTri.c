#include <stdio.h>

int main(void)
{
    int i = 0, T, A, B, C;
    scanf("%d", &T);

    while (i < T)
    {
        scanf("%d %d %d", &A, &B, &C);
        if ((A != 0 && B != 0 && C != 0) && (A + B + C) == 180)
        {
             printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
        i++;
    }
}
