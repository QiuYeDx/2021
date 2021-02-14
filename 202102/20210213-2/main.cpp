#include <iostream> //P1563 [NOIP2016 提高组] 玩具谜题  模拟/高性能 P120
#include <string>
using namespace std;
const int MAXN = 1e6 + 5;
struct node {
    int head;
    string name;
}a[MAXN];
int n,m,x,y;
int main() {
    cin >> n >> m;
    for(int i=0;i<n;i++)
        cin >> a[i].head >> a[i].name;
    int now=0;
    for(int i=1;i<=m;i++)
    {
        cin >> x >> y;
        if(a[now].head ^ x)
            now=(now+y)%n;
        else
            now=(now+n-y)%n;
    }
    cout << a[now].name << endl;
    return 0;
}
