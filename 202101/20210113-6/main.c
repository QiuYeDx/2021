#include <stdio.h>

int main() {
    int t;
    long long n;
    long long scores;

    scanf("%d",&t);
    for(int i0=0;i0<t;i0++)
    {
        long long no[200010]={0};
        long long i_no=0;
        long long a[200010]={0};
        long long scores_max=0;
        int yn;
        scanf("%lld",&n);
        for(long long i=1;i<=n;i++)
            scanf("%lld",&a[i]);
        long long i;
        for(long long k=1;k<=n;k++)
        {
            yn=1;
            for(int i3=0;i3<i_no;i3++)
                if(k==no[i3])
                {
                    yn=0;
                    break;
                }
            if(yn==1)
            {
                i=k;
                scores = a[i];
                i = i + a[i];
                no[i_no] = i;
                i_no++;
                while (i <= n)
                {
                    scores += a[i];
                    i = i + a[i];
                    no[i_no]=i;
                    i_no++;
                }
                if (scores > scores_max)
                {
                    scores_max = scores;
                }
            }
        }
        printf("%lld\n",scores_max);
    }
    return 0;
}
