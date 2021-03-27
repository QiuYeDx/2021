#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
#define eps 1e-4
double A,B,C,D;
double f(double x){
    return A*x*x*x+B*x*x+C*x+D;
}
int main() {
    cin >> A >> B >> C >> D;
    for(int i=-100;i<=100;i++){
        double L=i,R=i+1,mid;   //只是处理区间[L,R)上的根
        if(fabs(f(L))<eps)  //如果L是根，可以直接输出
            printf("%.2lf ",L);
        else if(fabs(f(R))<eps) //如果R是根，跳过
            continue;
        else if(f(L)*f(R)<0){   //在[L,R)上有根，执行二分
            while(R-L>eps){
                mid=(L+R)/2;
                if(f(mid)*f(R)>0)
                    R=mid;
                else
                    L=mid;
            }
            printf("%.2lf ",L);
        }
    }
    return 0;
}
