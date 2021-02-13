#include <cstdio>  //page113 T7-7（1）
void emmm(void)
{
    int n;
    scanf("%d",&n);
    if(n!=0)
    {
        emmm();
        printf("%d ",n);
    }
}
int main() {
    emmm();
    return 0;
}
