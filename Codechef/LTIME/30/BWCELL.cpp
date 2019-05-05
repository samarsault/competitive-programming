#include <iostream>

int main(int argc, char const *argv[])
{
	using namespace std;

	int T;
	cin >> T;

	while (T--)
	{
		string s;
		cin >> s;
		int w = s.find('W');
		int l = s.size();
		if (l % 2 != 0  && w == l / 2)
			cout << "Chef" << endl;
		else
			cout << "Aleksa" << endl;
	}
	return 0;
}