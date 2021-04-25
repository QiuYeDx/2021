#include <bits/stdc++.h>    //P1135 奇怪的电梯 第一次自己写bfs~~~
using namespace std;        // 注意A可能等于B,到不了B时ans存的是-1，到了的话存的是答案-1，输出时需要+1
#define maxn 210
int k[maxn],N,A,B;
int ans[maxn];
queue<int> Q;
int main() {
    cin >> N >> A >> B;
    memset(ans,-1,sizeof ans);
    for(int i=1;i<=N;i++)
        scanf("%d",&k[i]);
    Q.push(A);
    while(!Q.empty()){
        int tmp_level=Q.front();
        if(tmp_level==B)
            break;
        int tmp_k=k[Q.front()],tmp_ans=ans[Q.front()];
        Q.pop();
        if(tmp_level+tmp_k<=N && ans[tmp_level+tmp_k]==-1){
            Q.push(tmp_level+tmp_k);
            ans[tmp_level+tmp_k]=tmp_ans+1;
        }
        if(tmp_level-tmp_k>0 && ans[tmp_level-tmp_k]==-1){
            Q.push(tmp_level-tmp_k);
            ans[tmp_level-tmp_k]=tmp_ans+1;
        }
    }
    if(A!=B)
        printf("%d",ans[B]==-1?-1:ans[B]+1);
    else
        printf("0");
    return 0;
}
