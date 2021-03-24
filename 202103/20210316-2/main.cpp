#include <iostream> //P3817 小A的糖果 模拟 贪心  NICE~ AC 1/1
using namespace std;
int a[100010],n,x;
long long sum=0;
int main() {
    cin >> n >> x;
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(int i=0;i<n-1;i++)
    {
        if(a[i]+a[i+1]>x)
        {
            if(x>=a[i]) //只需要在a[i+1]上做减法
            {
                sum+=a[i]+a[i+1]-x;
                a[i+1]-=a[i]+a[i+1]-x;
            }
            else
            {
                sum+=a[i]+a[i+1]-x;
                a[i+1]=0;
                //a[i]-=a[i]+a[i+1]-x-a[i+1];其实不用管了hhh
            }
        }
    }
    cout << sum;
    return 0;
}
