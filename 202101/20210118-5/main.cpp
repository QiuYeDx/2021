#include <iostream> //P4956 [COCI2017-2018#6] Davor
using namespace std;
int main()
{
    int n,x,k;
    cin >> n;
    for(x=100;x>0;x--)
        for(k=1;k<100000;k++)
        {
            if(x*52*7+k*21*52==n)
            {
                cout << x << endl << k;
                return 0;
            }
            else
                if(x*52+k*21*52>n)
                    break;
        }
    return 0;
}
