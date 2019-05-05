#include <iostream>

int main(void)
{
	int mask = 0, cnt = 0, n, S[100], k;

	std::cin >> n >> k;

	for (int i = 0; i < n; ++i) 
		std::cin >> S[i];

	while (mask <= (1 << n))
	{
		int sum  = 0;
		for (int i = 0;i < n;i++)
		{
			if (mask & (1 << i))
			{
				std::cout << S[i] << ' ';
				sum += S[i];
			}
		}

		if (sum == k)
			cnt++;

		mask++;
		std::cout << std::endl;
	}

	std::cout << cnt << std::endl;
}
