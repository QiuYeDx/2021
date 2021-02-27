#include <iostream> //P3799 妖梦拼木棒
#define MOD 1000000007LL
using namespace std;
long long num[5010],ans;

int main() {
    long long n,i,j,tmp;

    cin >> n;
    for(int i=0;i<n;i++){
        scanf("%d",&tmp);
        num[tmp]++;
    }
    for(i=2;i<5001;i++)
        if(num[i]>=2)
            for(j=1;j<=i/2;j++){
                long long k=i-j;
                if(num[j]>=1 && num[k]>=1)
                    if(j!=k)
                        ans+=num[i]%MOD*(num[i]-1)%MOD/2*num[k]%MOD*num[j]%MOD;
                    else
                        ans+=num[i]%MOD*(num[i]-1)%MOD/2*num[j]%MOD*(num[j]-1)%MOD/2;
            }
    ans%=MOD;
    cout << ans;
    return 0;
}
