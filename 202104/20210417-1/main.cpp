#include <bits/stdc++.h>
class Point{
public:
    Point(int _x,int _y){
        x=_x;y=_y;
    }
    Point(){x=0;y=0;}
    void showPoint(){
        printf("(%d,%d)\n",x,y);
    }
    Point(Point& p){
        x=p.x;y=p.y;
    }
    Point& operator++(){
        x++;y++;
        return *this;
    }
    Point operator++(int){
        Point u(*this);
        ++*this;
        return u;
    }
    Point& operator--(){
        x--;y--;
        return *this;
    }
    Point operator--(int){
        Point u(*this);
        --*this;
        return u;
    }
private:
    int x,y;
};
using namespace std;
int main() {
    int x,y;
    cin >> x >> y;
    Point point(x,y);
    point.showPoint();
    point.showPoint();
    point++;
    ++point;
    point.showPoint();
    point.showPoint();
    point--;
    --point;
    point.showPoint();
    return 0;
}
