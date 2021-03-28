#include <bits/stdc++.h>    //P1433 吃奶酪 状态压缩动态规划(逆推) dfs(深度优先搜索)
using namespace std;    //第一道自己慢慢理解感悟的状态压缩动态规划解法(本来想学dfs的说...)
#define reg register
double dp[1<<16][17],dist[17][17],x[17],y[17];
int n;
inline void init(){
    scanf("%d",&n);
    for(reg int i=1;i<=n;++i)
        scanf("%lf%lf",x+i,y+i);
    x[0]=y[0]=0;
    for(reg int i=0;i<=n;++i)
        for(reg int j=0;j<=n;++j)
            dist[i][j]=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));   //计算从第i个点到第j个点的距离
        memset(dp,127,sizeof dp);   //一开始所有情况下的dp值均为无穷大([从第i个点开始，S点集的情况下]距离无穷大,其中i,S去任意有效值)
}
inline void solve(){
    for(reg int i=0;i<=n;++i)
        dp[(1<<n+1)-1][i]=0;    //将从i=0到i=n的每一个点集都初始化为全1(满),即一开始全部点均未走
    for(reg int S=(1<<n+1)-2;~S;--S)    //S从各位均为1递减枚举到各位为0,然后再减1,变为-1,而~-1为false，结束循环
        for(reg int i=0;i<=n;++i)
            for(reg int j=0;j<=n;++j)
                if(!(S&1<<j))          //<<优先级比&高  means:如果是[从第i个点出发,第j个点已走]的状态,则
                    dp[S][i]=min(dp[S][i],dp[S|1<<j][j]+dist[i][j]);    /*[从第i个点出发剩余S个点未走]状态下的ans
 * 与[从第j个点出发剩余S+1个点未走(第i个点未走)]+从第j个点到第i个点的距离dist[i][j] 作比较,取最小值赋给dp[S][i]*/
    printf("%.2lf",dp[0][0]);
}
int main() {
    init();
    solve();
    return 0;
}
