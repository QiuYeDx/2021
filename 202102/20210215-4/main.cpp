#include <iostream> //P4924 [1007]魔法少女小Scarlet 模拟/暴力 自解 OJ不过……自己测试没问题
using namespace std;
struct B{
    int value;
    int x,y;    //第x列，第y行
}b[503*503];
int sum=1;

void revolve(int x,int y,int value,int z)   //旋转指定序号的数
{
    int rep;
    if(z)   //逆时针
        {
            rep=b[value].x;
            b[value].x=b[value].y+x-y;
            b[value].y=x+y-rep;
        }
    else    //顺时针
        {
            rep=b[value].x;
            b[value].x=x+y-b[value].y;
            b[value].y=y-x+rep;
        }
}
int main() {
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++,sum++)
        {
            b[sum].value=sum;
            b[sum].x=j;
            b[sum].y=i;
        }
    sum--;  //初始化完毕
    for(int i=0;i<m;i++)
    {
        int x,y,r,z;
        scanf("%d %d %d %d",&x,&y,&r,&z);
        for(int j=1;j<=sum;j++)
            if(x-r<=b[j].x && b[j].x<=x+r && y-r<=b[j].y && b[j].y<=y+r)
                revolve(x,y,j,z);
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            for(int k=1;k<=sum;k++)
                if(b[k].y==i && b[k].x==j && j<n)
                    printf("%d ",k);
                else if(b[k].y==i && b[k].x==j)
                    printf("%d",k);
        if(i<n)
            printf("\n");
    }
    return 0;
}
