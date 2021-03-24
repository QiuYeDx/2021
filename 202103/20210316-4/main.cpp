#include <iostream> //P2249 【深基13.例1】查找 二分思想入门 (待查询的数字有多个，输出最小的编号)
#define MAXN 1000010
using namespace std;
int a[MAXN],m,n,q;
int find(int x){
    int l=1,r=n+1;
    while(l<r){
        int mid=l+(r-l)/2;
        if(a[mid]>=x)r=mid;
        else l=mid+1;
    }
    if(a[l]==x)return l;
    else return -1;
}
int main() {
    cin >> n >> m;
    for(int i=1;i<=n;i++)
        cin >> a[i];
    for(int i=0;i<m;i++){
        cin >> q;
        cout << find(q) << " ";
    }
    return 0;
}
