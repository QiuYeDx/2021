#include <iostream> //测试sort
#include <algorithm>
using namespace std;
int main() {
    int a[10]={10,9,8,7,6,5,4,3,2,1};
    int *pt=a;
    pt+=9;
    cout << *pt;
    return 0;
}
