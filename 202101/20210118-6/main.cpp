#include <cstdio> //P1789 【Mc生存】插火把

int main() {
    int yn[110][110]={0};  //0表示会生成怪物
    int n,m,k;
    int sum=0;

    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<m;i++)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        yn[x][y]=1;
        for(int j=1;j<=2 && x-j>0;j++)
            yn[x-j][y]=1;
        for(int j=1;j<=2 && y-j>0;j++)
            yn[x][y-j]=1;
        for(int j=1;j<=2 && x+j<=n;j++)
            yn[x+j][y]=1;
        for(int j=1;j<=2 && y+j<=n;j++)
            yn[x][y+j]=1;
        if(x-1>0 && y-1>0)
            yn[x-1][y-1]=1;
        if(x-1>0 && y+1<=n)
            yn[x-1][y+1]=1;
        if(x+1<=n && y-1>0)
            yn[x+1][y-1]=1;
        if(x+1<=n && y+1<=n)
            yn[x+1][y+1]=1;
    }
    for(int i=0;i<k;i++)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        for(int x1=x-2;x1>0 && x1<=n && x1<=x+2;x1++)
            for(int y1=y-2;y1>0 && y1<=n && y1<=y+2;y1++)
                yn[x1][y1]=1;
    }
    for(int x=1;x<=n;x++)
        for(int y=1;y<=n;y++)
            if(yn[x][y]==0)
                sum++;
    printf("%d",sum);
    return 0;
}
