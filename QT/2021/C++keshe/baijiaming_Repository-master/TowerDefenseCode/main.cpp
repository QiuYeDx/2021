#include "startwindow.h"
#include <QApplication>
#include <bits/stdc++.h>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    StartWindow w;
    w.show();

    return a.exec();
}
