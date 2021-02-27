#include <iostream>
#include <cstdio>
using namespace std;
int a[30];
bool check(int x)   //判断质数
{
    for(int i=2;i*i<=x;i++)
        if(x % i == 0)
            return 0;
        return 1;
}
int main() {
    int n, k, ans = 0;
    cin >> n >> k;
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    int U = 1 << n; //U-1即为全集
    for(int S=0;S<U;S++)    //枚举所有子集[0,U)
        if(__builtin_popcount(S) == k)  //找到k元子集
        {
            int sum=0;
            for(int i=0;i<n;i++)
                if(S & (1<<i))  //如果第i个元素在S中
                    sum+=a[i];
            if(check(sum))
                    ans++;
        }
    cout << ans;
    return 0;
}
