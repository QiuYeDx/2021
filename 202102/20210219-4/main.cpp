#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int const MAXN = 50010;
struct poi{
    int x, y, z;
}a[MAXN];
int N;
double sum=0;
bool cmp(poi m, poi n)
{
    return m.z < n.z;
}
int main() {
    cin >> N;
    for(int i=0;i<N;i++)
        cin >> a[i].x >> a[i].y >> a[i].z;
    sort(a,a+N,cmp);
    for(int i=0;i<N-1;i++)
        sum+=sqrt(pow(a[i+1].x-a[i].x,2)+pow(a[i+1].y-a[i].y,2)+pow(a[i+1].z-a[i].z,2));
    printf("%.3lf",sum);
    return 0;
}
