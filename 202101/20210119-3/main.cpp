#include <iostream>
#include <string>
using namespace std;

int main() {
    string str="LUOGU";
    char arr[10]={0};
    int len = str.copy(arr,6);
    arr[len]='!';
    cout << arr;
    return 0;
}
