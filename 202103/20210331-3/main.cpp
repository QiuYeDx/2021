#include <bits/stdc++.h>
using namespace std;
#define maxn 310
struct coord{
    int x,y;
};
queue<coord> Q;
int ans[maxn][maxn],death[maxn][maxn];  //death表示该点被流星雨砸中的时间
int wk[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
int main() {
    int m,Ans=100000;
    memset(ans,-1,sizeof ans);  //全部赋值为-1
    memset(death,0x7f,sizeof death);    //全部赋值为一个很大的值，大约2e10
    cin >> m;
    for(int i=1;i<=m;i++){
        int x,y,t;
        cin >> x >> y >> t;
#define MIN(x,y,t) if(x>=0 && y>=0) death[x][y] = min(death[x][y],t)
        MIN(x,y,t);
        for(int k=0;k<4;k++)
            MIN(x + wk[k][0],y + wk[k][1],t);
        //记录下流行和上下左右影响范围烧焦的时间
    }
    Q.push((coord){0,0});   //原点加入到队列
    ans[0][0]=0;
    while(!Q.empty()){
        coord u = Q.front();    //取出队首
        int ux=u.x,uy=u.y;
        Q.pop();
        for(int k=0;k<4;k++){   //奶牛向四个方向运动
            int x=ux +wk[k][0],y=uy+wk[k][1];
            if(x<0 || y<0 || ans[x][y]!=-1 || ans[ux][uy]+1 >= death[x][y])
                continue;   //当目标格子的最早到达时间已经比被破坏时间晚时不能更新
            ans[x][y]=ans[ux][uy]+1;
            Q.push((coord){x,y});   //扩展的结点加入队列
        }
    }
    for(int i=0;i<=305;i++)
        for(int j=0;j<=305;j++)
            if(death[i][j]>1000 && ans[i][j]!=-1)
                Ans=min(Ans,ans[i][j]); //统计答案:在所有安全区域且能到达的点中找到达最早的
    if(Ans==100000)
        puts("-1");
    else
        printf("%d",Ans);
    return 0;
}
