#include <iostream> //P1102 A-B数对 key2
#include <algorithm>
#include <cstdio>

#define maxn 200010
using namespace std;
typedef long long LL;
LL a[maxn];
int n, c;

int main() {
    scanf("%d %d", &n, &c);
    for (int i = 0; i < n; i++)
        scanf("%lld", &a[i]);
    sort(a, a + n);
    LL tot = 0;
    for (int i = 0, L = 0, R = 0; i < n; i++) {
        while (L < n && a[L] < a[i] + c)
            L++;
        while (R < n && a[R] <= a[i] + c)
            R++;
        tot += R - L;
    }
    printf("%lld",tot);
    return 0;
}
