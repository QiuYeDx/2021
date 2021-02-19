#include <iostream>     //P1093 [NOIP2007 普及组] 奖学金 ******典例·结构体排序******
#include <algorithm>
using namespace std;
int const MAXN = 310;
int n;
struct student
{
    int id, chinese, total;
}a[MAXN];

bool cmp(student x, student y)  //c++中可以略去struct前缀了!
{
    if(x.total != y.total)      //自己写的，算是比较普遍，比较正规的写法(书上的是错的）
        return x.total > y.total;
    else if(x.chinese != y.chinese)
        return x.chinese > y.chinese;
    else
        return x.id < y.id;
}

int main() {
    int rep1,rep2;

    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> a[i].chinese >> rep1 >> rep2;
        a[i].total = a[i].chinese + rep1 + rep2;
        a[i].id = i+1;
    }
    sort(a,a+n,cmp);
    for(int i=0;i<5;i++)
        cout << a[i].id << ' ' << a[i].total << endl;
    return 0;
}
