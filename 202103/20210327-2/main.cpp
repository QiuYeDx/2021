#include <iostream> //P2392 kkksc03考前临时抱佛脚 深度优先搜索 贪心 递归 背包问题
#include <algorithm>
using namespace std;
int nowtime,maxtime,sum;    //子集中的时间和、最大合法时间和、该课作业总时长
int ans,maxdeep;    //答案,最深递归层数限制(作业数量)
int s[4],a[21]; //每科作业数量,每个作业的耗时
void dfs(int x){
    if(x > maxdeep){    //所有作业枚举完毕,达到了最大递归层数
        maxtime = max(maxtime,nowtime); //如果解更优,更新答案
        return;
    }
    if(nowtime + a[x] <= sum / 2){  //如果放入这个作业是合法的,选择它
        nowtime += a[x];    //增加子集中这道题目的时间
        dfs(x+1);   //下一层递归
        nowtime-=a[x];  //去掉子集中这道题目的时间
    }
    dfs(x+1);   //不选这道题目，直接进行下一层递归
}
int main() {
    cin >> s[0] >> s[1] >> s[2] >> s[3];
    for(int i=0;i<4;i++){   //四种科目
        nowtime = 0;
        maxdeep = s[i];
        sum=0;  //别忘了每次换科目都要初始化
        for(int j=1;j <= s[i];j++){
            cin >> a[j];
            sum+=a[j];  //记录这科作业总耗时
        }
        maxtime = 0;
        dfs(1); //开始枚举第一个题目
        ans += (sum - maxtime); //加上答案
    }
    cout << ans;
    return 0;
}
