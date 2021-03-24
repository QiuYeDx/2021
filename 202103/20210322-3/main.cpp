#include <iostream>
using namespace std;
int dp[210][210]={0};
int n,m,q,f,x1,x2,y1,y2;
int ans=0;
void f_1();
void f_2();
void f_3();
void f_4();
void f_5();
void f_6();
void f_7();
int main() {
    cin >> n >> m >> q;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d",&dp[i][j]);
    for(int i=0;i<q;i++)
    {
        scanf("%d %d %d %d %d",&f,&x1,&y1,&x2,&y2);
        switch(f){
            case 1:
                f_1();
                break;
            case 2:
                f_2();
                break;
            case 3:
                f_3();
                break;
            case 4:
                f_4();
                break;
            case 5:
                f_5();
                break;
            case 6:
                f_6();
                break;
            case 7:
                f_7();
                break;
            default:
                break;
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(dp[i][j]==0)
                ans++;
    printf("%d",ans);
    return 0;
}
void f_1(){
    for(int i=x1;i<=x2;i++)
        for(int j=y1;j<=y2;j++)
            if(dp[i][j]==1)
                dp[i][j]=0;
}
void f_2(){
    for(int i=x1;i<=x2;i++)
        for(int j=y1;j<=y2;j++)
            if(dp[i][j]==1)
                dp[i][j]=3;
}
void f_3(){
    for(int i=x1;i<=x2;i++)
        for(int j=y1;j<=y2;j++)
            if(dp[i][j]==1)
                dp[i][j]=2;
}
void f_4(){
    for(int i=x1;i<=x2;i++)
        for(int j=y1;j<=y2;j++)
            if(dp[i][j]==1)
                dp[i][j]=4;
}
void f_5(){
    for(int i=x1;i<=x2;i++)
        for(int j=y1;j<=y2;j++)
            if(dp[i][j]==2 || dp[i][j]==3)
                dp[i][j]=0;
}
void f_6(){
    for(int i=x1;i<=x2;i++)
        for(int j=y1;j<=y2;j++)
            if(dp[i][j]==2 || dp[i][j]==3 || dp[i][j]==4)
                dp[i][j]=0;
}
void f_7(){
    for(int i=x1;i<=x2;i++)
        for(int j=y1;j<=y2;j++)
            if(dp[i][j]==0)
                dp[i][j]=1;
}