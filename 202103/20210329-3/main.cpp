#include <iostream>
using namespace std;
class Basic{
public:
    void multiplyValue(){
        cout << x*y << endl;
    }
    void getValue(){
        int x,y;
        cin >> x >> y;
        this->x=x;
        this->y=y;
    }
protected:
    int x,y;
};
class Derived:public Basic{
public:
    void addValue(){
        cout << x+y << endl;
    }
};
int main() {
    Derived derived;
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        derived.getValue();
        derived.multiplyValue();
        derived.addValue();
    }
    return 0;
}
