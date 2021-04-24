#include <bits/stdc++.h>
using namespace std;
enum Color {    //颜色枚举型定义
    MAKI,
    ERI,
    UMI
};
/*class Ball {    //小球类定义
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
};*/
void shengli(){
    cout << "omedetou" << endl; //gong xi ~
}
void shibai(){
    cout << "zannen" << endl;   //zhen yi han ya ~
}
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
    Optional<int> a;
    Optional<double> b;
    Optional<Color> c;
    int zl1,zl3;char zl2;int x;double xx;string xxx;
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> zl1 >> zl2 >> zl3;
        if(zl1==1){
            if(zl3==1){
                if(zl2=='A')
                    a.clear();
                else if(zl2=='B')
                    b.clear();
                else c.clear();
            }else if(zl3==2){   //fang ru wu pin
                if(zl2=='A'){
                    cin >> x;
                    if(!a.exists())continue;
                    a.set(x);
                }else if(zl2=='B'){
                    cin >> xx;
                    if(!b.exists())continue;
                    b.set(xx);
                }else if(zl2=='C'){
                    cin >> xxx;
                    if(!c.exists())continue;
                    if(xxx=="maki")
                        c.set(MAKI);
                    else if(xxx=="eri")
                        c.set(ERI);
                    else if(xxx=="umi")
                        c.set(UMI);
                }
            }else{  //xiu gai
                if(zl2=='A'){
                    cin >> x;
                    if(a.exists())continue;
                    a.set(x);
                }else if(zl2=='B'){
                    cin >> xx;
                    if(b.exists())continue;
                    b.set(xx);
                }else if(zl2=='C'){
                    cin >> xxx;
                    if(c.exists())continue;
                    if(xxx=="maki")
                        c.set(MAKI);
                    else if(xxx=="eri")
                        c.set(ERI);
                    else if(xxx=="umi")
                        c.set(UMI);
                }
            }
        }else{
            if(zl2=='A'){
                cin >> x;
                if(a.exists()){
                    shibai();
                    continue;
                }
                if(a.get()==x) shengli();
                else shibai();
            }else if(zl2=='B'){
                cin >> xx;
                if(b.exists()){
                    shibai();
                    continue;
                }
                if(b.get()==xx) shengli();
                else shibai();
            }else if(zl2=='C'){
                cin >> xxx;
                if(c.exists()){
                    shibai();
                    continue;
                }
                if(xxx=="maki"){
                    if(c.get()==MAKI) shengli();
                    else shibai();
                }
                else if(xxx=="eri")
                    if(c.get()==ERI) shengli();
                    else shibai();
                else if(xxx=="umi"){
                    if(c.get()==UMI)
                        shengli();
                    else
                        shibai();
                }
            }
        }
    }
    return 0;
}

template <class T>
void Optional<T>::clear(){
    isEmpty=true;
}
template <class T>
void Optional<T>::set(const T& t){
    content=t;
    isEmpty=false;
}
template <class T>
T Optional<T>::get()const{
    return content;
}