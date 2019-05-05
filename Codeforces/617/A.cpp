#include <iostream>

int main(int argc, char const *argv[])
{
	int x;
	std::cin >> x;
	int steps = 0;
	int i = 5;
	while (x > 0 && i > 0)
	{
		if (i <= x)
		{
			steps += x / i;
			x = x % i;
		}
		i--;
	}
	std::cout << steps << std::endl;
	return 0;
}