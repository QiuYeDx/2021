#include <bits/stdc++.h>
using namespace std;
class BaseClass{
public:
    BaseClass(){cout << "Construct BaseClass" << endl;}
    ~BaseClass(){cout << "Destruct BaseClass" << endl;}
private:
    int Number;
};
class DerivedClass:public BaseClass{
public:
    DerivedClass(int a,int b){cout << "Construct DerivedClass" << endl;}
    DerivedClass(){cout << "Construct DerivedClass" << endl;}
    ~DerivedClass(){cout << "Destruct DerivedClass" << endl;}
private:
    BaseClass basesss;
};
int main() {
    DerivedClass obj(1,2);
    return 0;
}
