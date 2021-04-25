#include <bits/stdc++.h>
using namespace std;
class Polygon{
public:
    virtual double getArea(){}
    //virtual void initEdge(){}
    virtual void getEdge(int l){}
    //virtual void initArea(){}
    int myEdge;
};
class Triangle:public Polygon{
public:
    double getArea(){
    return sqrt(3)*myEdge/4*myEdge;
    }
    void getEdge(int l){
        myEdge=l/3;
    }
};
class Square:public Polygon{
public:
    double getArea(){
        return 1.0*myEdge*myEdge;
    }
    void getEdge(int l){
        myEdge=l/4;
    }
};
int main() {
    Square a;
    Triangle b;
    Polygon* c=&a;
    Polygon* d=&b;
    int m,n;
    while(cin >> m >> n){
        a.getEdge(n);
        b.getEdge(m);
        double x=a.getArea();
        double y=b.getArea();   //三角形
        printf("%.4lf\n%.4lf\n",y,x);
        if(x>=y) printf("No!\n");
        else printf("Yes!\n");
    }
    return 0;
}
