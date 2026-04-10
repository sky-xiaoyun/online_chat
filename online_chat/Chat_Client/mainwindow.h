#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_connectButton_clicked();    // 连接服务器
    void on_sendButton_clicked();       // 发送消息
    void on_disconnectButton_clicked();
    void onConnected();                 // 连接成功
    void onReadyRead();                 // 收到消息
    void onDisconnected();                // 断开服务器连接
    void onError(QAbstractSocket::SocketError); // 错误处理

    void onUserListDoubleClicked(const QModelIndex& index); //双击进入用户信息界面
    void on_backToGroupButton_clicked();                    //返回群聊信息
    void on_privateMsgSendButton_clicked();                 //发送私聊消息

    void on_pushButton_clicked();

    void on_praviteMsgSendButton_clicked();

private:
    void appendMessage(const QString &msg);  // 显示消息
    void updateUserList(const QStringList& users);
    QString m_currentPrivateTarget;     //当前私聊对象用户名
    QString m_privateHistory;           //存储私聊记录

private:
    Ui::MainWindow *ui;
    QTcpSocket *m_socket;
    QString m_username;                     // 当前用户名
};
#endif // MAINWINDOW_H
