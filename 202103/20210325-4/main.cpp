#include <iostream> //P2678 [NOIP2015 提高组] 跳石头  第一次自己写二分答案哈哈哈，一遍AC~
#include <cstdio>
using namespace std;
#define maxn 50010
typedef long long LL;
LL a[maxn],l,n,m;
bool P(int d){
    int last=0,sum=0;
    for(int i=1;i<=n;i++)
        if(a[i]-last < d)
            sum++;
        else{
            last=a[i];
        }
    return sum <= m;
}
int main() {
    cin >> l >> n >> m;
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    LL L=0,R=l,ans,mid;
    while(L<=R){
        if(P(mid=(L+R)>>1)){
            ans=mid;
            L=mid+1;
        }
        else
            R=mid-1;
    }
    printf("%lld",ans);
    return 0;
}
