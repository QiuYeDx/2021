#include <iostream> //P1618 三连击（升级版）
#include <cstdio>
#include <cstring>
using namespace std;
int b[10];
void go(int x){ //分解3位数到桶里
    b[x % 10]=1;
    b[x / 10 % 10]=1;
    b[x / 100]=1;
}
bool check(int x, int y, int z)
{
    memset(b,0,sizeof(b));
    if(y>999 || z>999) return false;
    go(x), go(y), go(z);
    for(int i=1;i<=9;i++)
        if(!b[i]) return false;
    return true;
}
int main() {
    long long  A, B, C, x, y, z, cnt=0;
    cin >> A >> B >> C;
    for(x=123;x<=987;x++)
    {
        if(x*B%A || x*C%A) continue;
        y=x*B/A, z=x*C/A;
        if(check(x,y,z))
            printf("%lld %lld %lld\n",x,y,z),cnt++;
    }
    if(!cnt) puts("No!!!");
    return 0;
}