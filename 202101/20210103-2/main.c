#include <stdio.h>  //高精度加法

int main() {
    char num1[600]={0};
    char num2[600]={0};
    int num[600]={0};
    int numa[600]={0};
    int numb[600]={0};
    int jw[600]={0};
    int i1,i2,i_max;

    for(i1=1;scanf("%c",&num1[i1])!=EOF && num1[i1]!='\n';i1++);
    for(i2=1;scanf("%c",&num2[i2])!=EOF && num2[i2]!='\n';i2++);
    i1--;
    i2--;
    for(int i=1;i<=i1;i++)
        numa[i]=num1[i1-i+1]-48;
    for(int i=1;i<=i2;i++)
        numb[i]=num2[i2-i+1]-48;

    for(int i=1;i<=(i1>i2?i1:i2);i++)
    {
        num[i]=(numa[i]+numb[i]+jw[i])%10;
        jw[i+1]=(numa[i]+numb[i]+jw[i])/10;
    }
    num[(i1>i2?i1:i2)+1]=jw[i1>i2?i1+1:(i2+1)];
    if(num[i1>i2?i1+1:(i2+1)]!=0)
        i_max=i1>i2?i1+1:(i2+1);
    else
        i_max=i1>i2?i1:i2;
    for(int i=i_max;i>=1;i--)
        printf("%d",num[i]);
    return 0;
}
