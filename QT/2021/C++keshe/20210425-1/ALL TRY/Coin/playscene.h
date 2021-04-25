#ifndef PLAYSCENE_H
#define PLAYSCENE_H

#include <QMainWindow>
#include <mycoin.h>
class PlayScene : public QMainWindow
{
    Q_OBJECT
public:
    //explicit PlayScene(QWidget *parent = nullptr);

    PlayScene(int levelNum);

    int levelIndex;  //内部的成员属性，记录所选关卡

    //重写paintEvent事件
    void paintEvent(QPaintEvent *);

    int gameArray[4][4];  //二维数组，维护每个关卡具体的数据

    MyCoin * coinBtn[4][4];
signals:
    void chooseSceneBack();
public slots:
};

#endif // PLAYSCENE_H
