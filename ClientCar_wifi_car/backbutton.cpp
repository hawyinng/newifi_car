#include "backbutton.h"
#include <QDebug>

BackButton::BackButton(QWidget *parent) : QPushButton(parent)
{
    QPalette pal = this->palette();              //startBtn是我已经定义好的QPushButton对象
    pal.setColor(QPalette::ButtonText, Qt::green);    //设置按钮上的字体颜色，理论上可以，实际上就是可以
    //pal.setColor(QPalette::Background, Qt::green);      //设置按钮背景颜色，理论上可以，实际上不可以
    this->setPalette(pal);
    //this->setStyleSheet("background-color:green");
}

void BackButton::mousePressEvent(QMouseEvent *event) {
    //this->setText(QString("<center><h1>Press: (%1, %2)</h1></center>") .arg
      //            (QString::number(event->x()), QString::number(event->y())));

    qDebug() << "BackButton mousePressEvent" <<"\n";
    qDebug() << "BackButton isEnabled" << this->isEnabled() << "\n";
    if(this->isEnabled())
    {
        this->setEnabled(false);
        QPushButton::mousePressEvent(event);
        //qDebug() << "BackButton styleSheet" << this->styleSheet() << "\n";
        return;
    }

    if(!this->isEnabled())
    {
        QPushButton::mousePressEvent(event);
        this->setEnabled(true);
        return;
    }
}
