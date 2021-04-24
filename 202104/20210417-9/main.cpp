#include <bits/stdc++.h>
using namespace std;
template <class T,class U>
class Pair{
public:
    Pair(T a,U b){
        t=a;
        u=b;
    }
    T getFirst()const{
        return t;
    }
    U getSecond()const{
        return u;
    }
private:
    T t;
    U u;
};
int main() {
    int n,tmp_int;
    double tmp_double;
    string tmp_str,type1,type2;
    string str_tmp;
    while(cin >> n){
        getline(cin,str_tmp);   //适应垃圾OJ系统
        //getchar();  //适应垃圾oj系统
        //getchar();  //适应垃圾oj系统
        for(int i=0;i<n;i++){
            cin >> type1 >> type2;
            if(type1=="int" && type2=="double"){
                cin >> tmp_int >> tmp_double;
                getline(cin,str_tmp);   //适应垃圾oj系统
                //getchar();  //适应垃圾oj系统
                //getchar();  //适应垃圾oj系统
                Pair<int,double>p1(tmp_int,tmp_double);
                printf("%lf %d\n",p1.getSecond(),p1.getFirst());
            }
            else if(type1=="int" && type2=="string"){
                cin >> tmp_int;
                getline(cin,tmp_str);   //适应垃圾oj系统
                Pair<int,string>p2(tmp_int,tmp_str);
                printf("%s %d\n",p2.getSecond().c_str(),p2.getFirst());
            }
            else if(type1=="double" && type2=="string"){
                cin >> tmp_double;
                getline(cin,tmp_str);   //适应垃圾oj系统
                Pair<double,string>p3(tmp_double,tmp_str);
                printf("%s %lf\n",p3.getSecond().c_str(),p3.getFirst());
            }
        }
    }
    return 0;
}
