#include <iostream> //P1002 [NOIP2002 普及组] 过河卒 二阶DP动态规划

using namespace std;
long long dp[21][21];   //(n, m)---(x, y)
struct Flag {
    int x, y;
}flag[9];
//{xh - 1, yh - 2, xh - 2, yh - 1, xh - 2, yh + 1, xh - 1, yh + 2, xh + 1, yh - 2, xh + 1, yh + 2,
//xh + 2, yh - 1, xh + 2, yh + 1, xh, yh}
int xb, yb, xh, yh;
bool yn(int,int);
int main() {
    cin >> xb >> yb >> xh >> yh;
    flag[0].x=xh-1,flag[0].y=yh-2;
    flag[1].x=xh-2,flag[1].y=yh-1;
    flag[2].x=xh-2,flag[2].y=yh+1;
    flag[3].x=xh-1,flag[3].y=yh+2;
    flag[4].x=xh+1,flag[4].y=yh-2;
    flag[5].x=xh+1,flag[5].y=yh+2;
    flag[6].x=xh+2,flag[6].y=yh-1;
    flag[7].x=xh+2,flag[7].y=yh+1;
    flag[8].x=xh,flag[8].y=yh;
    for (int i = 0; i <= xb; i++)
        for (int j = 0; j <= yb; j++) {
            if(i==0 && j==0)
            {
                dp[i][j]=1;
                continue;
            }
            if (i - 1 >= 0 && yn(i - 1, j))
                dp[i][j] += dp[i - 1][j];
            if (j - 1 >= 0 && yn(i, j - 1))
                dp[i][j] += dp[i][j - 1];
        }
    cout << dp[xb][yb];
    return 0;
}

bool yn(int x, int y){  //判断点是否在“马位”上
    for(int k=0;k<9;k++)
        if(x==flag[k].x && y==flag[k].y)
            return false;
    return true;
}