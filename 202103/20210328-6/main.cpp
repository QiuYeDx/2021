#include <iostream> //右值引用 探索
#include <string>
using namespace std;
class Birth{
public:

    Birth()=default;
    Birth(int y,int m,int d):year(y),month(m),day(d){
    }
    Birth(Birth& birth){
        year=birth.year;
        month=birth.month;
        day=birth.day;
    }
    void setBirth(int y,int m,int d){
        year=y;
        month=m;
        day=d;
    }
    void showBirth() const{             //const
        printf("出生日期: %d年%d月%d日\n",year,month,day);
    }
private:
    int year,month,day;
};
class People{
public:
    People()=default;
    People(int num,string &s,string &i,Birth &bir):birth(bir),sex(s),number(num),id(i){
    }
    People(People& people){
        number=people.number;
        sex=people.sex;
        id=people.id;
        birth=people.birth;
    }
    void showPeople() const{                    //const
        cout << "编号: " << number << endl;
        cout << "性别: " << sex << endl;
        cout << "ID : " << id << endl;
        birth.showBirth();
    }
    void setPeople(int num,string &s,string &i,Birth&& bir){
        number=num;
        sex=s;
        id=i;
        birth=bir;
    }
private:
    int number;
    string sex;
    string id;
    Birth birth;
};
int main() {
    People a;
    int number,y,m,d;
    string s1,s2;
    cin >> number >> s1 >> s2 >> y >> m >> d;
    a.setPeople(number,s1,s2,Birth(y,m,d));
    a.showPeople();
    return 0;
}
