#include <stdio.h>
#pragma comment(lib,"libmysql")
#include <mysql.h>
int main() {
    char str[1000]={0},str2[1000]={0};
    int yn;
    scanf("%d",&yn);
    switch(yn){
        case 1:
            FILE *pt = fopen("test2.dat","w");
            scanf("%s",str);
            fread(str,sizeof(char),5,pt);
            break;
        case 2:
            FILE *pt2=fopen("test2.dat","r");
            fwrite(str2,sizeof(char),5,pt2);
            printf("%s",str2);
            break;
        default:
            break;
    }
    getchar();
    getchar();
    return 0;
}
