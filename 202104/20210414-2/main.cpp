#include <bits/stdc++.h>
using namespace std;
class Set{
public:
    Set(int _max){
        len=0;
        max=_max-1;
        first=new int[max];
    }
    Set(Set& tmp){
        len=tmp.len;
        max=tmp.max;
        first=new int[max];
        for(int i=0;i<=len;i++)
            first[i]=tmp[i];
    }
    void add(int x){
        if(len==max){
            int *pt=new int[len+1];
            max++;
            for(int i=0;i<=len;i++){
                pt[i]=first[i];
            }
            delete []first;
            len++;
            first=pt;
        }
        else
            first[len++]=x;
    }
    int &operator[](int i){
        return first[i];
    }
    ~Set(){
        delete []first;
    }
private:
    int * first;
    int len;
    int max;
};
int main() {
    Set set(100);
    set.add(5);
    cout << set[0] << endl;
    Set set_b(set);
    cout << set_b[0] << endl;
    return 0;
}
