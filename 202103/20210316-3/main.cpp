#include <stdio.h>
#include <string.h>
char c[260];
int main(){
    int len,i,j,s;
    scanf("%s%d",c,&s);
    len=strlen(c);
    while(s--){
        for(i=0;i<=len-2;i++)
            if(c[i]>c[i+1]){
                for(j=i;j<=len-2;j++)
                    c[j]=c[j+1];
                break;
            }
        len--;//此处位置写错，之前写在if内部
    }
    i=0;
    while(i<=len-1&&c[i]=='0')i++;//处理前导0
    if(i==len)printf("0");
    else
        for(j=i;j<=len-1;j++)
            printf("%c",c[j]);
    return 0;
}