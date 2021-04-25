#include<iostream>
#include<queue>
using namespace std;
const int N=350;

struct point{
    int x;
    int y;
    int t;
};

queue<point> que;

char a[N][N];
bool vis[N][N];
int n,m;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int sx;
int sy;

void goto_another(int &nx,int &ny,int k)//goto_another函数用于寻找另一个传送门，nx、ny代表当前点的坐标，记得要加上取地址符'&'，因为每当贝西踏入一个传送门，它就会立即被传送至另一个传送门，不能在原地停留
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i][j]==a[nx][ny]&&(i!=nx||j!=ny))//如果a[i][j]这个点的是一个与a[nx][ny]相同的传送门，并且a[i][j]与a[nx][ny]不是同一个点
            {
                nx=i;//改变当前坐标，将贝西强行移动至另一个传送门处
                ny=j;
                return ;//告辞
            }
        }
    }
}
int main()
{

    cin>>n>>m;
    string s;
    for(int i=1;i<=n;i++)
    {
        cin>>s;//由于输入奇奇怪怪地没有空格，于是乎窝便使用字符串读入
        for(int j=1;j<=m;j++)
        {
            a[i][j]=s[j-1];
            if(a[i][j]=='@')//获取起点坐标
            {
                sx=i;
                sy=j;
            }
        }
    }
    que.push((point){sx,sy,0});

    while(!que.empty())
    {
        point f=que.front();
        que.pop();
        if(a[f.x][f.y]=='=')
        {
            cout<<f.t;
            return 0;
        }
        if(a[f.x][f.y]>='A'&&a[f.x][f.y]<='Z')//特判部分，如果当前点是一个传送门，那么就传送至另一个传送门
        {
            goto_another(f.x,f.y,f.t);
        }
        for(int i=0;i<=3;i++)
        {
            int nx=f.x+dx[i];
            int ny=f.y+dy[i];
            if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&a[nx][ny]!='#'&&!vis[nx][ny])
            {
                vis[nx][ny]=true;
                que.push((point){nx,ny,f.t+1});
            }
        }
    }
    return 0;
}