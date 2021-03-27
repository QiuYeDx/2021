#include <iostream> //P3853 [TJOI2007]路标设置 天津省选 二分答案 自己觉得还有贪心 这就是普及+/提高???
#include <cstdio>
using namespace std;
#define maxn 100010
long long a[maxn],L,N,K;
bool P(long long d){
    long long sum=0,last=0;
    for(int i=2;i<=N;i++){
        if(a[i]-last>d)
        {
            last+=d;
            sum++;
            i--;
        }
        else
            last=a[i];  //别忘写了T_T   WA到这儿了。。。
    }
    return sum<=K;
}
int main() {
    cin >> L >> N >> K;
    for(int i=1;i<=N;i++)
        scanf("%lld",&a[i]);
    long long l=1,r=L,ans,mid;
    while(l<=r){
        if(P(mid=(l+r)>>1))
            ans=mid,r=mid-1;
        else
            l=mid+1;
    }
    printf("%lld",ans);
    return 0;
}
