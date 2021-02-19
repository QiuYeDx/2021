#include <iostream> //P1104 生日
#include <algorithm>
#include <string>
using namespace std;
int const MAXN = 110;
int N;
struct man{
    string name;
    int year, month, day, id;
}a[MAXN];
bool cmp(man x, man y)
{
    if(x.year != y.year)
        return x.year < y.year;
    else if(x.month != y.month)
        return x.month < y.month;
    else if(x.day != y.day)
        return x.day < y.day;
    else return x.id > y.id;   //生日相同则输入靠后的同学(id大的同学)先输出
}
int main() {
    cin >> N;
    for(int i=0;i<N;i++)
        a[i].id=i;
    for(int i=0;i<N;i++)
        cin >> a[i].name >> a[i].year >> a[i].month >> a[i].day;
    sort(a,a+N,cmp);
    for(int i=0;i<N;i++)
        cout << a[i].name << endl;
    return 0;
}
