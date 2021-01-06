#include <stdio.h>

int main() {
    double fz[30]={0};
    int fm[30]={0};
    double sum=0;

    fz[1]=2;
    fm[1]=1;
    sum+=fz[1]/fm[1];
    for(int i=2;i<=20;i++)
    {
        fz[i]=fz[i-1]+fm[i-1];
        fm[i]=(int)fz[i-1];
        sum+=fz[i]/fm[i];
    }
    printf("%.4f",sum);
    return 0;
}
