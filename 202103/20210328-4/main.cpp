#include <iostream>
#include <string.h>
using namespace std;
int main() {
    char str_a[400]={0};
    char str_b[200]={0};
    cin >> str_a >> str_b;
    int len_a=strlen(str_a);
    int len_b=strlen(str_b);
    for(int i=0;i<len_b;i++)
        str_a[len_a+i]=str_b[i];
    str_a[len_a+len_b]=0;
    cout << str_a;
    return 0;
}
