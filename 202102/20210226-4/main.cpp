#include <iostream> //P1088 [NOIP2004 普及组] 火星人 普通排列枚举,一遍过
#include <algorithm>

using namespace std;
int a[10005];

int main() {
    int N, M;
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        scanf("%d", &a[i]);
    for (int j = 0; j < M; j++) //or "M--",don't need 'j'.
        next_permutation(a + 1, a + N + 1);
    for (int j = 1; j <= N; j++)
        printf("%d ", a[j]);
    return 0;
}
