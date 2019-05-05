#include <iostream>

using namespace std;

int HCF(int a,int b)
{
    if (b == 0)
        return a;
    return HCF(b, a % b);
}

int main(int argc, const char *argv[])
{ 
    int T, A, B;
    cin >> T;
    
    while (T--)
    {
        cin >> A >> B;    
        cout << HCF(A, B) << endl;
    }

    return 0;
}