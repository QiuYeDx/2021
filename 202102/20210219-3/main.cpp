#include <iostream> //P1068 [NOIP2009 普及组] 分数线划定
#include <algorithm>
#include <cmath>
using namespace std;
int const MAXN = 5010;
struct man{
    int k, s;   //k为报名号，s为成绩
}a[MAXN];
int n, m, line, low,ans;
bool cmp(man x, man y)
{
    if(x.s != y.s)
        return x.s > y.s;
    else
        return x.k < y.k;
}
int main() {
    cin >> n >> m;
    for(int i=0;i<n;i++)
        cin >> a[i].k >> a[i].s;
    sort(a,a+n,cmp);
    low = floor(m*1.5);
    ans = low;
    while(a[ans].s==a[low-1].s)     //易错点！（low是第low名，对应的是a[low-1]）
        ans++;
    cout << a[low-1].s << ' ' << ans << endl;
    for(int i=0;i<ans;i++)
        cout << a[i].k << ' ' << a[i].s << endl;
    return 0;
}
