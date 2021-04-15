#include <bits/stdc++.h>
using namespace std;
int n,q,opt,i,j,k;
int main() {
    cin >> n >> q;
    vector< vector<int> > locker(n+1);  //初始化，一共0到n号寄包柜
    while(q--){
        cin >> opt;
        if(opt==1){
            cin >> i >> j >> k;
            if(locker[i].size()<j+1)
                locker[i].resize(j+1);
            locker[i][j]=k;
        }
        else{
            cin >> i >> j;
            cout << locker[i][j] << endl;
        }
    }
    return 0;
}
