#include "mainscene.h"
#include "ui_mainscene.h"
#include <QPainter>
#include "mypushbutton.h"
#include <QDebug>
#include <QTimer>
MainScene::MainScene(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainScene)
{
    ui->setupUi(this);
    //配置主场景

    //设置固定大小
    setFixedSize(420,650);
    //设置图标
    setWindowIcon(QIcon(":/res/Coin0001.png"));
    //设置标题
    setWindowTitle("WPS带你翻金币");

    //退出按钮的实现
    connect(ui->actionquit,&QAction::triggered,[=]()
    {
      this->close();
    });

    //开始按钮
    MyPushButton * startBtn = new MyPushButton(":/res/MenuSceneStartButton.png");
    startBtn->setParent(this);
    startBtn->move(this->width()*0.5 - startBtn->width()*0.5 , this->height()*0.7);

    //实例化选择关卡场景
    chooseScene = new ChooseLevelScene;

    //监听选择关卡返回按钮的信号
    connect(chooseScene,&ChooseLevelScene::chooseSceneBack,this,[=](){
        chooseScene->hide();   //隐藏选择关卡场景
        this->show();   //重新显示主场景

    });

    connect(startBtn,&MyPushButton::clicked,[=](){
        qDebug()<<"开始游戏！";
        //下面做弹起特效
        startBtn->zoom1();
        startBtn->zoom2();
        QTimer::singleShot(500,this,[=](){      //延时进入
            //将自身隐藏，进入到选择关卡场景中
            this->hide();
            chooseScene->show();
        });


    });
}


void MainScene::paintEvent(QPaintEvent *)        //画主界面的背景图
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/PlayLevelSceneBg.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);  //拉伸至设定的窗口大小
    //画背景图上的图标
    pix.load(":/res/Title.png");
    pix = pix.scaled( pix.width() * 0.5 , pix.height() * 0.5);    //缩放
    painter.drawPixmap(10,30,pix);
}

MainScene::~MainScene()
{
    delete ui;
}
