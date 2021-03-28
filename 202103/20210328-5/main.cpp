#include <iostream>
#include <string>
using namespace std;
int main() {
    string a,b;
    cin >> a >> b;
    a.insert(a.length(),b);
    cout << a;
    return 0;
}
