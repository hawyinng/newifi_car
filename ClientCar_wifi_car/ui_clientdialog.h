/********************************************************************************
** Form generated from reading UI file 'clientdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENTDIALOG_H
#define UI_CLIENTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Clientdialog
{
public:
    QWidget *centralWidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *pushButton_stop;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_up;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *pushButton_down;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *pushButton_left;
    QPushButton *pushButton_right;
    QSpacerItem *horizontalSpacer_2;
    QRadioButton *radioButton;
    QWidget *gridLayoutWidget_4;
    QGridLayout *gridLayout_4;
    QGroupBox *groupBox;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *radioPlan1;
    QRadioButton *radioPlan2;
    QRadioButton *radioPlan3;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QPushButton *planRun;
    QPushButton *planStop;
    QWidget *gridLayoutWidget_5;
    QGridLayout *gridLayout_5;
    QSpacerItem *horizontalSpacer_3;
    QGridLayout *gridLayout_2;
    QPushButton *closeButton;
    QPushButton *connButton;
    QTextBrowser *textBrowser;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menuClientCar;

    void setupUi(QMainWindow *Clientdialog)
    {
        if (Clientdialog->objectName().isEmpty())
            Clientdialog->setObjectName(QString::fromUtf8("Clientdialog"));
        Clientdialog->resize(1080, 1920);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Clientdialog->sizePolicy().hasHeightForWidth());
        Clientdialog->setSizePolicy(sizePolicy);
        Clientdialog->setMinimumSize(QSize(200, 100));
        centralWidget = new QWidget(Clientdialog);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(20, 990, 1041, 771));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_7, 2, 3, 1, 1);

        pushButton_stop = new QPushButton(gridLayoutWidget);
        pushButton_stop->setObjectName(QString::fromUtf8("pushButton_stop"));
        pushButton_stop->setMinimumSize(QSize(320, 200));

        gridLayout->addWidget(pushButton_stop, 2, 4, 1, 2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 7, 1, 1);

        pushButton_up = new QPushButton(gridLayoutWidget);
        pushButton_up->setObjectName(QString::fromUtf8("pushButton_up"));
        pushButton_up->setMinimumSize(QSize(320, 200));
        pushButton_up->setIconSize(QSize(16, 16));

        gridLayout->addWidget(pushButton_up, 0, 4, 1, 2);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_6, 2, 6, 1, 1);

        pushButton_down = new QPushButton(gridLayoutWidget);
        pushButton_down->setObjectName(QString::fromUtf8("pushButton_down"));
        pushButton_down->setMinimumSize(QSize(320, 200));

        gridLayout->addWidget(pushButton_down, 4, 4, 1, 2);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 4, 0, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 4, 7, 1, 1);

        pushButton_left = new QPushButton(gridLayoutWidget);
        pushButton_left->setObjectName(QString::fromUtf8("pushButton_left"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton_left->sizePolicy().hasHeightForWidth());
        pushButton_left->setSizePolicy(sizePolicy1);
        pushButton_left->setMinimumSize(QSize(320, 200));

        gridLayout->addWidget(pushButton_left, 2, 0, 1, 1);

        pushButton_right = new QPushButton(gridLayoutWidget);
        pushButton_right->setObjectName(QString::fromUtf8("pushButton_right"));
        sizePolicy1.setHeightForWidth(pushButton_right->sizePolicy().hasHeightForWidth());
        pushButton_right->setSizePolicy(sizePolicy1);
        pushButton_right->setMinimumSize(QSize(320, 200));

        gridLayout->addWidget(pushButton_right, 2, 7, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 3, 1, 1);

        radioButton = new QRadioButton(gridLayoutWidget);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setEnabled(true);
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(radioButton->sizePolicy().hasHeightForWidth());
        radioButton->setSizePolicy(sizePolicy2);
        radioButton->setMinimumSize(QSize(0, 0));
        QFont font;
        font.setPointSize(18);
        font.setBold(false);
        font.setUnderline(false);
        font.setWeight(50);
        font.setKerning(true);
        radioButton->setFont(font);
        radioButton->setAutoFillBackground(false);
        radioButton->setStyleSheet(QString::fromUtf8("QRadioButton{\n"
"    spacing: -30px;\n"
"    color: black;\n"
"}\n"
"QRadioButton::indicator {\n"
"    width: 200px;\n"
"    height: 200px;\n"
"}\n"
"QRadioButton::indicator:unchecked {\n"
"    image: url(:/Images/switchOff.png);\n"
"}\n"
"QRadioButton::indicator:unchecked:hover {\n"
"    image: url(:/Images/switchOff.png);\n"
"}\n"
"QRadioButton::indicator:unchecked:pressed {\n"
"    image: url(:/Images/switchOff.png);\n"
"}\n"
"QRadioButton::indicator:checked {\n"
"    image: url(:/Images/switchOn.png);\n"
"}\n"
"QRadioButton::indicator:checked:hover {\n"
"    image: url(:/Images/switchOn.png);\n"
"}\n"
"QRadioButton::indicator:checked:pressed {\n"
"    image: url(:/Images/switchOn.png);\n"
"}"));
        radioButton->setIconSize(QSize(16, 16));
        radioButton->setChecked(false);

        gridLayout->addWidget(radioButton, 0, 0, 1, 1);

        gridLayoutWidget_4 = new QWidget(centralWidget);
        gridLayoutWidget_4->setObjectName(QString::fromUtf8("gridLayoutWidget_4"));
        gridLayoutWidget_4->setGeometry(QRect(30, 520, 1021, 451));
        gridLayout_4 = new QGridLayout(gridLayoutWidget_4);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        groupBox = new QGroupBox(gridLayoutWidget_4);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        QSizePolicy sizePolicy3(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy3);
        groupBox->setMinimumSize(QSize(1000, 100));
        verticalLayoutWidget_2 = new QWidget(groupBox);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(20, 60, 341, 361));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        radioPlan1 = new QRadioButton(verticalLayoutWidget_2);
        radioPlan1->setObjectName(QString::fromUtf8("radioPlan1"));
        QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(radioPlan1->sizePolicy().hasHeightForWidth());
        radioPlan1->setSizePolicy(sizePolicy4);
        radioPlan1->setMinimumSize(QSize(0, 50));
        radioPlan1->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_2->addWidget(radioPlan1);

        radioPlan2 = new QRadioButton(verticalLayoutWidget_2);
        radioPlan2->setObjectName(QString::fromUtf8("radioPlan2"));
        radioPlan2->setMinimumSize(QSize(0, 50));

        verticalLayout_2->addWidget(radioPlan2);

        radioPlan3 = new QRadioButton(verticalLayoutWidget_2);
        radioPlan3->setObjectName(QString::fromUtf8("radioPlan3"));
        radioPlan3->setMinimumSize(QSize(0, 50));

        verticalLayout_2->addWidget(radioPlan3);

        verticalLayoutWidget_3 = new QWidget(groupBox);
        verticalLayoutWidget_3->setObjectName(QString::fromUtf8("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(460, 30, 471, 414));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        planRun = new QPushButton(verticalLayoutWidget_3);
        planRun->setObjectName(QString::fromUtf8("planRun"));
        planRun->setMinimumSize(QSize(0, 100));

        verticalLayout_3->addWidget(planRun);

        planStop = new QPushButton(verticalLayoutWidget_3);
        planStop->setObjectName(QString::fromUtf8("planStop"));
        planStop->setMinimumSize(QSize(0, 100));

        verticalLayout_3->addWidget(planStop);


        gridLayout_4->addWidget(groupBox, 0, 0, 1, 1);

        gridLayoutWidget_5 = new QWidget(centralWidget);
        gridLayoutWidget_5->setObjectName(QString::fromUtf8("gridLayoutWidget_5"));
        gridLayoutWidget_5->setGeometry(QRect(30, 10, 1016, 491));
        gridLayout_5 = new QGridLayout(gridLayoutWidget_5);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_3, 2, 2, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        closeButton = new QPushButton(gridLayoutWidget_5);
        closeButton->setObjectName(QString::fromUtf8("closeButton"));
        closeButton->setMinimumSize(QSize(400, 100));

        gridLayout_2->addWidget(closeButton, 1, 0, 1, 1);

        connButton = new QPushButton(gridLayoutWidget_5);
        connButton->setObjectName(QString::fromUtf8("connButton"));
        connButton->setMinimumSize(QSize(400, 100));

        gridLayout_2->addWidget(connButton, 0, 0, 1, 1);


        gridLayout_5->addLayout(gridLayout_2, 2, 3, 1, 1);

        textBrowser = new QTextBrowser(gridLayoutWidget_5);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setMinimumSize(QSize(600, 0));

        gridLayout_5->addWidget(textBrowser, 2, 1, 1, 1);

        Clientdialog->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(Clientdialog);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        mainToolBar->setMinimumSize(QSize(0, 0));
        Clientdialog->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Clientdialog);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Clientdialog->setStatusBar(statusBar);
        menuBar = new QMenuBar(Clientdialog);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1080, 23));
        menuClientCar = new QMenu(menuBar);
        menuClientCar->setObjectName(QString::fromUtf8("menuClientCar"));
        Clientdialog->setMenuBar(menuBar);

        menuBar->addAction(menuClientCar->menuAction());

        retranslateUi(Clientdialog);
        QObject::connect(connButton, SIGNAL(clicked()), Clientdialog, SLOT(openConn()));
        QObject::connect(closeButton, SIGNAL(clicked()), Clientdialog, SLOT(closeConn()));
        QObject::connect(planRun, SIGNAL(clicked()), Clientdialog, SLOT(plan_run()));
        QObject::connect(planStop, SIGNAL(clicked()), Clientdialog, SLOT(plan_stop()));

        QMetaObject::connectSlotsByName(Clientdialog);
    } // setupUi

    void retranslateUi(QMainWindow *Clientdialog)
    {
        Clientdialog->setWindowTitle(QCoreApplication::translate("Clientdialog", "clientdialog", nullptr));
        pushButton_stop->setText(QCoreApplication::translate("Clientdialog", "\345\201\234\346\255\242", nullptr));
        pushButton_up->setText(QCoreApplication::translate("Clientdialog", "\345\211\215\350\277\233", nullptr));
        pushButton_down->setText(QCoreApplication::translate("Clientdialog", "\345\220\216\351\200\200", nullptr));
        pushButton_left->setText(QCoreApplication::translate("Clientdialog", "\345\267\246\350\275\254", nullptr));
        pushButton_right->setText(QCoreApplication::translate("Clientdialog", "\345\217\263\350\275\254", nullptr));
        radioButton->setText(QCoreApplication::translate("Clientdialog", "\345\200\222\350\275\246", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Clientdialog", "\347\272\277\350\267\257\346\226\271\346\241\210", nullptr));
        radioPlan1->setText(QCoreApplication::translate("Clientdialog", "\346\226\271\346\241\210\344\270\200", nullptr));
        radioPlan2->setText(QCoreApplication::translate("Clientdialog", "\346\226\271\346\241\210\344\272\214", nullptr));
        radioPlan3->setText(QCoreApplication::translate("Clientdialog", "\346\226\271\346\241\210\344\270\211", nullptr));
        planRun->setText(QCoreApplication::translate("Clientdialog", "\345\220\257\345\212\250", nullptr));
        planStop->setText(QCoreApplication::translate("Clientdialog", "\345\201\234\346\255\242", nullptr));
        closeButton->setText(QCoreApplication::translate("Clientdialog", "\345\205\263\351\227\255\347\275\221\347\273\234", nullptr));
        connButton->setText(QCoreApplication::translate("Clientdialog", "\350\277\236\346\216\245\347\275\221\347\273\234", nullptr));
        menuClientCar->setTitle(QCoreApplication::translate("Clientdialog", "ClientCar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Clientdialog: public Ui_Clientdialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTDIALOG_H
