#include <iostream> //P1177 【模板】快速排序 高性能/快排/模拟
using namespace std;
int N,a[100010]={0};
void qqsort(int n[],int l,int r)    //引入数组的地址
{
    int flag=n[(l+r)/2],j=l,k=r,rep;
    do{
        while(n[j]<flag)    //从左找比哨兵大的数
            j++;
        while(n[k]>flag)    //从右找比哨兵小的数
            k--;
        if(j<=k)    //交换
        {
            rep=n[j]; n[j]=n[k]; n[k]=rep;
            j++;k--;
        }
    }while(j<=k);
    if(l<k)qqsort(n,l,k);   //k,j容易弄反!!!
    if(j<r)qqsort(n,j,r);
}
int main() {
    cin >> N;
    for(int i=0;i<N;i++)
        cin >> a[i];
    qqsort(a,0,N-1);
    for(int i=0;i<N;i++)
        printf("%d ",a[i]);
    return 0;
}
