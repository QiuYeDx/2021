#ifndef ENEMYOLANE_H
#define ENEMYOLANE_H
#include"bullet.h"
#include<QPixmap>
class EnemyPlane
{
public:
    EnemyPlane();
    void updatePosition();
public: QPixmap m_enemy;
    int m_x;
    int m_y;
    QRect m_Rect;
    bool m_Free;
    int m_Speed;
    int outscreen;
    bullet mybullet[3];
    void shoot();
    int  m_recorder;
};

#endif // ENEMYOLANE_H
