#include <iostream> //P1143 进制转换 n进制数转m进制数(2<=n,m<=16)
#include <string>
using namespace std;
int char_to_int(char a){
    return '0'<=a && a<='9'? a-'0' : 10+a-'A';
}
char int_to_char(int a){
    return a<=9? char('0'+a) : char(a-10+'A');
}
int main() {
    int output[33];
    int n, m, dec=0, num=0;
    string input;
    cin >> n >> input >> m;
    //原数转换为十进制
    for(int i=0;i<input.length();i++)   //可以简化为for(char i : input)
        dec = dec * n + char_to_int(input[i]);  //秦九韶算法
    //转换为m进制
    while(dec != 0)
        output[num++] = dec % m, dec/=m;
    //输出转换好的数字
    for(int i=num-1;i>=0;i--)
        cout << int_to_char(output[i]);
    cout << endl;
    return 0;
}
