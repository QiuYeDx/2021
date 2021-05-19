#include "startscene.h"
#include<QPainter>
#include<QPushButton>
#include<QDebug>
startscene::startscene(QWidget *parent) : QWidget(parent)
{
    //设置窗口大小
    this->setFixedSize(GAME_WIDTH+13,GAME_HEIGHT);
    //设置图标
    this->setWindowIcon(QIcon(GAME_ICON));
    //在窗口中定义一个按钮（startbutton类）,构造函数中定义btntype=1
    button=new startbutton(1);
    button->setParent(this);
    //移动按钮
    button->move(button->myy+8,button->myx);

    connect(button,&startbutton::clicked,[=](){
      button->zoom1();     //设置按钮按下的动画
      button->zoom2();

        QTimer::singleShot(250,this,[=](){
            //按钮功能：隐藏主菜单，转移到帮助界面
            this->hide();
            myhelpscene=new helpscene();
            myhelpscene->show();
            myhelpscene->move(750,100);//将窗口移动到正常的位置
            connect(myhelpscene,&helpscene::sendend,[=](){
                //在帮助界面点击鼠标的功能：隐藏该窗口并弹出游戏窗口
                QTimer::singleShot(100,myhelpscene,[=](){
                    myhelpscene->hide();
                    mymainscene=new MainScene();
                    mymainscene->show();
                    mymainscene->move(750,100);//将窗口移动到正常的位置
                    reshow(); //重复刷新游戏背景，实现动画效果


                });

            });

        });

    });

}

void startscene::paintEvent(QPaintEvent *ev)
{
    //画出初始背景，与游戏刚开始时的相同
    QPainter painter(this);
    painter.drawPixmap(0,mymap.m_map1_posY,mymap.m_map1);
    painter.drawPixmap(0,mymap.m_map2_posY,mymap.m_map2);
}

void startscene::reshow()
{
    //接收重新开始信号
    connect(mymainscene,&MainScene::sendreshow,[=](){
        //创建新的对象，重新开始
        delete mymainscene;
        mymainscene=new MainScene();
        mymainscene->show();
        mymainscene->move(750,100);
        reshow();
    });

}
