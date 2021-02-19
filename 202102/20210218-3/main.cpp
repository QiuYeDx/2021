#include <iostream> //P2676 [USACO07DEC]Bookshelf B
#include <algorithm>
using namespace std;
int N,B;
int s[20010];

int main() {
    int sum=0,ans;

    cin >> N >> B;
    for(int i=0;i<N;i++)
        cin >> s[i];
    sort(s,s+N,greater<>()); //从大到小排序
    for(ans=0;sum<B;ans++)
        sum+=s[ans];
    cout << ans;
    return 0;
}
