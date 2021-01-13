#include <stdio.h>  //xx7-8 画方块（四舍五入）

int main() {
    int n;
    char ch;
    float rep;
    int l;

    while(scanf("%d",&n)!=EOF)
    {
        getchar();
        scanf("%c",&ch);
        l=n/2+((float)n/2-n/2>=0.5?1:0);
        for(int i=0;i<l;i++)
        {
            for(int j=0;j<n;j++)
                printf("%c",ch);
            printf("\n");
        }
    }

    return 0;
}
