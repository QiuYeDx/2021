#include <iostream> //大一编程马拉松1-1
using namespace std;
int num[3][4]={0};
int D[4]={0};
int GetAnswer(int n1,int n2,int n3,int n4,int n5,int n6,int n7,int n8,int n9){
    return n1*n5*n9-n1*n6*n8+n2*n6*n7-n2*n4*n9+n3*n4*n8-n3*n5*n7;
}
int main() {
    for(int i=0;i<3;i++)
        for(int j=0;j<4;j++){
            cin >> num[i][j];
        }
    D[0]=GetAnswer(num[0][0],num[0][1],num[0][2],num[1][0],num[1][1],num[1][2],num[2][0],num[2][1],num[2][2]);
    D[1]=GetAnswer(num[0][3],num[0][1],num[0][2],num[1][3],num[1][1],num[1][2],num[2][3],num[2][1],num[2][2]);
    D[2]=GetAnswer(num[0][0],num[0][3],num[0][2],num[1][0],num[1][3],num[1][2],num[2][0],num[2][3],num[2][2]);
    D[3]=GetAnswer(num[0][0],num[0][1],num[0][3],num[1][0],num[1][1],num[1][3],num[2][0],num[2][1],num[2][3]);
    if(D[0]==0)
        cout << "nanisore?";
    else
    {
        cout << "x=" << D[1]/D[0] << endl;
        cout << "y=" << D[2]/D[0] << endl;
        cout << "z=" << D[3]/D[0] << endl;
    }
    return 0;
}
