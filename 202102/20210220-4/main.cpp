#include <iostream> //P2241 统计方形（数据加强版）key4
#include <algorithm>
using namespace std;
typedef long long LL;
int main() {
    LL n, m, squ = 0, rec;
    scanf("%lld%lld", &n, &m);
    for(LL a=1;a<=min(m, n);a++)
        squ+=(n-a+1)*(m-a+1);   //n*m中含有squ个a*a的矩形
    rec=n*(n+1)*m*(m+1)/4 - squ;
    printf("%lld %lld",squ,rec);
    return 0;
}
