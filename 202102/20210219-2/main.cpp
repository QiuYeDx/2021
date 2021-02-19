#include <iostream> //P1152 欢乐的跳 PS:重在分析、简化问题 20210219 01；48 over
#include <algorithm>    //只需要保证相邻差最小的是1，最大的是n-1，且差无查重即可。比暴力模拟好。
#include <cstdlib>
using namespace std;
int const MAXN = 1010;
int s[MAXN],d[MAXN];
int main() {
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> s[i];
    for(int i=0;i<n-1;i++)
        d[i]=abs(s[i+1]-s[i]);
    sort(d,d+n-1);
    if(d[0]==1 && d[n-2]==n-1)
    {
        int ans;
        ans = unique(d,d+n-1)-d;
        if(ans==n-1)
            cout << "Jolly";
        else
            cout << "Not jolly";
    }
    else
        cout << "Not jolly";
    return 0;
}
