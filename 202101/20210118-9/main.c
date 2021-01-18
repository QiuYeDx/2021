#include <stdio.h>  //高精度加法 P1601 A+B Problem（高精）
#include <string.h> //不容易……洛谷能AC的版本。(Linux评测机能过的版本)
int main() {
    char num1[600]={0};
    char num2[600]={0};
    int num[600]={0};
    int numa[600]={0};
    int numb[600]={0};
    int jw[600]={0};
    int i1,i2,i_max;

    fgets(num1+1,610,stdin);
    fgets(num2+1,610,stdin);
    int i;
    for(i=1;num1[i]<='9'&&num1[i]>='0';i++);
    num1[i]='\0';
    for(i=1;num2[i]<='9'&&num2[i]>='0';i++);
    num2[i]='\0';
    i1=strlen(num1+1);
    i2=strlen(num2+1);

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