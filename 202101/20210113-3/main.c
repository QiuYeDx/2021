#include <stdio.h>

int main() {
    char ch[100]={0};
    char str[100]={0};
    char rep;
    int n=0,i,k=0;
    int yn;

    scanf("%s",str);
    while(rep=str[k],rep!='\0')
    {
        yn=1;
        for(i=0;ch[i]!='\0';i++)
        {
            if(ch[i]==rep)
            {
                yn=0;
                break;
            }
        }
        if(yn==1)
        {
            ch[i]=rep;
            n++;
        }
        k++;
    }
    if(n%2==0)
        printf("CHAT WITH HER!");
    else
        printf("IGNORE HIM!");

    return 0;
}
