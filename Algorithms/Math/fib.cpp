#include <iostream>

int main(int argc, const char *argv[])
{
    int f, f1 = 0, f2 = 1;
    int count = 10;

    while (count--)
    {
        f = f1 + f2;
        f1 = f2;
        f2 = f;
        std::cout << f << " ";
    }
    std::cout << std::endl;
} 
