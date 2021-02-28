#include <iostream> //P1255 数楼梯 简单递归+高精度数组加法(大整数类+重载运算符)
#include <algorithm>

using namespace std;
int N;

struct Bigint {
    int n[1700];
    int len;

    void print() {
        for (int i = max(len, 1); i >= 1; i--)
            printf("%d", n[i]);
    }

    void flatten(int L) {
        len = L;
        for (int i = 1; i <= len; i++)
            n[i + 1] += n[i] / 10, n[i] %= 10;
        for (; !n[len];)
            len--;
    }
};

Bigint operator+(Bigint a, Bigint b) {
    Bigint c={0};   //必须初始化！！！否则c.n[i+1]的值是无意义的！！！错在这儿了555T_T
    int len = max(a.len, b.len);
    for (int i = 1; i <= len; i++)
        c.n[i] += a.n[i] + b.n[i];
    c.flatten(len + 1);
    return c;
}

Bigint a[5002]; //64MB
int main() {
    a[1].len = 1, a[2].len = 1;
    a[1].n[1] = 1, a[2].n[1] = 2;
    cin >> N;
    for (int i = 3; i <= N; i++)
        a[i] = a[i - 1] + a[i - 2];
    a[N].print();
    return 0;
}
