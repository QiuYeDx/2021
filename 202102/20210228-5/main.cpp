#include <iostream> //P1928 外星密码    字符串 递归 分治 模拟 (标程)
#include <cstring>

using namespace std;

string expand() {
    string s, X;
    char c;
    int D;
    while (cin >> c) {
        if (c == '[') {
            cin >> D;
            X = expand();
            while (D--)s += X;
        } else if (c == ']')
            return s;
        else s += c;
    }
    return s;
}

int main() {
    cout << expand();
    return 0;
}
