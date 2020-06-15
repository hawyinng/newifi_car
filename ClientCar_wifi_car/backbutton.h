#ifndef BACKBUTTON_H
#define BACKBUTTON_H

#include <QObject>
#include <QPushButton>

class BackButton : public QPushButton
{
    Q_OBJECT

public:
    explicit BackButton(QWidget *parent=0);

protected:
    void mousePressEvent(QMouseEvent *event);
};

#endif // BACKBUTTON_H
