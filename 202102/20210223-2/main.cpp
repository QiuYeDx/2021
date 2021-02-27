#include <iostream> //P1469 找筷子 其实就是求n个数的异或的和
using namespace std;

int main() {
    int ans,n,sum=0;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&ans);
        sum=sum^ans;
    }
    cout << sum;
    return 0;
}
