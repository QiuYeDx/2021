#include <iostream>
using namespace std;
int main() {
    int num;
    cin >> num;
    num=num>>1<<1;
    for(int j=0;j<32;j++)
        printf("%d",(num>>(31-j))&1);
    cout << endl << num;
    return 0;
}
