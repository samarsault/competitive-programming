#include <iostream>

int bf(int n)
{
    if (n == 0)
        return 1;
    return bf(n + 1)/(n + 1);
}

int main(int argc, const char *argv[])
{
    std::cout << bf(8);
    return 0;
}
