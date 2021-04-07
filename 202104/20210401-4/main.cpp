#include <bits/stdc++.h>
using namespace std;
struct Stu{
    int ID,fs;
    string name;
}stu[110];
int N,M;
/*bool cmp(Stu a,Stu b){
    return a.fs <= b.fs;
}
bool cmp2(Stu a,Stu b){
    return a.ID < b.ID;
}*/
void QNum(int l,int r){
    //sort(stu,stu+N,cmp);
    int n=0;
    for(int i=0;i<N;i++)
        if(stu[i].fs>=l && stu[i].fs<=r)
            n++;
    cout << n << endl;
}
void QName(int l,int r){
    //sort(stu,stu+N,cmp2);
    int flags=1;
    for(int i=0;i<N;i++){
        if(stu[i].fs>=l && stu[i].fs<=r){
            if(flags==0)
                cout << ' ';
            flags=0;
            cout << stu[i].name;
        }
    }
    cout << endl;
}
int main() {
    while(cin >> N){
        cin >> M;   //这样就RE？？？？
        for(int i=0;i<N;i++){
            cin >> stu[i].name >> stu[i].fs;
            stu[i].ID=i;
        }
        string zl;
        //cin >> M; 写到这儿就不RE了，而是WA？？？
        int l,r;
        for(int i=0;i<M;i++){
            cin >> zl >> l >> r;
            if(zl == "QNum") QNum(l,r);
            else if(zl == "QName") QName(l,r);
        }
    }
    return 0;
}
