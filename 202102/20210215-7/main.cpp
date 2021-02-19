#include <iostream> //P1923 【深基9.例4】求第 k 小的数 PS:不能用cin>>读入，否则会超时
using namespace std;
int num[5000001],ans=0,k;
void qqsort(int a[],int l,int r)
{
    if(l==r){
        ans=a[l];   //区间长度为1时，记录答案
        return;
    }
    int i=l, j=r, tmp, flag=a[(l+r)/2];
    do{
        while(a[i]<flag)i++;
        while(a[j]>flag)j--;
        if(i<=j){
            tmp=a[i]; a[i]=a[j]; a[j]=tmp;
            i++;j--;
        }
    }while(i<=j);
    if(k<=j)qqsort(a,l,j);  //第k小的数字在左区间
    else if(i<=k)qqsort(a,i,r); //在右区间
    else qqsort(a,j+1,i-1); //eg: j=4,i=6,k=5这种情形
}

int main() {
    int n;
    cin >> n >>k;
    for(int i=0;i<n;i++)
        scanf("%d",&num[i]);
    qqsort(num,0,n-1);
    cout << ans;
    return 0;
}
