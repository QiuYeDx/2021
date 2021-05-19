#ifndef MYPLANE_H
#define MYPLANE_H
#include<QPixmap>
#include"bullet.h"
class myplane     //玩家的飞机类
{
public:
    myplane();
    void shoot();          //射击
    void setPosition(int x,int y);    //设置位置
public:
    QPixmap m_Plane;       //加载图片
    int m_x;
    int m_y;
    QRect m_Rect;          //
    bullet m_bullets[BULLET_NUM];
    int m_recorder;        //管理子弹发射的变量
};

#endif // MYPLANE_H
