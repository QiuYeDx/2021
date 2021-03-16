#include <iostream>
using namespace std;
int N,x,y,day;
double now;
int main() {
    cin >> N >> x >> y;
    now=N*2.0/3;
    for(day=2;day<=y;day++)
    {
        now=now*2.0/3;
        if(day==x)
            now+=N*1.0/2;
        if(now<N*1.0/32){
            printf("N0!\n%d %lf",day,now);
            return 0;
        }
    }
    printf("YE5!\n%lf",now);
    return 0;
}
