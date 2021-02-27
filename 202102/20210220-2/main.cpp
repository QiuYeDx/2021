#include <iostream> //P2241 统计方形（数据加强版）key1
#include <algorithm>
using namespace std;
typedef long long LL;
int main() {
    LL n, m, squ = 0, rec = 0;
    scanf("%lld%lld", &n, &m);
    for(LL x=0; x<=n; x++)
        for(LL y=0; y<=m; y++)
        {
            LL tmp=min(x, y)+min(y, n-x)+min(n-x, m-y)+min(m-y, x);
            squ+=tmp;
            rec+=n*m-tmp;
        }
    printf("%lld %lld",squ/4,rec/4);
    return 0;
}
