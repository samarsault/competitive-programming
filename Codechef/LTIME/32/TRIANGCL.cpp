/*
 * Triangle Classification
 * Use Pythagoras theorum (instead of Law of Cosines)
 */
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

typedef struct Triangle {
	double A; // side A
	double B; // side B
	double C; // side C
} Triangle;

double pdistance(int x1, int y1, int x2, int y2)
{
	return sqrt( (x2 - x1)*(x2 - x1) + (y2 - y1) * (y2 - y1) );
}

inline bool equals(double a, double b)
{
	return abs(a - b) < 0.000001; // | A - B | < 10^(-6)
}

// order sides to get highest value in C
void order(double &A, double & B, double & C)
{
	if (A > C)
		swap(A, C);
	if (B > C)
		swap(B, C);
	if (A > B)
		swap(A, B);
}

int main(int argc, char const *argv[])
{
	int SUBID, T;
	cin >> SUBID >> T;

	int x1, y1, x2, y2, x3, y3;

	while (T--)
	{
		string stype, atype; // side and angle
		Triangle *tr = new Triangle;
		cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
		tr->A = pdistance(x1, y1, x2, y2);
		tr->B = pdistance(x2, y2, x3, y3);
		tr->C = pdistance(x3, y3, x1, y1);

		if (equals(tr->A, tr->B) || equals(tr->B, tr->C) || equals(tr->A, tr->C))
			stype = "Isosceles";
		else
			stype = "Scalene";

		if (SUBID == 2)
		{
			order(tr->A, tr->B, tr->C);
			double s = tr->A*tr->A + tr->B * tr->B;
			if (equals(s, (tr->C * tr->C)))
				atype = " right";
			else if (s < (tr->C * tr->C))
				atype = " obtuse";
			else
				atype = " acute";
		}

		cout << stype << atype << " triangle" << endl;
	}
	return 0;
}