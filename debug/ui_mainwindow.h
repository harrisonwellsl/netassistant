/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSplitter>
#include <QtGui/QStatusBar>
#include <QtGui/QTextBrowser>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTextBrowser *showTheResvData;
    QTextBrowser *showTheSendData;
    QSplitter *splitter;
    QSplitter *splitter_2;
    QSplitter *splitter_3;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_3;
    QLabel *ipaddrLabel;
    QSpacerItem *horizontalSpacer_3;
    QLineEdit *ipaddrLineEdit;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *multicastIpaddrLabel;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *multicastIpaddrLineEdit;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout;
    QLabel *portLabel;
    QSpacerItem *horizontalSpacer;
    QLineEdit *portLineEdit;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *startTransmitButton;
    QSpacerItem *horizontalSpacer_4;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1280, 720);
        MainWindow->setMinimumSize(QSize(1280, 720));
        MainWindow->setMaximumSize(QSize(1280, 720));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        showTheResvData = new QTextBrowser(centralWidget);
        showTheResvData->setObjectName(QString::fromUtf8("showTheResvData"));
        showTheResvData->setGeometry(QRect(620, 10, 631, 311));
        showTheSendData = new QTextBrowser(centralWidget);
        showTheSendData->setObjectName(QString::fromUtf8("showTheSendData"));
        showTheSendData->setGeometry(QRect(620, 340, 631, 311));
        splitter = new QSplitter(centralWidget);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setGeometry(QRect(10, 10, 256, 66));
        splitter->setOrientation(Qt::Vertical);
        splitter_2 = new QSplitter(splitter);
        splitter_2->setObjectName(QString::fromUtf8("splitter_2"));
        splitter_2->setOrientation(Qt::Vertical);
        splitter_3 = new QSplitter(splitter_2);
        splitter_3->setObjectName(QString::fromUtf8("splitter_3"));
        splitter_3->setOrientation(Qt::Vertical);
        layoutWidget = new QWidget(splitter_3);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        ipaddrLabel = new QLabel(layoutWidget);
        ipaddrLabel->setObjectName(QString::fromUtf8("ipaddrLabel"));

        horizontalLayout_3->addWidget(ipaddrLabel);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        ipaddrLineEdit = new QLineEdit(layoutWidget);
        ipaddrLineEdit->setObjectName(QString::fromUtf8("ipaddrLineEdit"));

        horizontalLayout_3->addWidget(ipaddrLineEdit);

        splitter_3->addWidget(layoutWidget);
        layoutWidget1 = new QWidget(splitter_3);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        multicastIpaddrLabel = new QLabel(layoutWidget1);
        multicastIpaddrLabel->setObjectName(QString::fromUtf8("multicastIpaddrLabel"));

        horizontalLayout_2->addWidget(multicastIpaddrLabel);

        horizontalSpacer_2 = new QSpacerItem(37, 14, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        multicastIpaddrLineEdit = new QLineEdit(layoutWidget1);
        multicastIpaddrLineEdit->setObjectName(QString::fromUtf8("multicastIpaddrLineEdit"));

        horizontalLayout_2->addWidget(multicastIpaddrLineEdit);

        splitter_3->addWidget(layoutWidget1);
        layoutWidget2 = new QWidget(splitter_3);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        horizontalLayout = new QHBoxLayout(layoutWidget2);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        portLabel = new QLabel(layoutWidget2);
        portLabel->setObjectName(QString::fromUtf8("portLabel"));

        horizontalLayout->addWidget(portLabel);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        portLineEdit = new QLineEdit(layoutWidget2);
        portLineEdit->setObjectName(QString::fromUtf8("portLineEdit"));

        horizontalLayout->addWidget(portLineEdit);

        splitter_3->addWidget(layoutWidget2);
        splitter_2->addWidget(splitter_3);
        splitter->addWidget(splitter_2);
        layoutWidget3 = new QWidget(centralWidget);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(10, 90, 123, 25));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        startTransmitButton = new QPushButton(layoutWidget3);
        startTransmitButton->setObjectName(QString::fromUtf8("startTransmitButton"));

        horizontalLayout_4->addWidget(startTransmitButton);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        MainWindow->setCentralWidget(centralWidget);
        layoutWidget->raise();
        showTheResvData->raise();
        showTheSendData->raise();
        splitter->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1280, 23));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\347\275\221\347\273\234\345\212\251\346\211\213", 0, QApplication::UnicodeUTF8));
        ipaddrLabel->setText(QApplication::translate("MainWindow", "IP address", 0, QApplication::UnicodeUTF8));
        multicastIpaddrLabel->setText(QApplication::translate("MainWindow", "Multicast IP", 0, QApplication::UnicodeUTF8));
        portLabel->setText(QApplication::translate("MainWindow", "Port", 0, QApplication::UnicodeUTF8));
        startTransmitButton->setText(QApplication::translate("MainWindow", "PushButton", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
