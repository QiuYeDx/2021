#include <bits/stdc++.h>
using namespace std;
class Vehicle{
public:
    virtual void Run(){
        cout << "vehicle run!" << endl;
    }
};
class Bicycle:virtual public Vehicle{
public:
    void Run(){
        cout << "bicycle run!" << endl;
    }
};
class Motorcar:virtual public Vehicle{
public:
    void Run(){
        cout << "motorcar run!" << endl;
    }
};
class Motorbicycle:public Bicycle,public Motorcar{
public:
    void Run(){
        cout << "motorbicycle run!" << endl;
    }
};
void showV(Vehicle& pt){
    pt.Run();
}
int main() {
    Vehicle vehicle;
    Bicycle bicycle;
    Motorcar motorcar;
    Motorbicycle motorbicycle;
    vehicle.Run();
    bicycle.Run();
    motorcar.Run();
    motorbicycle.Run();
    showV(vehicle);
    showV(bicycle);
    showV(motorcar);
    showV(motorbicycle);
    return 0;
}
