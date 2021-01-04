#include <stdio.h>  //i++不是赋值语句。。。

int main() {
    float a=1.1;
    ((int)a)++;
    printf("%f\n",a);

    float b=1.1;
    (int)b+=1;
    printf("%f\n",b);

    float c=1.1;
    (int)c=c+1;

    return 0;
}
