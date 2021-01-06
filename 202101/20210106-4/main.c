#include <stdio.h>//输出8位生日各位数字之和

int main() {
    int sum=0;
    long num;

    scanf("%ld",&num);
    for(int i=1;i<=8;i++)
    {
        sum+=num%10;
        num/=10;
    }
    printf("%d",sum);
    return 0;
}
