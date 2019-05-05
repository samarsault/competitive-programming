#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
    int t,n,a;
    cin >> t;
    while (t--)
    {
        cin >> n >> a;
        if (a > 2)
        {
            string s="";
            for (int i = 0;i < n;i++)
                s += 'a' + i%3;
            cout << 1 << ' ' << s << endl;
        }
        else if (a == 2) {
            // special case
            if (n > 8) {
                string t ="aababb";
                string s = t;
                while (s.size() < n)
                    s += t;
                cout << 4 << ' ' << s.substr(0, n)<<endl;
            } else {
                int k = 0;string s;
                switch(n) {
                    case 1: s = "a";k=1;
                        break;
                    case 2: s = "ab";k=1;
                        break;
                    case 3: s= "abb";k=2;
                        break;
                    case 4: s= "aabb";k=2;
                        break;
                    case 5: s="aaabb";k=3;
                        break;
                    case 6: s= "aaabbb";k=3;
                        break;
                    case 7: s= "aaababb";k=3;
                        break;
                    case 8: s="aaababbb";k=3;
                        break;
                }
                cout << k << ' ' << s << endl;
            }

        } else { // a = 1
            cout << n << ' ';
            for (int i = 0;i < n;i++)
                cout << 'a';
            cout << endl;
        }
    }
    return 0;
}
