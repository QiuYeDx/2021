#include <cstdio>   //P1223 排队接水 贪心 快排
#include <algorithm>

using namespace std;
struct water {
    int num, time;
} p[1010];

bool cmp(water a, water b) {
    if (a.time != b.time)
        return a.time < b.time;
    return a.num < b.num;
}

int n;
long long sum = 0;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &p[i].time);
        p[i].num = i;
    }
    sort(p + 1, p + n + 1, cmp);
    for (int i = 1; i <= n; i++) {
        printf("%d ", p[i].num);
        sum += i * p[n - i].time;
    }
    printf("\n%.2lf\n", 1.0 * sum / n);
    return 0;
}
