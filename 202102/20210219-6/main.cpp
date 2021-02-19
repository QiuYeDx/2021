#include <iostream> //P1012 [NOIP1998 提高组] 拼数 要想起用字典序排序******cmp比较函数的拟写是难点******
#include <algorithm>
#include <string>
using namespace std;
int const MAXN = 25;
string num[MAXN];
bool cmp(string x, string y)
{
    if(x.length() == y.length())
        return x > y;
    else
        if(x.length() > y.length())
    {
        string rep;
        rep=x.substr(0,y.length());
        if(rep != y)
            return rep > y;
        else
        {
            x.erase(0,y.length());
            return x > y;
        }
    }
        else
        {
            string rep;
            rep=y.substr(0,x.length());
            if(rep != x)
                return x > rep;
            else {
                y.erase(0, x.length());
                return x > y;
            }
        }
}
int main() {
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> num[i];
    sort(num,num+n,cmp);
    for(int i=0;i<n;i++)
        cout << num[i];
    return 0;
}
