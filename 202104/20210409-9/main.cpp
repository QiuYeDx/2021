#include <bits/stdc++.h>
using namespace std;
class Point{
public:
    virtual void getDis(){}
    virtual void showPos(){}
    virtual void getPoint(double, double){}
    virtual void getPoint(double, double, double){}
    double dist;
};
class Point_2:public Point{
public:
    void getDis(){
        dist=sqrt(x*x+y*y);
        printf("%.2lf\n",dist);
    }
    void showPos(){
        printf("%.2lf %.2lf\n",x,y);
    }
    void getPoint(double xx,double yy){
        x=xx;y=yy;
    }
private:
    double x,y;
};
class Point_3:public Point{
public:
    void getDis(){
        dist=sqrt(x*x+y*y+z*z);
        printf("%.2lf\n",dist);
    }
    void showPos(){
        printf("%.2lf %.2lf %.2lf\n",x,y,z);
    }
    void getPoint(double xx,double yy,double zz){
        x=xx;y=yy;z=zz;
    }
private:
    double x,y,z;
};
int main() {
    Point_2 p2;
    Point_3 p3;
    Point* pa=&p2,*pb=&p3;
    double x1,y1,x2,y2,z2;
    while(cin >> x1 >> y1 >> x2 >> y2 >> z2){
        pa->getPoint(x1,y1);
        pb->getPoint(x2,y2,z2);
        pa->getDis();
        pa->showPos();
        pb->getDis();
        pb->showPos();
    }
    return 0;
}
