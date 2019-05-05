#include <iostream>
#include <cmath>
#include <climits>

class SortEstimate
{
public:
	double howMany(int c, int time)
	{
		// find n such that c * n * lg(n) <= time
		// p(n) = n*lg(n) <= t
		double low = 1, high = INT_MAX, n, t;
		while ((high-low) > 1e-9)
		{
			n = (low+high)/2;
			t = c * n * log(n)/log(2);
			if (t == time)
				return n;
			
			if (t <= time)
				low =  n;
			else
				high = n;
		}
		return n;
	}
};

int main(int argc, char *argv[])
{
	SortEstimate s;
	std::cout << s.howMany(1, 2000000000);
	return 0;
}
