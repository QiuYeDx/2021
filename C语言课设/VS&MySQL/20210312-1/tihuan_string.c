#include <stdio.h>
#include <string.h>
#include <malloc.h>
 
// ��strRes�е�t�滻Ϊs���滻�ɹ�����1�����򷵻�0��
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
    printf("�滻ǰ:%s\n",str);
    if(StrReplace(str,"staff","goods")) printf("�滻��:%s\n",str);
    else printf("û���κ��滻��\n");
    return 0;
}
