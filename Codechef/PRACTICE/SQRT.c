#include <stdio.h>
#include <math.h>

int main(void)
{
    int i = 0, T, N;

    scanf("%d", &T);

    while (i < T)
    {
        scanf("%d", &N);
        printf("%0.f", sqrt((double)N));
        i++;
    }
}
