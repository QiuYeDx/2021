#include <iostream> //P1059 [NOIP2006 普及组] 明明的随机数
#include <algorithm>
using namespace std;
int const MAXN = 1010;
int a[MAXN], ans[MAXN], n, cnt=0, tmp=-1;
int main() {
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> a[i];
    sort(a,a+n);
    for(int i=0;i<n;i++)
    {
        if(a[i]!=tmp)
            ans[cnt++]=a[i];
        tmp=a[i];
    }
    cout << cnt << endl;
    for(int i=0;i<cnt;i++)
        cout << ans[i] << ' ';
    return 0;
}
