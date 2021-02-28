#include <iostream> //P2437 蜜蜂路线    封装大整数类+重载运算符>>高精度加法+简单递推
#include <algorithm>

using namespace std;

struct Bigint {
    int a[1668], len;

    void flatten(int L) {
        len = L;
        for (int i = 1; i <= len + 1; i++)
            a[i + 1] += a[i] / 10, a[i] %= 10;
        for (; !a[len];)
            len--;
    }

    void print() {
        for (int i = max(len,1); i > 0; i--)
            printf("%d", a[i]);
    }
} dp[1010] = {0};

Bigint operator+(Bigint a, Bigint b) {
    Bigint c = {0};
    int len = max(a.len, b.len);
    for (int i = 1; i <= len; i++)
        c.a[i] = a.a[i] + b.a[i];
    c.flatten(len+1);
    return c;
}

int main() {
    int n, m;
    cin >> m >> n;
    dp[m].a[1] = 1, dp[m].len = 1;
    for (int i = m + 1; i <= n; i++)
        dp[i] = dp[i - 1] + dp[i - 2];
    dp[n].print();
    return 0;
}
