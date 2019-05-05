#include <stdio.h>

int main(int argc, const char *argv[])
{
   int n;
   scanf("%d", &n);
   int zs = 0;

    while (n % 10 == 0)
    {
        n /= 10;
        zs++;
    }

    printf("%d", zs);
    return 0;
}
