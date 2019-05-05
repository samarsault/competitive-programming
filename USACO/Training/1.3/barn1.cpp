/*
ID: samarjeet
LANG: C++
TASK: barn1
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
 
string mgap(string & stalls)
{
    int maxGap = 0, gapStart = 0, gapEnd = 0, gapLen = 0;
    int S = stalls.size();
 
    for (int i = 0; i < S; i++)
    {
        gapLen = 0;
 		int curr_gapStart = i;

        int k = i;

        while (stalls[k] == '0')
        {
            gapLen++;
            k++;
        }

        int curr_gapEnd = k;

        if (gapLen > maxGap)
        {
            maxGap = gapLen;
            gapStart = curr_gapStart;
            gapEnd = curr_gapEnd;
        }
        i = k;
	}
 
    stalls = stalls.substr(0, gapStart) + stalls.substr(gapEnd, S);
    return stalls;
}
 
int main()
{
    ifstream fin("barn1.in");
    ofstream fout("barn1.out");
 
    int M, S, C;
    fin >> M >> S >> C;
 
    string stalls;

    for (int i = 0; i < S; i++) 
        stalls += "0";

    for (int i = 0; i < C; i++)
    {
        int loc;
        fin >> loc;
        stalls[loc - 1] = '1';
    }
 
    int start = 0, end = 0;

    for (int i = 0; i < S; i++)
    {
        if(stalls[i] == '1')
        {
            start = i;
            break;
        }
    }
    for (int i = S; i > 0; i--)
    {
        if(stalls[i - 1] == '1')
        {
            end = i;
            break;
        }
    }
 
    stalls = stalls.substr(start, end - start);
 
    for(int i = 0; i < M - 1; i++)
        mgap(stalls);
 
    fout << stalls.size() << endl;
}