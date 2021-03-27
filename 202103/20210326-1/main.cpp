#include <iostream> //P2440 木材加工 二分答案 贪心
#include <cstdio>
#define maxn 100020
using namespace std;
typedef long long LL;
LL a[maxn],N,K;
bool P(LL d){
    if(d==0)        //不能少写，否则有可能RE 因为除数不能为0
        return true;
    LL sum=0;
    for(int i=1;i<=N;i++)
        sum+=a[i]/d;
    return sum>=K;
}
int main() {
    cin >> N >> K;
    for(int i=1;i<=N;i++)
        scanf("%lld",&a[i]);
    LL L=0,R=1e9,ans=0,mid;
    while(L<=R){
        if(P(mid=L + (R - L) / 2))
            ans=mid,L=mid+1;
        else
            R=mid-1;
    }
    printf("%lld",ans);
    return 0;
}
