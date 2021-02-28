#include <iostream> //P1028 [NOIP2001 普及组] 数的计算 ~递归~
#include <cstring>

using namespace std;
int n, f[1010];

int sol(int x) {
    if (f[x] != -1)
        return f[x];
    int ans = 1;
    for (int i = 1; i <= x / 2; i++)
        ans += sol(i);
    return f[x] = ans;
}

int main() {
    cin >> n;
    memset(f, -1, sizeof(f));
    f[1] = 1;
    cout << sol(n) << endl;
    return 0;
}
