#include <stdio.h>

int main() {
    int n,t,x;
    int i1,i2;

    scanf("%ld",&t);
    for(int i0=0;i0<t;i0++)
    {
        i1=0;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            if(scanf("%d",&x),x==1)
                i1++;
        i2=n-i1;
        if(i1%2==1)
            printf("NO\n");
        else
            if(i2%2==0)
                printf("YES\n");
            else
                if(i1>0)
                    printf("YES\n");
                else
                    printf("NO\n");
    }
    return 0;
}
