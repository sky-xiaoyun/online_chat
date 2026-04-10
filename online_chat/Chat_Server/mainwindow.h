#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpServer>
#include <QTcpSocket>
#include <QList>
#include <QMap>

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
    void on_startButton_clicked();          // 启动服务器
    void onNewConnection();                 // 新客户端连接
    void onReadyRead();                     // 客户端数据到达
    void onClientDisconnected();            // 客户端断开

private:
    void broadcastMessage(const QString &msg);  // 广播消息
    void sendUserList();

private:
    Ui::MainWindow *ui;
    QTcpServer *m_server;                   // 服务器对象
    QList<QTcpSocket*> m_clients;           // 所有连接的客户端套接字
    QMap<QTcpSocket* ,QString> m_userMap;   //记录每个socket的用户名
    QStringList m_userList;
};
#endif // MAINWINDOW_H
