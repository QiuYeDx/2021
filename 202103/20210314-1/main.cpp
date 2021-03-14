#include <iostream>
#define SSS 0.00001
using namespace std;

int main() {
    double A, B, a, b;
    cin >> A >> B >> a >> b;
    int min_a,min_b;
    if(A>a+a-SSS+a-SSS)
    {
        int i;
        A-=a-SSS;
        for(i=0;A>=a;i++)
        {
            if(A>=a+a-SSS)
            {
                A-=a+a-SSS;
                i++;
            }
            else
                if(A>=a)
                    i++;
                else
                    break;
        }
        min_a=i;
    }
    else
        min_a=1;
    if(B>b+b-SSS+b-SSS)
    {
        int i;
        B-=b-SSS;
        for(i=0;B>=b;i++)
        {
            if(B>=b+b-SSS)
            {
                B-=b+b-SSS;
                i++;
            }
            else
            if(B>=b)
                i++;
            else
                break;
        }
        min_b=i;
    }
    else
        min_b=1;
   /* if(A>a+a-1+a-1)
    {
        min_a = (A-a+1)/(a+a-1);
        if((A-a+1)%(a+a-1)+a-1>=a)
            min_a++;
    }
    else
        min_a=1;
    int min_b;
    if(B>b+b-1+b-1)
    {
        min_b = (B-b+1)/(b+b-1);
        if((B-b+1)%(b+b-1)+b-1>=b)
            min_b++;
    }
    else
        min_b=1;
        */
    int min=min_a*min_b;
    cout << min;
    return 0;
}
