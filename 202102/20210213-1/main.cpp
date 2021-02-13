#include <iostream> //P2670 [NOIP2015 普及组] 扫雷游戏 AC~1
#define MAX 8
using namespace std;
char ch[102][102]={0};
int nn[8]={-1,-1,-1,0,0,1,1,1};
int mm[8]={-1,0,1,-1,1,-1,0,1};     //位置偏移量
void f_out(int i1,int i2)
{
    int n=0;
    for(int i=0;i<MAX;i++)
        if(ch[i1+nn[i]][i2+mm[i]]=='*')
            n++;
        cout << n;
}
int main() {
    int n,m;
    cin >> n >> m;
    getchar();
    for(int i1=1;i1<=n;i1++)
        for(int i2=1;i2<=m;i2++)
            cin >> ch[i1][i2];
    for(int i1=1;i1<=n;i1++)
    {
        for(int i2=1;i2<=m;i2++)
            if(ch[i1][i2]=='*')
                cout << ch[i1][i2];
            else
                f_out(i1,i2);
        cout << endl;
    }

    return 0;
}
