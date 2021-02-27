#include <iostream> //P1157 组合的输出
#include <cstdio>

using namespace std;
int a[30];

int main() {
    int n, r;
    cin >> n >> r;
    for (int S = (1 << n) - 1; S >= 0; S--) {   //从全集枚举到0
        int cnt = 0;
        for (int i = 0; i < n; i++)
            if (S & (1 << i))
                a[cnt++] = i;   //分离记录每一位
        if (cnt == r) {
            for (int i = r - 1; i >= 0; i--)
                printf("%3d", n - a[i]);    //因为用高位表示1，所以需要反过来输出
            puts(" ");
        }
    }
    return 0;
}