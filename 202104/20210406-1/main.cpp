#include <bits/stdc++.h>    //P1101 单词方阵  模拟/dfs  激动！！！一个小时的debug，终于一次性AC啦！~~~
using namespace std;
#define maxn 110
int n;
char a[maxn][maxn]={0};
char ans[maxn][maxn]={0};
const char word[7]={'y','i','z','h','o','n','g'};
const int d[8][2]={{-1,0},{-1,1},{0,-1},{1,1},{1,0},{1,-1},{0,1},{-1,-1}};
struct P{
    int w,dd,x,y;
};
void dfs(P p){
    if(p.x>0 && p.y>0 && p.x<=n && p.y<=n && p.w==5 && a[p.x][p.y]=='g'){
        for(int i=6;i>=0;i--){
            ans[p.x][p.y]=word[i];
            p.x-=d[p.dd][0];
            p.y-=d[p.dd][1];
        }
        return;
    }
    P tmp=(P){p.w,p.dd,p.x,p.y};
    //printf("%c\n",a[p.x][p.y]);
    if(p.x>0 && p.y>0 && p.x<=n && p.y<=n && a[p.x][p.y]==word[p.w+1]){
        if(p.dd==-1)
            for(int i=0;i<8;i++){
                tmp.w=p.w+1;
                tmp.dd++;
                tmp.x=p.x+d[tmp.dd][0];
                tmp.y=p.y+d[tmp.dd][1];
                dfs(tmp);
            }
        else{
            tmp.w=p.w+1;
            tmp.x+=d[tmp.dd][0];
            tmp.y+=d[tmp.dd][1];
            dfs(tmp);
        }
    }
}
int main() {
    cin >> n;
    for(int i=1;i<=n;i++)
        scanf("%s",a[i]+1);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            ans[i][j]='*';
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            dfs((P){-1,-1,i,j});
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            printf("%c",ans[i][j]);
        printf("\n");
    }
    /*printf("\n\n");
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            printf("%c",a[i][j]);
        printf("\n");
    }*/
    return 0;
}
