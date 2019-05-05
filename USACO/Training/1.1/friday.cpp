/*
ID: samarjeet
LANG: C++11
PROG: friday
TASK: friday
*/

#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>

using namespace std;

int months[13] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int DAYS[7];

int leap(int year)
{
    if (year % 100 == 0)
    {
        if (year % 400 == 0)
            return true;
        return false;
    }

    return (year % 4 == 0);
}

int main(int argc, char const *argv[])
{
    memset(DAYS, 0, sizeof(DAYS));

    ifstream fin("friday.in");
    ofstream fout("friday.out");

    /* solve */
    int N, id;
    fin >> N;
    N += 1900;

    int prev = 0;
    for (int year = 1900; year < N; year++) 
    {
        for (int month = 0;month < 12;month++)
        {
            DAYS[prev]++;

            id = months[month];

            if (month == 1)
                id += leap(year);

            prev = (prev + id) % 7;
        }        
    }
    
    for (int i = 0;i < 6;i++)
        fout << DAYS[i] << ' ';
    fout << DAYS[6] << endl;

    fin.close();
    fout.close();
    return 0;
}
