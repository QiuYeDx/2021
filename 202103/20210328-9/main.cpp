#include <bits/stdc++.h>    //P1433 复刻(根据思路默写哈哈哈)
using namespace std;
#define reg register
int n;
double x[17],y[17];
double dist[17][17],dp[1<<16][17];  //dp的点集S中包含了起始点(0,0)，故会用到距离dist[0][0],且下面S=(1<<n+1)-2
inline void init(){
    scanf("%d",&n);
    for(reg int i=1;i<=n;i++)   //出发点是(0,0)
        scanf("%lf%lf",x+i,y+i);
    x[0]=y[0]=0;
    for(reg int i=0;i<=n;i++)   //要从0开始！！！
        for(reg int j=0;j<=n;j++)
            dist[i][j]=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
    memset(dp,127,sizeof dp);
}
inline void solve(){
    for(reg int i=0;i<=n;i++)
        dp[(1<<n+1)-1][i]=0;    //初始化从任意点出发其余点均未经过情况的dp值为0
    for( reg int S=(1<<n+1)-2;~S;S--)   //从已有一个点(起始点(0,0))已走开始dp
        for(reg int i=0;i<=n;i++)
            for(reg int j=0;j<=n;j++)
                if(!(S&1<<j))
                    dp[S][i]=min(dp[S][i],dp[S|1<<j][j]+dist[i][j]);
    printf("%.2lf",dp[0][0]);
}
int main() {
    init();
    solve();
    return 0;
}
