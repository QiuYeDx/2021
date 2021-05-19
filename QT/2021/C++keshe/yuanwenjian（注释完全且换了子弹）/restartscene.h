#ifndef RESTARTSCENE_H
#define RESTARTSCENE_H

#include <QWidget>
#include"config.h"
#include<QTimer>
#include"startbutton.h"
#include"map.h"
class restartscene : public QWidget
{
    Q_OBJECT
public:
    void paintEvent(QPaintEvent *ev);   //绘图以及显示文字
    explicit restartscene(QWidget *parent = nullptr);  //构造函数
    Map mymap;                            //背景图片
    startbutton *restartbtn;              //重新开始按钮
    QPixmap frame;                        //上层图片
signals:
    void sendreshow();

};

#endif // RESTARTSCENE_H
