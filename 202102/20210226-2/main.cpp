#include <iostream> //P1618 三连击（升级版）(重现) 排列枚举 时间复杂度O(9!)还算可以
#include <algorithm>

using namespace std;
int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

int main() {
    long long A, B, C, x, y, z, cnt = 0;
    cin >> A >> B >> C;
    do {
        x = a[1] * 100 + a[2] * 10 + a[3];
        y = a[4] * 100 + a[5] * 10 + a[6];
        z = a[7] * 100 + a[8] * 10 + a[9];
        if (x * B == y * A && z * B == y * C)
            printf("%lld %lld %lld\n", x, y, z), cnt++;
    } while (next_permutation(a+1, a + 10));
    if (!cnt)
        puts("No!!!");
    return 0;
}
