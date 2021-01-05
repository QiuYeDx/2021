#include <stdio.h>

int main() {
    char num1[600]={0};
    char num2[600]={0};
    char num[600]={0};
    int jw[600]={0};
    int i1=1,i2=1,i,i_max,i_min;     //i1:A的位数  i2:B的位数

    for(;scanf("%c",&num1[i1])!=EOF && num1[i1]!='\n';i1++)  //读入A
        num1[i1]-=48;
    num1[i1]='\0';
    i1--;
    for(;scanf("%c",&num2[i2])!=EOF && num2[i]!='\n';i2++)  //读入B
        num2[i2]-=48;
    i2--;
    i_max=i1>i2?i1:i2;
    i_min=i1>i2?i2:i1;
    for(i=i_max;i>=0;i--)
    {
        if(i_max-i<=i_min)
        {
            num[i]=(num1[i]+num2[i]+jw[i])%10;
            if(i-1>=0)
                jw[i-1]=(num1[i]+num2[i]+jw[i])/10;
        }
        else
        {
            num[i]=num1[i]+jw[i];
        }
    }
    if(num[0]!=0)
        printf("%d",num[0]);
    for(int k=1;k<=i_max;k++)
        printf("%d",num[k]);
    return 0;
}
