#include <iostream>
#include <cmath>
int main()
{
    int t,a,b,c,d;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        scanf("%d%d%d%d",&a,&b,&c,&d);
        printf("%.3lf %d\n",hypot(b-a,d-c),(b-a)*(d-c));
    }
    return 0;
}