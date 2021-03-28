#include <iostream>
#include <string>
using namespace std;
class Employee{
public:
    Employee()=default;
    Employee(string &s1,string &s2,string &s3,string &s4):name(s1),address(s2),city(s3),postalcode(s4){
    }
    Employee(Employee & employee){
        name=employee.name;
        address=employee.address;
        city=employee.city;
        postalcode=employee.postalcode;
    }
    void change_name(string &s1){
        name=s1;
    }
    void display(){
        cout<<"name:"<<name<<endl;
        cout<<"address:"<<address<<endl;
        cout<<"city:"<<city<<endl;
        cout<<"postalcode:"<<postalcode<<endl;
    }
private:
    string name,address,city,postalcode;
};

int main() {
    string  n,a,c,p;
    int  i,j;
    Employee emp[5];
    for(i=0;i<5;i++)
    {
        cin>>n;
        cin>>a;
        cin>>c;
        cin>>p;
        emp[i]=Employee(n,a,c,p);
    }
    for(i=0;i<5;i++)
    {
        cout<<"Employee"<<i+1<<endl;
        emp[i].display();
    }
    return 0;
}
