#include "chooselevelscene.h"
#include <QMenuBar>
#include <QPainter>
#include "mypushbutton.h"
#include <QDebug>
#include <QTimer>
#include <QLabel>

ChooseLevelScene::ChooseLevelScene(QWidget *parent) : QMainWindow(parent)
{
    //配置选择关卡场景
    this->setFixedSize(420,650);

    //设置图标
    setWindowIcon(QIcon(":/res/Coin0001.png"));

    //设置标题
    setWindowTitle("选择关卡");

    //创建菜单栏
    QMenuBar * bar = menuBar();
    setMenuBar(bar);

    //创建开始菜单
    QMenu * startMenu = bar->addMenu("开始");

    //创建退出菜单项
    QAction * quitAction = startMenu->addAction("退出");

    //点击退出实现退出游戏
    connect(quitAction,&QAction::triggered,[=](){
       this->close();
    });

    //返回按钮
    MyPushButton * backBtn = new MyPushButton(":/res/BackButton.png",":/res/BackButtonSelected.png");
    backBtn->setParent(this);
    backBtn->move(this->width()-backBtn->width() , this->height()-backBtn->height());
    //点击返回
    connect(backBtn,&MyPushButton::clicked,[=](){
        //主场景监听chooseLevelScene返回按钮
        //延时返回

        QTimer::singleShot(500,this,[=](){
            emit this->chooseSceneBack();
        });

    });

    //创建选择关卡的按钮
    for(int i=0 ; i<20 ; i++)
    {
        MyPushButton * menuBtn = new MyPushButton(":/res/LevelIcon.png");
        menuBtn->setParent(this);
        menuBtn->move( 65+i%4 * 80 , 150+i/4 * 80 );

        //监听每个按钮的点击事件
        connect(menuBtn,&MyPushButton::clicked,[=](){
                QString str = QString("您选择的是第 %1 关 ").arg(i+1);
                qDebug() <<str;

                //进入到游戏场景
                this->hide();   //选择场景隐藏掉
                play= new PlayScene(i+1);
                play->show();   //显示游戏场景

                //从关卡中返回到选关界面
                connect(play,&PlayScene::chooseSceneBack,[=](){
                    this->show();
                    delete play;
                    play = NULL;
                });

           });

        //给图片上贴数字
        QLabel * label = new QLabel;
        label->setParent(this);
        label->setFixedSize(menuBtn->width() , menuBtn->height());
        label->setText(QString::number(i+1));
        label->move( 65+i%4 * 80 , 150+i/4 * 80 );

        //设置对齐方式  水平居中和垂直居中
        label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        //设置鼠标穿透（防止按的是label）  51号属性
        label->setAttribute(Qt::WA_TransparentForMouseEvents);
    }

}

void ChooseLevelScene::paintEvent(QPaintEvent *)
{
    //加载背景
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/OtherSceneBg.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
    //加载标题
    pix.load(":/res/Title.png");
    painter.drawPixmap( (this->width() - pix.width()) * 0.5,30,pix.width(),pix.height(),pix );
}
