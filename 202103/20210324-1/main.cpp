#include <iostream> //P1102 A-B 数对
#include <cstdio>
#include <algorithm>
#define maxn 200010
using namespace std;
typedef long long LL;
LL a[maxn];
int n,c;
int main() {
    scanf("%d%d",&n,&c);
    for(int i=0;i<n;i++)
        scanf("%lld",&a[i]);
    sort(a,a+n);
    LL tot=0;
    for(int i=0;i<n;i++)
        tot+=upper_bound(a,a+n,a[i]+c)-lower_bound(a,a+n,a[i]+c);
    /*其实可以注意到lower_bound(a,a+n,a[i]+c+1)和upper(a,a+n,a[i]+c)是等价的*/
    printf("%lld",tot);
    return 0;
}
