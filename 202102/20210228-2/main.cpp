#include <iostream> //P1044 [NOIP2003 普及组] 栈 DP动态规划 ~自解~

using namespace std;
long long dp[20] = {0};

int main() {
    int n;
    cin >> n;
    dp[0] = 1, dp[1] = 1, dp[2] = 2;
    for (int i = 3; i <= n; i++)
        for (int j = 0; j < i; j++)
            dp[i] += dp[i - 1 - j] * dp[j];
    cout << dp[n];
    return 0;
}
