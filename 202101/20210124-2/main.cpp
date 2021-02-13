#include <iostream>
#include <string>
#define MAXN 1024
using namespace std;
int n,x,ans;
struct student{
    int id;
    int academic,quality;
    double overall;
    student(int _id,int _ac,int _qu){   //初始化构造函数
        this->id = _id;
        this->academic = _ac;
        this->quality = _qu;
        this->overall = 0.7 * _ac + 0.3 * _qu;
    }   //这里的this->也可以省略
    student() {}    //没有传递参数的初始化构造函数
    int sum(){
        return academic + quality;
    }   //一般的成员函数
};
int is_excellent(student s){
    return s.overall >= 80 && s.sum() > 140;
}
int main() {
    cin >> n;
    for(int i=1;i<=n;i++){
        int tmp_id,tmp_ac,tmp_qu;
        cin >> tmp_id >> tmp_ac >> tmp_qu;
        student one_student(tmp_id,tmp_ac,tmp_qu);
        if(is_excellent(one_student))
            cout << "Excellent" << endl;
        else
            cout << "Not excellent" << endl;
    }
    return 0;
}
