#include <stdio.h> //1988年世界人口为50亿，按年增长率11%计算，从哪一年开始世界人口数超过100亿？

int main() {
    double sum=50;
    int i=0;
    while(1)
    {
        i++;
        sum*=1.11;
        if(sum>=100)
        {
            printf("%d",1988+i);
            break;
        }
    }
    return 0;
}
