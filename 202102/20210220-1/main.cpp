#include <iostream> //P2241 统计方形（数据加强版）3/10 7个超时 O(n^2*m^2)
using namespace std;
int const MAXN = 5010*5010;
struct poi{
    int x, y;
}o,p;
int main() {
    int n, m, n1=0, n2=0;
    cin >> n >> m;  //n+1行m+1列
    m++;
    n++;
    for(o.x=1;o.x<m;o.x++)
        for(o.y=1;o.y<n;o.y++)
            for(p.x=o.x+1;p.x<=m;p.x++)
                for(p.y=o.y+1;p.y<=n;p.y++)
                    if(p.x-o.x==p.y-o.y)
                        n1++;
                    else
                        n2++;
    cout << n1 << ' ' << n2;
    return 0;
}
