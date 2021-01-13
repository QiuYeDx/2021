#include <stdio.h>

int main() {
    long t,w,h,n,x;
    int i1,i2;

    scanf("%ld",&t);
    for(int i0=0;i0<t;i0++)
    {
        scanf("%ld %ld %ld",&w,&h,&n);
        i1=1;
        i2=1;
        while(w%2==0 && w!=0)
        {
            i1*=2;
            w/=2;
        }
        while(h%2==0 && h!=0)
        {
            i2*=2;
            h/=2;
        }
        x=i1*i2;
        if(x>=n)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
