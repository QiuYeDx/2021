#ifndef BULLET_H
#define BULLET_H
#include<QPixmap>
#include"config.h"
class bullet     //子弹类
{
public:
    bullet();                   //构造函数
    void updatePosition();      //更新玩家子弹的位置（碰撞体积和坐标）
    void updatePosition2();     //更新敌机子弹的位置（碰撞体积和坐标）
public:
    QPixmap m_bullet;           //加载图片
    int m_x;                    //横纵坐标
    int m_y;
    int m_speed;   //子弹速度，定义为每次更新位置时子弹的移动距离
    bool m_free;                //是否free
    QRect m_Rect;               //碰撞体积
};

#endif // BULLET_H
