#include <iostream>
#include <string>
using namespace std;
class Animal{
public:
    void toBark(){
        for(int i=0;i<3;i++)
            cout << bark;
        cout << endl;
    }
protected:
    string bark;
};
class Cat:public Animal{
public:
    Cat(){
        bark="miao";
    }
};
class Dog:public Animal{
public:
    Dog(){
        bark="wang";
    }
};
int main() {
    int n;
    Dog dog;
    Cat cat;
    cin >> n;
    for(int i=0;i<n;i++){
        int flag;
        cin >> flag;
        if(flag==1)
            dog.toBark();
        else
            cat.toBark();
    }
    return 0;
}
