#include <bits/stdc++.h>    //P1605 迷宫  经典dfs(easy)
using namespace std;
int a[8][8]={0};
int M,N,T,sx,sy,fx,fy;
int sum=0;
void dfs(int nx,int ny){
    if(nx==fx && ny==fy)    //到达终点
    {
        sum++;
        return;
    }
    a[nx][ny]=-1;   //添加标记
    if(nx-1>0 && a[nx-1][ny]!=-1)
        dfs(nx-1,ny);
    if(ny-1>0 && a[nx][ny-1]!=-1)
        dfs(nx,ny-1);
    if(nx+1<=M && a[nx+1][ny]!=-1)
        dfs(nx+1,ny);
    if(ny+1<=N && a[nx][ny+1]!=-1)
        dfs(nx,ny+1);
    a[nx][ny]=0;    //移除标记
}
int main() {
    cin >> M >> N >> T;
    cin >> sx >> sy >> fx >> fy;
    for(int i=0;i<T;i++)
    {
        int tmp_x,tmp_y;
        cin >> tmp_x >> tmp_y;
        a[tmp_x][tmp_y]=-1;
    }
    dfs(sx,sy);
    printf("%d",sum);
    return 0;
}
