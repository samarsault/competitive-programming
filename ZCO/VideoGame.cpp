#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
	std::ios_base::sync_with_stdio(false);

	int N, H, C;
	cin >> N >> H;
	int A[N];
	vector<int> Commands;

	for (int i = 0;i < N;i++)
		cin >> A[i];

	while (true)
	{
		cin >> C;
		if (C == 0)
			break;
		Commands.push_back(C);
	}

	int cpos = 0; // crane position
	bool hasbox = false;
	int l = Commands.size();

	for (int i = 0;i < l;i++)
	{
		switch(Commands[i])
		{
			case 1:
				if (cpos > 0)
					cpos--;
				break;
			case 2:
				if ((cpos + 1) < N)
					cpos++;
				break;
			case 3:
				if (A[cpos] > 0 && !hasbox)
				{
					hasbox = true;
					A[cpos]--;
				}
				break;
			case 4:
				if (hasbox && A[cpos] < H)
				{
					hasbox = false;
					A[cpos]++;
				}
				break;
		}
	}

	for (int i = 0;i < N;i++)
		cout << A[i] << " ";

	cout << endl;

	return 0;
}