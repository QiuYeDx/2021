#include <bits/stdc++.h>    //Uva673

using namespace std;
stack<char> s;
int num;

char trans(char a) {
    if (a == ')') return '(';
    if (a == ']') return '[';
    if (a == '}') return '{';
    return '\0';
}

int main() {
    cin >> num;
    string p;
    getline(cin, p);    //读掉num后的换行符，用getchar()也可
    while(num--){
        while(!s.empty())
            s.pop();    //清除
        getline(cin, p);    //读入一行
        for(int i=0;i<p.size();i++){
            if(s.empty()){  //如果栈为空，直接放入栈中
                s.push(p[i]);
                continue;
            }
            if(trans(p[i])==s.top())
                s.pop();
            else
                s.push(p[i]);
        }
        if(s.empty())   printf("Yes\n");
        else    printf("No\n");
    }
    return 0;
}
