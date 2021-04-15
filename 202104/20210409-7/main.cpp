#include <bits/stdc++.h>    //P1996 约瑟夫问题
using namespace std;
queue<int> q;
int n,k;
int main() {
    cin >> n >> k;
    int i;
    for(int i=1;i<=n;i++)
        q.push(i);  //初始加入小朋友
        while(q.size()!=1){
            for(i=1;i<k;i++){
                q.push(q.front());
                q.pop();
            }
            printf("%d ",q.front());
            q.pop();
        }
        printf("%d",q.front());
        q.pop();
    return 0;
}
