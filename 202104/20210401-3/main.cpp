#include <bits/stdc++.h>
using namespace std;

int main() {
    string str;
    while(getline(cin,str)){
        int n_A=0,n_a=0,n_b=0,n_other=0,len=str.size();
        for(int i=0;i<len;i++)
            if(str[i]>='A' && str[i]<='Z')
                n_A++;
            else if(str[i]>='a' && str[i]<='z')
                n_a++;
            else if(str[i]==' ')
                n_b++;
            else n_other++;
            printf("%d %d %d %d\n",n_A,n_a,n_b,n_other);
    }

    return 0;
}
