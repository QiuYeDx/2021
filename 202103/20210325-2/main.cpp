#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
#define maxn 1000010
#define INF 1e9
int a[maxn],n,c;
bool P(int d){
    int k=0,last = -INF;    //INF记录上一头牛的安置坐标
    for(int i=1;i<=n;i++)
        if(a[i]-last>=d)
            last=a[i],k++;
    return k>=c;
}
int main() {
    scanf("%d%d",&n,&c);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    int L=0,R=INF,ans,mid;
    while(L<=R){
        if(P(mid=L+R >> 1))
            ans=mid,L=mid+1;
        else
            R=mid-1;
    }
    printf("%d",ans);
    return 0;
}
