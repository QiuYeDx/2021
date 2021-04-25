#include <iostream>
using namespace std;
int a[3][3]={0};
int main() {
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            cin >> a[i][j];
    for(int j=0;j<3;j++)
    {
        int tmp=a[0][j];
        a[0][j]=a[j][0];
        a[j][0]=tmp;
    }
    {
        int tmp=a[1][2];
        a[1][2]=a[2][1];
        a[2][1]=tmp;
    }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
            cout << a[i][j] << " ";
        cout << endl;
    }

    return 0;
}
