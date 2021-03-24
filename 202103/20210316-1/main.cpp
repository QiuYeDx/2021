#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int n,n2,a1[10010],a2[10010],sum=0;
int main() {
    cin >> n;
    memset(a1,127,sizeof(a1));
    memset(a2,127,sizeof(a2));
    for(int i=0;i<n;i++)
        cin >> a1[i];
    sort(a1,a1+n);
    int i=0,j=0,k,w;
    for(k=1;k<n;k++){
        w=a1[i]<a2[j]?a1[i++]:a2[j++];
        w+=a1[i]<a2[j]?a1[i++]:a2[j++];
        a2[n2++]=w;
        sum+=w;
    }
    cout << sum;
    return 0;
}
