#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{

	int T;
	string S;
	cin >> T;

	char hole[] = { 'A', 'D', 'O', 'P', 'Q', 'R' };

	while (T--)
	{
		cin >> S;
		int holes = 0;
		for (int i = 0, l = S.size();i < l;i++)
		{
			if (S[i] == 'B')
			{
				holes += 2;
			}
			else 
			{
				for (int k = 0;k < 6;k++)
				{

					if (S[i] == hole[k])
					{
						holes++;
						break;
					}
				}
			}
		}

		cout << holes << endl;
	}
	return 0;
}