#include "restartscene.h"
#include<QPainter>
#include<QDebug>
#include"mainscene.h"
restartscene::restartscene(QWidget *parent) : QWidget(parent)
{
    //显示图片
    frame.load(FRAME_PATH);
    frame=frame.scaled(GAME_WIDTH+13,GAME_HEIGHT*0.35);
    //设置窗口大小
    this->setFixedSize(GAME_WIDTH+13,GAME_HEIGHT);
    //重新开始按钮
    restartbtn=new startbutton(2);
    restartbtn->setParent(this);
    restartbtn->move(restartbtn->myy+10,restartbtn->myx);

    connect(restartbtn,&QPushButton::clicked,[=](){
        //设置点击特效
        restartbtn->zoom1();
        restartbtn->zoom2();
        //重新开始
        QTimer::singleShot(300,this,[=](){
            this->hide();
            emit sendreshow();
        });
    });
}

void restartscene::paintEvent(QPaintEvent *ev)
{
    QPainter painter(this);
    //画背景图（与游戏开始前的一样）
    painter.drawPixmap(0,mymap.m_map1_posY,mymap.m_map1);
    painter.drawPixmap(0,mymap.m_map2_posY,mymap.m_map2);
    painter.drawPixmap(0,GAME_HEIGHT*0.3,frame);
    //显示文字
    painter.setFont(QFont("楷体",30));
    painter.drawText(0.5*GAME_WIDTH-75-10,0.5*GAME_HEIGHT-15,"游戏结束");
    painter.setFont(QFont("楷体",20));
    painter.drawText(0.5*GAME_WIDTH-45-10,0.5*GAME_HEIGHT+15,"得分："+QString::number(MainScene::recorde));
}
