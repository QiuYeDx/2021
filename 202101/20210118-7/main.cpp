#include <cstdio> //P1319 压缩技术

int main() {
    int N;
    int i=0,cs=0,rep;

    scanf("%d",&N);
    while(scanf("%d",&rep)!=EOF)
    {
        if(cs==0)
        {
            for(int n=0;n<rep;n++)
            {
                if(i<N)
                    printf("0");
                else
                {
                    printf("\n0");
                    i=0;
                }
                i++;
            }
            cs=1;
        }
        else
        {
            for(int n=0;n<rep;n++)
            {
                if(i<N)
                    printf("1");
                else
                {
                    printf("\n1");
                    i=0;
                }
                i++;
            }
            cs=0;
        }
    }
    return 0;
}
