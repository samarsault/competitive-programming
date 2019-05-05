#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int jacketCost, sockCost, money;
	cin >> jacketCost >> sockCost >> money;
	int jk = money - jacketCost;

	if ((jk / sockCost) % 2 == 0)
		cout << "Lucky Chef";
	else
		cout << "Unlucky Chef";
	
	cout << endl;
	return 0;
}
