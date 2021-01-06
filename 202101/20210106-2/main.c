#include <stdio.h>
#include <math.h>

int judge(int num)
{
    for(int i=2;i<=sqrt(num);i++)
    {
        if(num%i==0)
            return 0;
    }
    return 1;
}

int main() {
    for(int i=10;i<100;i++)
        if(judge(i)==1)
            printf("%d\n",i);
    return 0;
}
