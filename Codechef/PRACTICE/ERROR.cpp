#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	int T;
	string S;
	cin >> T;

	while (T--)
	{
		cin >> S;
		int k = S.size();
		if (S.find("101") < k || S.find("010") < k)
			cout << "Good" << endl;
		else
			cout << "Bad" << endl;
	}
	return 0;
}