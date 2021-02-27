#include <iostream> //P1706 全排列问题   极其简单直白的STL应用体验~
#include <algorithm>
using namespace std;
int a[10]={0,1,2,3,4,5,6,7,8,9};
int main() {
    int n;
    cin >> n;
    do{
        for(int i=1;i<=n;i++)
            printf("%5d",a[i]);
        puts("");
    }while(next_permutation(a+1,a+n+1));
    return 0;
}
