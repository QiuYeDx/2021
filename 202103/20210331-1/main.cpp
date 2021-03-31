#include <iostream> //P1443 马的遍历    广度优先搜索,bfs  队列  例题
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
#define maxn 310
struct coord{
    int x,y;
};
queue<coord> Q; //队列
int ans[maxn][maxn];
int walk[8][2]={{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1}};   //马能走的8个方向
int main() {
    int n,m,sx,sy;
    memset(ans,-1,sizeof ans);
    cin >> n >> m >> sx >> sy;
    coord tmp={sx,sy};
    Q.push(tmp);    //使起点入队扩展
    ans[sx][sy]=0;
    while(!Q.empty()){  //循环直到队列为空
        coord u=Q.front();  //拿出队首以扩展
        int ux =u.x,uy=u.y;
        Q.pop();
        for(int k=0;k<8;k++){
            int x=ux+walk[k][0],y=uy+walk[k][1];
            int d=ans[ux][uy];
            if(x<1 || x>n || y<1 || y>m || ans[x][y]!=-1)
                continue;   //若坐标超过地图范围或者该店已被访问过则无需入队
            ans[x][y]=d+1;  //记录答案，是上一个点多走一步的结果
            coord tmp={x,y};
            Q.push(tmp);
        }
    }
    for(int i=1;i<=n;i++,puts(""))
        for(int j=1;j<=m;j++)
            printf("%-5d",ans[i][j]);   //场宽输出
    return 0;
}
