/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QWidget *widget_4;
    QVBoxLayout *verticalLayout;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *nameLineEdit;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_3;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLineEdit *portLineEdit;
    QLabel *label_2;
    QLineEdit *hostLineEdit;
    QPushButton *connectButton;
    QLabel *label_3;
    QPushButton *disconnectButton;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QVBoxLayout *verticalLayout_2;
    QTextEdit *chatTextEdit;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *msgLineEdit;
    QPushButton *sendButton;
    QWidget *page_2;
    QVBoxLayout *verticalLayout_3;
    QWidget *widget_6;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *backToGroupButton;
    QLabel *privateChatTitleLabel;
    QTextEdit *privateChatTextEdit;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *privateMsgLineEdit;
    QPushButton *privateMsgSendButton;
    QListWidget *userListWidget;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(368, 436);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName("gridLayout_2");
        widget_4 = new QWidget(centralwidget);
        widget_4->setObjectName("widget_4");
        verticalLayout = new QVBoxLayout(widget_4);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget_2 = new QWidget(widget_4);
        widget_2->setObjectName("widget_2");
        horizontalLayout = new QHBoxLayout(widget_2);
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(widget_2);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        nameLineEdit = new QLineEdit(widget_2);
        nameLineEdit->setObjectName("nameLineEdit");

        horizontalLayout->addWidget(nameLineEdit);

        horizontalSpacer_2 = new QSpacerItem(43, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        horizontalSpacer_3 = new QSpacerItem(60, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);


        verticalLayout->addWidget(widget_2);

        widget = new QWidget(widget_4);
        widget->setObjectName("widget");
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName("gridLayout");
        portLineEdit = new QLineEdit(widget);
        portLineEdit->setObjectName("portLineEdit");

        gridLayout->addWidget(portLineEdit, 1, 1, 1, 1);

        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        hostLineEdit = new QLineEdit(widget);
        hostLineEdit->setObjectName("hostLineEdit");

        gridLayout->addWidget(hostLineEdit, 0, 1, 1, 1);

        connectButton = new QPushButton(widget);
        connectButton->setObjectName("connectButton");

        gridLayout->addWidget(connectButton, 0, 2, 1, 1);

        label_3 = new QLabel(widget);
        label_3->setObjectName("label_3");

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        disconnectButton = new QPushButton(widget);
        disconnectButton->setObjectName("disconnectButton");

        gridLayout->addWidget(disconnectButton, 1, 2, 1, 1);


        verticalLayout->addWidget(widget);

        stackedWidget = new QStackedWidget(widget_4);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setLineWidth(0);
        page = new QWidget();
        page->setObjectName("page");
        verticalLayout_2 = new QVBoxLayout(page);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        chatTextEdit = new QTextEdit(page);
        chatTextEdit->setObjectName("chatTextEdit");
        chatTextEdit->setReadOnly(true);

        verticalLayout_2->addWidget(chatTextEdit);

        widget_3 = new QWidget(page);
        widget_3->setObjectName("widget_3");
        horizontalLayout_2 = new QHBoxLayout(widget_3);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 6, 0, 0);
        msgLineEdit = new QLineEdit(widget_3);
        msgLineEdit->setObjectName("msgLineEdit");

        horizontalLayout_2->addWidget(msgLineEdit);

        sendButton = new QPushButton(widget_3);
        sendButton->setObjectName("sendButton");

        horizontalLayout_2->addWidget(sendButton);


        verticalLayout_2->addWidget(widget_3);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        verticalLayout_3 = new QVBoxLayout(page_2);
        verticalLayout_3->setObjectName("verticalLayout_3");
        widget_6 = new QWidget(page_2);
        widget_6->setObjectName("widget_6");
        horizontalLayout_4 = new QHBoxLayout(widget_6);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        backToGroupButton = new QPushButton(widget_6);
        backToGroupButton->setObjectName("backToGroupButton");
        backToGroupButton->setMaximumSize(QSize(30, 30));

        horizontalLayout_4->addWidget(backToGroupButton);

        privateChatTitleLabel = new QLabel(widget_6);
        privateChatTitleLabel->setObjectName("privateChatTitleLabel");
        privateChatTitleLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_4->addWidget(privateChatTitleLabel);


        verticalLayout_3->addWidget(widget_6);

        privateChatTextEdit = new QTextEdit(page_2);
        privateChatTextEdit->setObjectName("privateChatTextEdit");

        verticalLayout_3->addWidget(privateChatTextEdit);

        widget_5 = new QWidget(page_2);
        widget_5->setObjectName("widget_5");
        horizontalLayout_3 = new QHBoxLayout(widget_5);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        privateMsgLineEdit = new QLineEdit(widget_5);
        privateMsgLineEdit->setObjectName("privateMsgLineEdit");

        horizontalLayout_3->addWidget(privateMsgLineEdit);

        privateMsgSendButton = new QPushButton(widget_5);
        privateMsgSendButton->setObjectName("privateMsgSendButton");

        horizontalLayout_3->addWidget(privateMsgSendButton);


        verticalLayout_3->addWidget(widget_5);

        stackedWidget->addWidget(page_2);

        verticalLayout->addWidget(stackedWidget);


        gridLayout_2->addWidget(widget_4, 0, 1, 1, 1);

        userListWidget = new QListWidget(centralwidget);
        userListWidget->setObjectName("userListWidget");
        userListWidget->setMaximumSize(QSize(180, 16777215));

        gridLayout_2->addWidget(userListWidget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\345\256\242\346\210\267\347\253\257", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\347\224\250\346\210\267\345\220\215 :", nullptr));
        portLineEdit->setText(QCoreApplication::translate("MainWindow", "8989", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\346\234\215\345\212\241\345\231\250IP :", nullptr));
        hostLineEdit->setText(QCoreApplication::translate("MainWindow", "127.0.0.1", nullptr));
        connectButton->setText(QCoreApplication::translate("MainWindow", "\350\277\236\346\216\245\346\234\215\345\212\241\345\231\250", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\347\253\257\345\217\243 :", nullptr));
        disconnectButton->setText(QCoreApplication::translate("MainWindow", "\346\226\255\345\274\200\350\277\236\346\216\245", nullptr));
        sendButton->setText(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201\346\266\210\346\201\257", nullptr));
        backToGroupButton->setText(QCoreApplication::translate("MainWindow", "\350\277\224\345\233\236", nullptr));
        privateChatTitleLabel->setText(QCoreApplication::translate("MainWindow", "\345\214\277\345\220\215", nullptr));
        privateMsgSendButton->setText(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201\346\266\210\346\201\257", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
