#include <bits/stdc++.h>
using namespace std;
enum Color {    //颜色枚举型定义
    MAKI,
    ERI,
    UMI
};

class Ball {    //小球类定义
private:
    Color color;
public:
    Ball(){}
    Ball(const Color& c){color=c;}
    Ball(Ball& b){color=b.color;}
    Color getColor() const{
        return color;
    }
    void setColor(const Color& c){color=c;}
    Ball& operator=(int x){ //匹配模板___挂在最后一条语句了
        color=(Color)x;
        return *this;
    }
};

template <class T>
class Optional {    //盒子模板类定义
private:
    T content;  //盒子内容
    bool isEmpty;   //盒子是否为空
public:
    Optional(){isEmpty=true;}
    bool exists() const{return isEmpty;}    //判断盒子是否为空
    void clear();   //清空盒子
    void set(const T& t);   //放入物品
    T get() const;  //获取盒子中的物品
};

int main() {

    return 0;
}

template <class T>
void Optional<T>::clear(){
    content=0;
    isEmpty=true;
}
template <class T>
void Optional<T>::set(const T& t){
    content=t;
}
template <class T>
T Optional<T>::get()const{
    return content;
}