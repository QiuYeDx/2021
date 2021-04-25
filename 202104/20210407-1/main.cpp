#include <bits/stdc++.h>
using namespace std;
#define maxn 310
char a[maxn][maxn]={0};
int b[maxn][maxn]={0};
struct TELE{
    int x,y;
};
TELE tele[27][2]={0};
int n_tele=0;
int N,M,ux,uy;
int ans=9999999;
const int d[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
struct NOW{
    int x,y;
    int sum;
    int yn_tele[27]={0};
};
queue<NOW> Q;
int main() {
    cin >> N >> M;
    for(int i=1;i<=N;i++)
        scanf("%s",a[i]+1);
    for(int i=1;i<=N;i++)
        for(int j=1;j<=M;j++){
            if(a[i][j]=='@'){
                ux=i;
                uy=j;
            }
            else if(a[i][j]>='A' && a[i][j]<='Z'){
                if(tele[a[i][j]-'A'+1][0].x==0){
                    /*printf("%d ",*/tele[a[i][j]-'A'+1][0].x=i/*)*/;
                    /*printf("%d ",*/tele[a[i][j]-'A'+1][0].y=j/*)*/;
                }else{
                    /*printf("%d ",*/tele[a[i][j]-'A'+1][1].x=i/*)*/;
                    /*printf("%d ",*/tele[a[i][j]-'A'+1][1].y=j/*)*/;
                }
                n_tele++;
            }
        }
    /*for(int i=1;i<27;i++)
        for(int j=0;j<2;j++)
            printf("%d %d\n",tele[i][j].x,tele[i][j].y);*/
    Q.push((NOW){ux,uy,0});
    while(!Q.empty()){
        NOW now=Q.front();
        NOW tmp=now;
        b[now.x][now.y]=1;  //标记该点
        Q.pop();
        if(a[now.x][now.y]=='='){
            ans=ans>now.sum?now.sum:ans;
            continue;
        }
        if(a[now.x][now.y]>='A' && a[now.x][now.y]<='Z' && !now.yn_tele[a[now.x][now.y]-'A'+1]){
            if(tele[a[now.x][now.y]-'A'+1][0].x==now.x && tele[a[now.x][now.y]-'A'+1][0].y==now.y){
                if(!b[now.x+tele[a[now.x][now.y]-'A'+1][1].x][now.y+tele[a[now.x][now.y]-'A'+1][1].y]){
                    tmp.x=tele[a[now.x][now.y]-'A'+1][1].x;
                    tmp.y=tele[a[now.x][now.y]-'A'+1][1].y;
                    tmp.yn_tele[a[now.x][now.y]-'A'+1]=1;
                    Q.push(tmp);
                }
            }else{
                if(!b[now.x+tele[a[now.x][now.y]-'A'+1][0].x][now.y+tele[a[now.x][now.y]-'A'+1][0].y]){
                    /*printf("now.x=%d, now.y=%d\n",now.x,now.y);
                    printf("a[now.x][now.y]=%c\n",a[now.x][now.y]);
                    printf("tele[a[now.x][now.y]-'A'+1][0].x=%d\n",tele[a[now.x][now.y]-'A'+1][0].x);
                    printf("tele[a[now.x][now.y]-'A'+1][0].y=%d\n",tele[a[now.x][now.y]-'A'+1][0].y);*/
                    /*printf("%d ",*/tmp.x=tele[a[now.x][now.y]-'A'+1][0].x/*)*/;
                    /*printf("%d ",*/tmp.y=tele[a[now.x][now.y]-'A'+1][0].y/*)*/;
                    tmp.yn_tele[a[now.x][now.y]-'A'+1]=1;
                    Q.push(tmp);
                }
            }
        }else {
            for(int i=0;i<4;i++)
                if(now.x+d[i][0]>0 && now.x+d[i][0]<=N && now.y+d[i][1]>0 && now.y+d[i][1]<=M && !b[now.x+d[i][0]][now.y+d[i][1]] && a[now.x+d[i][0]][now.y+d[i][1]]!='#' && a[now.x+d[i][0]][now.y+d[i][1]]!='@')
                {
                    tmp.x+=d[i][0];
                    tmp.y+=d[i][1];
                    tmp.sum=now.sum+1;
                    Q.push(tmp);
                }
        }
    }
    printf("%d",ans);
    return 0;
}
