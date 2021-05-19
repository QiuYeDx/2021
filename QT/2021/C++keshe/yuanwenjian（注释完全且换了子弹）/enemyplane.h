#ifndef ENEMYOLANE_H
#define ENEMYOLANE_H
#include"bullet.h"
#include<QPixmap>
class EnemyPlane   //敌机类
{
public:
    EnemyPlane();               //构造函数
    void updatePosition();      //更新位置
    void shoot();               //发射子弹函数
public:
    QPixmap m_enemy;            //加载图片
    int m_x;                    //坐标
    int m_y;
    QRect m_Rect;               //碰撞体积
    bool m_Free;                //是否free
    int m_Speed;                //速度，定义为每次更新位置时敌机的移动距离
    int outscreen;              //是否已经出屏幕
    bullet mybullet[3];         //三发子弹，保证不会多用子弹
    int  m_recorder;            //管理子弹发射的变量
};

#endif // ENEMYOLANE_H
