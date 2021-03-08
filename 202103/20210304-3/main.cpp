#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
double sum;
long int n;
long long int t[1001];
double ans;
int main(int argc, const char * argv[])
{
    cin>>n;
    int x;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        t[i]=x*1001+i;
    }
    sort(t+1,t+1+n);
    for(int j=1;j<=n;j++)
    {
        cout<<t[j]%1001<<" ";
        sum+=t[j]/1001*(n-j);
    }
    cout<<endl;
    ans=sum/n;
    printf("%0.2lf",ans);
    return 0;
}