#include <bits/stdc++.h>
using namespace std;
class a{
public:
    virtual void fun(){}
    int a;
};
class b:virtual public a{
public:
    void fun(){}
    int b;
};
class c:virtual public a{
public:
    void fun(){}
    int c;
};
class d:public b,public c{
public:
    void fun(){}
    virtual void fun2(){}
    int d;
};
int main() {
    cout << sizeof(a) << endl;
    cout << sizeof(b) << endl;
    cout << sizeof(c) << endl;
    cout << sizeof(d) << endl;
    return 0;
}
