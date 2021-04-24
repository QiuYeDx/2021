#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    string type1,type2,tmp_str,str_tmp,tmp_int,tmp_double;
    cin >> n;
    getline(cin,str_tmp);   //适应垃圾oj系统
    for(int i=0;i<n;i++){
        cin >> type1 >> type2;
        if(type1=="int" && type2=="double"){
            cin >> tmp_int >> tmp_double;
            getline(cin,str_tmp);   //适应垃圾oj系统
            printf("%s %s\n",tmp_double.c_str(),tmp_int.c_str());
        }
        else if(type1=="int" && type2=="string"){
            cin >> tmp_int;
            getchar();
            getline(cin,tmp_str);   //适应垃圾oj系统
            printf("%s %s\n",tmp_str.c_str(),tmp_int.c_str());
        }
        else if(type1=="double" && type2=="string"){
            cin >> tmp_double;
            getchar();
            getline(cin,tmp_str);   //适应垃圾oj系统
            printf("%s %s\n",tmp_str.c_str(),tmp_double.c_str());
        }
    }
    return 0;
}
