#include <iostream> //P2241 统计方形（数据加强版）key4
#include <algorithm>
using namespace std;
typedef long long LL;
int main() {
    LL n, m, squ = 0, rec = 0;
    scanf("%lld%lld", &n, &m);
    for(LL a=1;a<=n;a++)
        for(LL b=1;b<=m;b++)
            if(a == b)
                squ+=(n-a+1)*(m-b+1);
            else
                rec+=(n-a+1)*(m-b+1);
    printf("%lld %lld",squ,rec);
    return 0;
}
