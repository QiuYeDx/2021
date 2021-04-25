#include <bits/stdc++.h>
using namespace std;
class Animal{
public:
    virtual void SetAge(int a){
        age=a;
    }
    virtual int GetAge(){
        return age;
    }
private:
    int age;
};
class dog:public Animal{
};
int main() {
    dog  d;
    d.SetAge(1);
    cout<<d.GetAge()<<endl;
    return  0;
    return 0;
}
