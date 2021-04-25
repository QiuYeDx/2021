#include <bits/stdc++.h>
using namespace std;
stack<int> n;
int s=0,x,y;
int main() {
    char ch;
    do{
        ch=getchar();
        if(ch>='0'&&ch<='9')
            s=s*10+ch-'0';
        else if(ch == '.')
            n.push(s),s=0;
        else if(ch!='@'){
            x=n.top();
            n.pop();
            y=n.top();
            n.pop();
            switch(ch){
                case '+':n.push(x+y);break;
                case '-':n.push(y-x);break;
                case '*':n.push(x*y);break;
                case '/':n.push(y/x);break;
            }
        }
    }while(ch!='@');
    printf("%d\n",n.top());
    return 0;
}
