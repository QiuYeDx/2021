#include <iostream>
#include <algorithm>
using namespace std;
struct coin{
    int m,v;
}a[110];
bool cmp(coin x, coin y){
    return x.v*y.m > y.v*x.m;
}
int main() {
    int n,t,c,i;
    float ans=0;
    scanf("%d%d",&n,&t);
    c=t;    //背包的剩余容量
    for(int i=0;i<n;i++)
        scanf("%d%d",&a[i].m,&a[i].v);
    sort(a,a+n,cmp);
    for( i=0;i<n;i++){
        if(a[i].m>c)
            break;
        c-=a[i].m;
        ans+=a[i].v;
    }
    if(i<n)
        ans+=1.0*c/a[i].m*a[i].v;
    printf("%.2lf",ans);
    return 0;
}
