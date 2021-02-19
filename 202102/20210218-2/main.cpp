#include <iostream> //P1781 宇宙总统 高精度数字用string储存来排序/自定义比较器
#include <algorithm>
using namespace std;
int const MAXN = 30;
struct node{
    int id;
    string x;
}s[MAXN];
bool cmp(node a, node b)
{
    if(a.x.length() != b.x.length())
        return a.x.length() > b.x.length();
    else
        return a.x > b.x;
}
int main() {
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        s[i].id=i+1;
        cin >> s[i].x;
    }
    sort(s,s+n,cmp);
    cout << s[0].id << endl << s[0].x;

    return 0;
}
