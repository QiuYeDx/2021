#include <cstdio>

int main() {
    long long num;

    scanf("%lld",&num);
    if(num<0)
    {
        printf("-");
        num=0-num;
    }
    else if(num==0)
    {
        printf("0");
        return 0;
    }
    while(1)
    {
        if(num%10!=0)
        {
            printf("%lld",num%10);
            num/=10;
            break;
        }
        else
            num/=10;
    }
    while(num>0)
    {
        printf("%lld",num%10);
        num/=10;
    }
    return 0;
}
