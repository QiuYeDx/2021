#include <iostream>  //P5734 【深基6.例6】文字处理软件
#include <string>
using namespace std;
int main() {
    int n;
    cin >> n;
    string str0;
    cin >> str0;
    while(n--)
    {
        int ord;
        string str,str3,str4;
        cin >> ord;
        switch(ord)
        {
            case 1: cin >> str;
                    str0.append(str);
                    cout << str0 << endl;
                break;
            case 2: int a,b;
                    cin >> a >> b;
                    str0=str0.substr(a,b);
                    cout << str0 << endl;
                break;
            case 3: int c;
                    cin >> c >> str3;
                    str0.insert(c,str3);
                    cout << str0 << endl;
                break;
            case 4: cin >> str4;
                    cout << (int)str0.find(str4) << endl;
                break;
        }
    }
    return 0;
}
