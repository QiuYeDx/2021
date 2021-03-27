#include <iostream> //P1873 砍树  二分答案 高性能
#include <cstdio>
#include <algorithm>

#define maxn 1000010
using namespace std;
typedef long long LL;
LL a[maxn], n, m;

bool P(int h) {
    LL tot = 0;
    for (int i = 1; i <= n; i++)
        if (a[i] > h)
            tot += a[i] - h;
    return tot >= m;
}

int main() {
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    LL L=0,R=1e9,ans,mid;
    while(L<=R){
        if(P(mid = (L + R) >> 1))   //L+R外的括号可以不要
            ans=mid,L=mid+1;
        else
            R=mid-1;
    }
    printf("%lld",ans);
    return 0;
}
