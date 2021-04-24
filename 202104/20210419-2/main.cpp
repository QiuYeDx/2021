#include<iostream>
#include<cstring>
using namespace std;
class Date                  //构建日期类
{
private:
    int m_year;
    int m_month;
    int m_day;
public:
    Date(int year,int month,int day);
    ~Date();
    void displayDate()       //定义内联函数展示日期
    {
        cout<<"出生日期:"<<m_year<<"."<<m_month<<"."<<m_day<<endl;
    }
};

Date::Date(int year,int month,int day)
{
    m_year = year;
    m_month = month;
    m_day = day;
}

Date::~Date(){}

class People    //构建People类，其中成员数据birthday是一个日期类的对象
{
private:
    char m_name[11];
    char m_number[7];
    char m_sex[4];
    char m_id[16];
    Date birthday;
public:
    void display()      //用内联函数展示调用，其中调用了displayDate函数
    {
        printf("姓名：%s\n编号：%s\n性别：%s\n身份证号:%s\n",m_name,m_number,m_sex,m_id);
        birthday.displayDate();
    }
    People(string name,string number, string sex,string id,int year,int month,int day);
    ~People();
    bool operator==(const People& p)
    {
        return !strcmp(this->m_id,p.m_id);
    }
    void operator-(const People& p)
    {
        (*this) = p;
    }
};
People::People(string name,string number,string sex,string id,int year,int month,int day):birthday(year,month,day)
{
    strcpy(m_name,name.c_str());
    strcpy(m_number,number.c_str());
    strcpy(m_sex,sex.c_str());
    strcpy(m_id,id.c_str());
    //m_sex[3] = '\0';
}
People::~People(){}
int main()
{
    //freopen("in.txt","r",stdin);
    string name;
    string number;
    string sex;
    string id;
    int year;
    int month;
    int day;
    cin>>name>>number>>sex>>id>>year>>month>>day;
    People p1(name,number,sex,id,year,month,day);
    //p1.display();
    People p2(name,number,sex,"002",year,month,day);
    if(p1==p2) cout<<"相等"<<endl;
    else cout<<"不等"<<endl;
    p2 - p1;
    if(p1==p2) cout<<"相等"<<endl;
    else cout<<"不等"<<endl;
}
