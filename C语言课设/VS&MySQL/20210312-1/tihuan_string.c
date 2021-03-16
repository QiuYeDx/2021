#include <stdio.h>
#include <string.h>
#include <malloc.h>
 
// 将strRes中的t替换为s，替换成功返回1，否则返回0。
int StrReplace(char strRes[],char from[], char to[]) {
    int i,flag = 0;
    char *p,*q,*ts;
    for(i = 0; strRes[i]; ++i) {
        if(strRes[i] == from[0]) {
            p = strRes + i;
            q = from;
            while(*q && (*p++ == *q++));
            if(*q == '\0') {
                ts = (char *)malloc(strlen(strRes) + 1);
                strcpy(ts,p);
                strRes[i] = '\0';
                strcat(strRes,to);
                strcat(strRes,ts);
                free(ts);
                flag = 1;
            }
        }
    }
    return flag;
}
 
int main() {
    char str[80] = "select * from goods_v1.staff";
    printf("替换前:%s\n",str);
    if(StrReplace(str,"staff","goods")) printf("替换后:%s\n",str);
    else printf("没有任何替换。\n");
    return 0;
}
