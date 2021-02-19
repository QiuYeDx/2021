#include <iostream> //P1116 车厢重组 ******求最少（相邻）交换次数，用冒泡排序
using namespace std;
int const MAXN = 10010;
int s[MAXN];
int N,sum=0;
int main() {
    int rep;
    cin >> N;
    for(int i=0;i<N;i++)
        cin >> s[i];
    for(;N>0;N--)
        for(int i=0;i<N-1;i++)
            if(s[i]>s[i+1])
            {
                rep=s[i];
                s[i]=s[i+1];
                s[i+1]=rep;
                sum++;
            }
    cout << sum;
    return 0;
}
