#include <bits/stdc++.h>
using namespace std;
class Vehicle{
public:
    void run(){
        cout << "vehicle run" << endl;
    }
    void stop(){
        cout << "vehicle stop" << endl;
    }
private:
    int Maxspeed,Weight;
};
class bicycle:virtual public Vehicle{
public:
private:
    int Height;
};
class motorcar:virtual public Vehicle{
public:
private:
    int SeatNum;
};
class motorbicycle:public bicycle,public motorcar{
public:
private:
};
int main() {
    motorbicycle  m;
    m.run();
    m.stop();
    return 0;
}
