#include <iostream>     //P1765 手机
#include <string>
using namespace std;

int main() {
    string str;
    int sum=0;
    char ch;

    getline(cin,str);
    while(str.length()>1)
    {
        sscanf(str.c_str(),"%c",&ch);
        if(ch==' ' || ch=='a' || ch=='d' || ch=='g' || ch=='j' || ch=='m' || ch=='p' || ch=='t' || ch=='w')
        {
            sum++;
            str=str.substr(1,str.length()-1);
            continue;
        }
        if(ch=='b' || ch=='e' || ch=='h' || ch=='k' || ch=='n' || ch=='q' || ch=='u' || ch=='x')
        {
            sum+=2;
            str=str.substr(1,str.length()-1);
            continue;
        }
        if(ch=='c' || ch=='f' || ch=='i' || ch=='l' || ch=='o' || ch=='r' || ch=='v' || ch=='y')
        {
            sum+=3;
            str=str.substr(1,str.length()-1);
            continue;
        }
        if(ch=='s' || ch=='z')
        {
            sum+=4;
            str=str.substr(1,str.length()-1);
            continue;
        }
    }
    sscanf(str.c_str(),"%c",&ch);
    if(ch==' ' || ch=='a' || ch=='d' || ch=='g' || ch=='j' || ch=='m' || ch=='p' || ch=='t' || ch=='w')
        sum++;
    if(ch=='b' || ch=='e' || ch=='h' || ch=='k' || ch=='n' || ch=='q' || ch=='u' || ch=='x')
        sum+=2;
    if(ch=='c' || ch=='f' || ch=='i' || ch=='l' || ch=='o' || ch=='r' || ch=='v' || ch=='y')
        sum+=3;
    if(ch=='s' || ch=='z')
        sum+=4;
    cout << sum;
    return 0;
}
