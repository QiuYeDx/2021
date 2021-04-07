#include<bits/stdc++.h>
using namespace std;
int ans=0,n;//记录答案与单词串数。
int maxn=0;//用于筛选最大值。
int len[25];//记录单词串长度。
char a[25][25];//记录单词矩阵。
int t[25];//记录单词出现次数，t<=2。
void dfs(int x)//话不多说，开搜！
{
    int y=0;//这个是用来判断是否能够在找到符合条件的要求(若y未改动，则说明搜索到了边界。)
    for(int i=1;i<=n;i++)
    {//遍历每一个单词串。
        if(t[i]<2)//保证次数未超，注意是小于２而不是小于等于（若等于则在之后再被用上使用数变为３，不符要求。)
            for(int j=0;j<len[x];j++)
            {//从０开始遍历每一个字母。
                if(a[i][0]==a[x][j])
                {//找到第一位与待接单词长龙某一位相等的单词，记下位置，扫。
                    if(j==0)
                    {
                        if(len[i]!=len[x]) continue;
                    }//判断一下，是否会重合。（其实有点小问题。）
                    int l=1;
                    bool b=false;
                    for(int h=j+1;h<len[x];h++)
                        if(a[x][h]!=a[i][l++])
                        {
                            b=true;
                            break;
                        }//若扫到一位不相同，则不合法。
                    if(b==1) continue;
                    else
                    {
                        y++;ans+=len[i]-l;t[i]++;
                        //改变y值，表示能找到，注意ans+的是len[i]-j 单词的第一位是从０开始的。
                        dfs(i);
                        y--;ans-=len[i]-l;t[i]--;//回溯一波。
                    }
                }
            }
    }
    if(y==0)
    {
        if(ans>maxn) maxn=ans;
        return;//若搜完，取最大值。
    }
}
int main()
{
    //freopen("dragon.in","r",stdin);
    //freopen("dragon.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%s",a[i]);
        len[i]=strlen(a[i]);
    }
    scanf("%s",a[n+1]);
    for(int i=1;i<=n;i++)
    {
        if(a[i][0]==a[n+1][0])
        {//注意题目条件，找到符合条件的龙头。
            ans=len[i];t[i]++;
            dfs(i);
            ans=0;t[i]--;
        }
    }
    printf("%d",maxn);
    return 0;
}