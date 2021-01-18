#include <cstdio>  //P1075 [NOIP2012 普及组] 质因数分解 AC 100%

int main() {
    long long num;

    scanf("%lld",&num);
    for(int i=2;1;i++)
    {
        if(num%i==0)
        {
            printf("%lld",num/i);
            break;
        }
    }
    return 0;
}
