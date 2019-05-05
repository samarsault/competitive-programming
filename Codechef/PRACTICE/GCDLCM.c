#include <stdio.h>

int HCF(int a,int b)
{
    if (b == 0)
        return a;
    return HCF(b, a % b);
}
int main(int argc, const char *argv[])
{
    int T;
    scanf("%d", &T);

    while (T--)
    {
        int m, n, a;
        scanf("%d %d", &m, &n);
        a = HCF(m, n);
        printf("%d %d\n", a, (m * n) / a);
    }
    return 0;
}
