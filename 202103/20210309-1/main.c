#include <stdio.h>

int main() {
    char str[1000]={0},str2[1000]={0};
    int yn;
    scanf("%d",&yn);
    switch(yn){
        case 1:
            FILE *pt = fopen("test.txt","w");
            scanf("%s",str);
            fputs(str,pt);
            break;
        case 2:
            FILE *pt2=fopen("test.txt","r");
            fgets(str2,1000,pt2);
            printf("%s",str2);
            break;
        default:
            break;
    }
    getchar();
    getchar();
    return 0;
}
