#include <stdio.h>
#include <string.h>
#define KSIZE 200

int main(int argc, const char *argv[])
{
    int t;
    scanf("%d", &t);
    char s[KSIZE];
    while (t--)
    {
       scanf("%s", s); 
       int ln = strlen(s) / 2 ;
       for (int i = 0 ; i < ln ; i += 2)
       {
           printf("%c", s[i]);
       }
       printf("\n");
    }
    return 0;
}
