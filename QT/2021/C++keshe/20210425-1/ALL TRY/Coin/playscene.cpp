#include "playscene.h"
#include <QDebug>
#include <QMenuBar>
#include <QPainter>
#include "mypushbutton.h"
#include <QTimer>
#include <QLabel>
#include "mycoin.h"
#include "dataconfig.h"
//PlayScene::PlayScene(QWidget *parent) : QMainWindow(parent)
//{

//}

PlayScene::PlayScene(int levelNum)
{
    QString str = QString("进入了第 %1 关").arg(levelNum);
    qDebug()<<str;
    this->levelIndex = levelNum;

    //初始化游戏场景
    //初始化固定大小
    this->setFixedSize(420,650);
    //设置图标
    this->setWindowIcon(QIcon(":/res/Coin0001.png"));
    //设置标题
    this->setWindowTitle("翻金币场景");

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
          qDebug()<<"点击了返回按钮";
        QTimer::singleShot(500,this,[=](){
            emit this->chooseSceneBack();
        });

    });

    //显示关卡数
    QLabel * label = new QLabel;
    label->setParent(this);
    //改字体和字号
    QFont font;
    font.setFamily("华文新魏");
    font.setPointSize(20);
    QString str1 = QString("Level: %1").arg(this->levelIndex);
    //将字体设置到标签控件
    label->setFont(font);
    //记录关卡数字
    label->setText(str1);
    //既设置大小又挪位置
    label->setGeometry(30,this->height()-50,120,60);

    dataConfig config;
    //初始化每个关卡的二维数组
    for(int i=0 ; i<4 ; i++)
    {
        for(int j=0 ; j<4 ; j++)
        {
            this->gameArray[i][j]=config.mData[this->levelIndex][i][j];

        }
    }

    //显示金币背景的图案
    for(int i=0 ; i<4 ; i++)
    {
        for(int j=0 ; j<4 ; j++)
        {
            //绘制背景图片
            QPixmap pix = QPixmap(":/res/BoardNode.png");
            QLabel * label = new QLabel;
            label->setGeometry(0,0,pix.width(),pix.height());   //如果改变图片，可以适应新大小
            label->setPixmap(pix);
            label->setParent(this);
            label->move(110+i*50 , 210+j*50);

            //创建金币
            if(this->gameArray[i][j]==1)
            {
                //显示金币
                str = ":/res/Coin0001.png";
            }
            else str=":/res/Coin0008.png";
            MyCoin * coin = new MyCoin(str);
            coin->setParent(this);
            coin->move(112+i*50 , 212+j*50);

            //给金币的属性赋值
            coin->posX=i;
            coin->posY=j;
            coin->flag=this->gameArray[i][j];   //1正面 0反面

            //将金币放入到金币的二位数组里
            coinBtn[i][j] = coin;

            //点击金币进行翻转
            connect(coin,&MyCoin::clicked,[=](){
                coin->changeFlag();
                this->gameArray[i][j] = this->gameArray[i][j] == 0 ? 1 : 0 ;
                QTimer::singleShot(250,this,[=](){
                    //翻转周围硬币
                    if(coin->posX+1<=3)    //右侧翻的条件
                    {
                        coinBtn[coin->posX+1][coin->posY]->changeFlag();
                        this->gameArray[coin->posX+1][coin->posY] = this->gameArray[coin->posX+1][coin->posY] == 0 ? 1 : 0 ;
                    }
                    //左侧
                    if(coin->posX-1>=0)
                    {
                        coinBtn[coin->posX-1][coin->posY]->changeFlag();
                        this->gameArray[coin->posX-1][coin->posY] = this->gameArray[coin->posX-1][coin->posY] == 0 ? 1 : 0 ;
                    }
                    //上
                    if(coin->posY+1<=3)
                    {
                        coinBtn[coin->posX][coin->posY+1]->changeFlag();
                        this->gameArray[coin->posX][coin->posY+1] = this->gameArray[coin->posX][coin->posY+1] == 0 ? 1 : 0 ;
                    }
                    //下
                    if(coin->posY-1>=0)
                    {
                        coinBtn[coin->posX][coin->posY-1]->changeFlag();
                        this->gameArray[coin->posX][coin->posY-1] = this->gameArray[coin->posX][coin->posY-1] == 0 ? 1 : 0 ;
                    }
                });


            });

        }
    }

}



void PlayScene::paintEvent(QPaintEvent *)
{
    //创建背景
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/PlayLevelSceneBg.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

    //加载标题
    pix.load(":/res/Title.png");
    pix = pix.scaled(pix.width()*0.5,pix.height()*0.5);
    painter.drawPixmap(10,30,pix.width(),pix.height(),pix);


}
