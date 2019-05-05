#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int main(int argc, char const *argv[])
{
	double h, w, BMI;
	cin >> w >> h;
	BMI = w / (h * h);
	if (BMI > 25.0)
		cout << "Overweight" << endl;
	else if (BMI < 18.5)
		cout << "Underweight" << endl;
	else if (BMI > 18.5 && BMI < 25.0)
		cout << "Normal Weight" << endl;
	return 0;
}
