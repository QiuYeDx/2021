#include <bits/stdc++.h>
using namespace std;
class Worker{
public:
    string name,address;
    long int salary;
    virtual void printInfo(){}
    virtual void getSalary(){}
};
class AWorker:public Worker{
public:
    AWorker(const string& s_name,const string& s_address,long int x){
        name=s_name;
        address=s_address;
        salary=x;
    }
    void printInfo(){
        printf("name:%s,address:%s,salary:%ld\n",name.c_str(),address.c_str(),salary);
    }
};
class BWorker:public Worker{
public:
    BWorker(const string& s_name,const string& s_address,long int total,long int eve){
        name=s_name;
        address=s_address;
        totalNumbers=total;
        every=eve;
    }
    void getSalary(){
        salary=totalNumbers*every;
    }
    void printInfo(){
        printf("name:%s,address:%s,salary:%ld\n",name.c_str(),address.c_str(),salary);
    }
private:
    long int totalNumbers,every;
};
class CWorker:public Worker{
public:
    CWorker(const string& s_name,const string& s_address,long int total,long int eve){
        name=s_name;
        address=s_address;
        totalHours=total;
        every=eve;
    }
    void getSalary(){
        salary=totalHours*every;
    }
    void printInfo(){
        printf("name:%s,address:%s,salary:%ld\n",name.c_str(),address.c_str(),salary);
    }
private:
    long int totalHours,every;
};
int main() {
    Worker* pt;
    long int n,tmp_0,tmp_1,tmp_2;
    string tmp_name,tmp_add;
    cin >> n;
    while(n--){
        cin >> tmp_name >> tmp_add >> tmp_0;
        AWorker a(tmp_name,tmp_add,tmp_0);
        pt=&a;
        pt->printInfo();

        cin >> tmp_name >> tmp_add >> tmp_1 >> tmp_2;
        BWorker b(tmp_name,tmp_add,tmp_1,tmp_2);
        pt=&b;
        pt->getSalary();
        pt->printInfo();

        cin >> tmp_name >> tmp_add >> tmp_1 >> tmp_2;
        CWorker c(tmp_name,tmp_add,tmp_1,tmp_2);
        pt=&c;
        pt->getSalary();
        pt->printInfo();
    }
    return 0;
}
