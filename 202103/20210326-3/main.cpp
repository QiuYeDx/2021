#include <iostream> //P1678 烦恼的高考志愿 二分查找(非单调,需加个向左/右逼近的if判断)
#include <cstdio>
#include <algorithm>
using namespace std;
#define maxn 100010
int ddl[maxn],stu[maxn],m,n;
long long sum=0;
int main() {
    cin >> m >> n;
    for(int i=0;i<m;i++)
        scanf("%d",&ddl[i]);
    for(int i=0;i<n;i++)
        scanf("%d",&stu[i]);
    sort(ddl,ddl+m);
    for(int i=0;i<n;i++)
    {
        int L=0,R=m-1,ans=abs(ddl[m-1]-stu[i]),mid;
        while(L<=R){
            if(abs(ddl[mid=(L+R)>>1]-stu[i])<ans)
            {
                ans=abs(ddl[mid]-stu[i]);
                if(ddl[mid]>stu[i])
                    R=mid-1;
                else
                    L=mid+1;
            }
            else
                if(ddl[mid]>stu[i])
                    R=mid-1;
                else
                    L=mid+1;
        }
        sum+=ans;
    }
    printf("%lld",sum);
    return 0;
}
