#include <cstdio> //P1320 压缩技术(续集版)

int main() {
    int N=0;
    int i=0,i_s=1;
    char ch,last;
    int str[10000]={0};

    while(scanf("%c",&ch)!=EOF)
    {
        if(ch=='0' || ch=='1')
            N++;
        else
        {
            str[0]=N;
            break;
        }
        if(i==0)
        {
            if(ch=='1')
            {
                i++;
                str[i_s]=0;
                i_s++;
                last=ch;
                continue;
            }
            else
            {
                last=ch;
                i++;
                continue;
            }
        }
        else
        {
            if(last==ch)
            {
                i++;
                continue;
            }
            else
            {
                str[i_s]=i;
                i_s++;
                i=1;
                last=ch;
                continue;
            }
        }
    }
    while(scanf("%c",&ch)!=EOF)
    {
        if(ch!='0'&&ch!='1')
            continue;
        if(i==0)
        {
            last=ch;
            i++;
            continue;
        }
        else
        {
            if(last==ch)
            {
                i++;
                continue;
            }
            else
            {
                str[i_s]=i;
                i_s++;
                i=1;
                last=ch;
                continue;
            }
        }
    }
    str[i_s]=i;
    for(int j=0;j<i_s;j++)
        printf("%d ",str[j]);
    printf("%d",str[i_s]);
    return 0;
}
