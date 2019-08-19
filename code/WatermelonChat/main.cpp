#include "widget.h"
#include"client.h"
#include <QApplication>
#include <QPropertyAnimation>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //慢慢消失的效果
    Client c;
    c.setWindowTitle("client");
    QPropertyAnimation *animation = new QPropertyAnimation(&c,"windowOpacity");
    animation->setDuration(500);
    animation->setStartValue(0);
    animation->setEndValue(1);
    animation->start();
    c.show();
    return a.exec();
}
