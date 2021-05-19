#include "myplane.h"
#include"config.h"
#include"mainscene.h"
myplane::myplane()
{
    m_Plane.load(MY_PATH);   //加载图片
    //设置初始位置，即最下面居中的位置
    m_x=GAME_WIDTH*0.5-m_Plane.width()*0.5;
    m_y=GAME_HEIGHT-m_Plane.height();
    //设置碰撞体积大小及其位置
    m_Rect.setWidth(0.8*(m_Plane.width()));
    m_Rect.setHeight(0.8*m_Plane.height());
    m_Rect.moveTo(m_x+0.1*m_Plane.width(),m_y);
    m_recorder=0;
}
void myplane::setPosition(int x, int y)
{
    m_x=x;
    m_y=y;
    m_Rect.moveTo(m_x+0.1*m_Plane.width() /* 微调碰撞体积位置 */,m_y);
}
void myplane::shoot()
{
    m_recorder++;
    //射击速度与得分和Bullet_INTERVAL都有关
    if(m_recorder<Bullet_INTERVAL-MainScene::recorde/5){return;}
    m_recorder=0;
    for(int i=0;i<BULLET_NUM;i++)
    {
        if(m_bullets[i].m_free)      //与敌机发射子弹同理
        {
            m_bullets[i].m_free=false;
            m_bullets[i].m_x=m_x+m_Rect.width()*0.5+3;
            m_bullets[i].m_y=m_y-8;
            break;
        }
    }

}
