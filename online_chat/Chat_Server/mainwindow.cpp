#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_server(new QTcpServer(this))
{
    ui->setupUi(this);
    ui->startButton->setEnabled(true);
    ui->logTextEdit->append("服务器已启动，等待启动...");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_startButton_clicked()
{
    quint16 port = ui->portLineEdit->text().toUShort();
    if (!m_server->listen(QHostAddress::Any, port)) {
        ui->logTextEdit->append("启动失败：" + m_server->errorString());
        return;
    }
    ui->logTextEdit->append("服务器已启动，端口：" + QString::number(port));
    ui->startButton->setEnabled(false);
    connect(m_server, &QTcpServer::newConnection, this, &MainWindow::onNewConnection);
}

void MainWindow::onNewConnection()
{

    while (m_server->hasPendingConnections()) {
        QTcpSocket *client = m_server->nextPendingConnection();
        m_clients.append(client);

        // 连接信号
        connect(client, &QTcpSocket::readyRead, this, &MainWindow::onReadyRead);
        connect(client, &QTcpSocket::disconnected, this, &MainWindow::onClientDisconnected);

        // 可选：广播上线通知
        //broadcastMessage("【系统】新用户加入聊天室");
        ui->logTextEdit->append("新客户端连接：" + client->peerAddress().toString() +
                                ":" + QString::number(client->peerPort()));
    }
}

void MainWindow::onReadyRead()
{
    QTcpSocket *senderSocket = qobject_cast<QTcpSocket*>(sender());
    if (!senderSocket) return;

    QByteArray data = senderSocket->readAll();
    QString message = QString::fromUtf8(data);

    //检查是否登录消息(格式:"LOGIN|用户名")
    if(message.startsWith("LOGIN|"))
    {
        QString username = message.mid(6);
        m_userMap[senderSocket] = username;
        m_userList.append(username);

        sendUserList();

        //广播上线通知
        broadcastMessage("[系统]:" + username + "加入了聊天室");
        ui->logTextEdit->append("用户上线了:" + username);
        return;
    }

    // 广播给所有客户端（包括发送者自己，让所有人看到）
    for (QTcpSocket *client : m_clients) {
        client->write(message.toUtf8());
    }

    // 在服务器日志显示
    ui->logTextEdit->append("收到消息：" + message);
}

void MainWindow::onClientDisconnected()
{
    QTcpSocket *client = qobject_cast<QTcpSocket*>(sender());
    if (!client) return;

    QString username = m_userMap.value(client, "未知用户");
    qDebug()<<"客户端断开:"<<username;

    m_clients.removeAll(client);
    m_userList.removeAll(username);
    m_userMap.remove(client);

    qDebug()<<"当前在线用户列表:"<<m_userList;

    sendUserList();

    broadcastMessage("[系统]:" + username + "离开了聊天室");
    ui->logTextEdit->append("客户端断开连接:" + username);

    client->deleteLater();
}

void MainWindow::broadcastMessage(const QString &msg)
{
    QByteArray data = msg.toUtf8();
    for (QTcpSocket *client : m_clients) {
        client->write(data);
    }
}

void MainWindow::sendUserList()
{
    QString userListStr = m_userList.join(",");
    QString msg = "USERLIST|" + userListStr;

    QByteArray data = msg.toUtf8();
    for(QTcpSocket* client : m_clients)
    {
        client->write(data);
    }
    qDebug()<<"服务器广播:"<<userListStr;
    ui->logTextEdit->append("广播用户列表:" + userListStr);
}
