/*
 * Disadvantages:
 *  1. All objects considered distinct
 *  2. Not lexographically sorted
 */

#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

void permute(string s, int level = 0)
{
    if (level == s.size()) { 
        cout << s << endl;
        return;
    } else {
        for (int i = level;i < s.size();i++)
        {
            swap(s[i], s[level]);
            permute(s, level + 1);
            swap(s[level], s[i]);
        }
    }
}
int main(void)
{
    permute("ACB");
}