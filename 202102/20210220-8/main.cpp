#include <iostream> //P1143 进制转换 n进制数转m进制数(2<=n,m<=16)
#include <string>
#include <cmath>
using namespace std;
int n, m, num,len_a,tmp;
char ys[1000000000];    //用数组存储余数和最后一个商（倒着输出就是最终结果）*也可以不用存储，求的时候直接输出
string a, b;
int size(char ch)   //把某一位上用n进制表示的值转换为十进制
{
    if('0'<=ch && ch<='9')
        return ch-48;
    else
        return ch-55;
}
void tentom(char *ch)   //把某一位上用十进制表示的值转换为m进制
{
    if(*ch>=10)
        *ch+=55;
    else
        *ch+=48;
}
int main() {
    cin >> n >> a >> m;
    len_a=a.length();
    for(int i=len_a-1;i>=0;i--)
        num+=(int)pow(n,len_a-1-i)*size(a[i]);
    int i;
    for(i=0;;i++)
    {
        ys[i]=char(num%m);
        num/=m;
        if(num<m)
        {
            ys[i+1]=(char)num;
            break;
        }
    }
    i++;
    for(int j=0;j<=i;j++)
        tentom(&ys[j]);
    for(int k=i;k>=0;k--)
        printf("%c",ys[k]);
    return 0;
}
