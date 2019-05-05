/*
ID: samarjeet
LANG: C++
TASK: friday
PROG: friday
*/
// Somewhat Better
#include <iostream>
#include <fstream>

using namespace std;

int mdays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30,31,30,31 };

int leapsum(int x)
{
    return (x % 4 == 0) && (x % 100 != 0 || x % 400 == 0);
}

int getdays(int y, int month)
{
    if (month == 2) // feb
        return mdays[month - 1] + leapsum(y);
    return mdays[month - 1];
}

int main(int argc, char const *argv[])
{
    ifstream fin ("friday.in");
    ofstream fout("friday.out");

    int N;
	fin >> N;
    N += 1900;
    // { Saturday, Sunday, .... Friday }
    int freq[7] = { 0, 0, 0, 0, 0, 0, 0 };

    // January 13, 1900 was on a Saturday i.e. index 0
    // first of date
    int d13 = 0;
    for (int year = 1900;year < N;year++)
    {
        for (int month = 1;month <= 12;month++)
        {
            freq[d13]++;
            d13 = (d13 + getdays(year, month)) % 7;
        }
    }

    for (int i = 0;i < 6;i++)
        fout << freq[i] << " ";
    fout << freq[6] << endl;

    // close
    fin.close();
    fout.close();
    return 0;
}