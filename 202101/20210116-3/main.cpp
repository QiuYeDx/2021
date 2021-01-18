#include <cstdio>

int main() {
    int n1,n2,n3,rep;
    int a,b,c;
    char ch;

    scanf("%d%d%d",&n1,&n2,&n3);
    getchar();
    getchar();               //洛谷上需要两个getchar()！！！！！
    if(n1>n2)                //因为回车相当于\n\r
    {
        rep=n2;
        n2=n1;
        n1=rep;
    }
    if(n1>n3)
    {
        rep=n3;
        n3=n1;
        n1=rep;
    }
    if(n2>n3)
    {
        rep=n3;
        n3=n2;
        n2=rep;
    }
    a=n1;
    b=n2;
    c=n3;
    for(int i=0;i<2;i++)
    {
        scanf("%c",&ch);
        switch(ch){
            case 'A':printf("%d ",a);break;
            case 'B':printf("%d ",b);break;
            case 'C':printf("%d ",c);break;
        }
    }
    scanf("%c",&ch);
    switch(ch){
        case 'A':printf("%d",a);break;
        case 'B':printf("%d",b);break;
        case 'C':printf("%d",c);break;
    }

    return 0;
}
