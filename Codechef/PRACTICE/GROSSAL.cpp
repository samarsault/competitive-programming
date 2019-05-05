#include <iostream>

int main(int argc, char const *argv[])
{
	int T, sal;
	std::cin >> T;

	while (T--)
	{
		double HRA, DA;

		std::cin >> sal;
		
		if (sal < 1500) 
		{
			HRA = 0.1 * sal;
			DA = 0.9 * sal;
		}
		else
		{
			HRA = 500;
			DA = 0.98 * sal;
		}
		
		double GSAL = sal + HRA + DA;

		std::cout << GSAL << std::endl;

	}
	return 0;
}