#include <iostream> //P1803 凌乱的yyy / 线段覆盖 贪心www
#include <algorithm>

using namespace std;
int n, ans = 0, finish = 0;
struct contest {
    int l, r;
} con[1000010];

bool cmp(contest a, contest b) {
    return a.r <= b.r;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> con[i].l >> con[i].r;
    sort(con + 1, con + 1 + n, cmp);
    for (int i = 1; i <= n; i++)
        if (finish <= con[i].l)
            ans++, finish = con[i].r;
    cout << ans << endl;
    return 0;
}
