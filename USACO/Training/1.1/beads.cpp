/*
ID: samarjeet
LANG: C++
TASK: beads
PROG: beads
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

char closestw (string beads, int i)
{
    while (beads[i] == 'w')
        i++;
    return beads[i];
}

char beadinverse(char c)
{
    if (c == 'r')
        return 'b';
    return 'r';
}
bool isuniform(string str)
{
    for (int i = 0, l = str.size();i < l;i++)
    {
        if (str[0] != str[i])
        {
            return false;
            break;
        }
    }
    return true;
}
int main(int argc, char const *argv[])
{
    ifstream fin ("beads.in");
    ofstream fout("beads.out");

    // Read Input
    int N;
    fin >> N;
    string beads;
    fin >> beads;

    // Logic
    // Double String
    beads += beads;

    // Max Beads
    int maxB = 0;
    for (int i = 0, l = beads.size(); i < l;i++)
    {
        char c = beads[i];
        if (c == 'w')
            c = closestw(beads, i);

        char m = beadinverse(c);
        int a = 0, b = 0;
        int k = i;
        
        while (beads[k] != '\0' && beads[k] != m)
        {
            a++;
            k++;
        }

        if (c == 'w')
            c = closestw(beads, i);

        while(beads[k] != '\0' && beads[k] != c)
        {
            b++;
            k++;
        }
        
        int mx = a + b;

        if (mx >= N) 
        {
            maxB = N;
            break;
        }
        // update maximum bead variable
        if (maxB < mx)
            maxB = mx;
    }

    fout << maxB << endl;

    // close
    fin.close();
    fout.close();
    return 0;
}