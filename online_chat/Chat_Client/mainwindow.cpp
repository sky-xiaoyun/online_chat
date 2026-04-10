#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_socket(new QTcpSocket(this))
{
    ui->setupUi(this);
    ui->sendButton->setEnabled(false);
    ui->msgLineEdit->setEnabled(false);
    ui->stackedWidget->setCurrentIndex(0);

    // 连接信号
    connect(m_socket, &QTcpSocket::connected, this, &MainWindow::onConnected);
    connect(m_socket, &QTcpSocket::readyRead, this, &MainWindow::onReadyRead);
    connect(m_socket, &QTcpSocket::errorOccurred, this, &MainWindow::onError);
    connect(m_socket, &QTcpSocket::disconnected, this, &MainWindow::onDisconnected);

    connect(ui->userListWidget, &QListWidget::doubleClicked, this, &MainWindow::onUserListDoubleClicked);   //连接用户双击的用户信号
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_connectButton_clicked()
{
    QString host = ui->hostLineEdit->text();
    quint16 port = ui->portLineEdit->text().toUShort();
    m_username = ui->nameLineEdit->text().trimmed();
    if (m_username.isEmpty()) {
        m_username = "匿名";
    }

    m_socket->connectToHost(host, port);
    ui->connectButton->setEnabled(false);
    ui->hostLineEdit->setEnabled(false);
    ui->portLineEdit->setEnabled(false);
    ui->nameLineEdit->setEnabled(false);
    ui->disconnectButton->setEnabled(true);
    appendMessage("正在连接服务器...");
}

void MainWindow::onConnected()
{
    appendMessage("连接成功！");
    ui->sendButton->setEnabled(true);
    ui->msgLineEdit->setEnabled(true);
    // 可选：发送用户名（本例使用消息格式直接带上用户名）
    // 也可以发送一条系统消息通知服务器，这里我们直接让用户在发送时自己带上用户名
    m_socket->write(QString("LOGIN|" + m_username).toUtf8());
}

void MainWindow::on_sendButton_clicked()
{
    QString msg = ui->msgLineEdit->text().trimmed();
    if (msg.isEmpty()) return;

    // 组装消息：用户名: 内容
    QString fullMsg = m_username + ": " + msg;
    m_socket->write(fullMsg.toUtf8());
    ui->msgLineEdit->clear();
    // 本地也显示自己发送的消息（可选，因为服务器会广播回来，但为了即时显示可以先本地显示）
    // 这里我们选择本地显示，防止网络延迟造成自我消息显示滞后
    //appendMessage(fullMsg);
}

void MainWindow::on_disconnectButton_clicked()
{
    if (m_socket->state() == QTcpSocket::ConnectedState ||
        m_socket->state() == QTcpSocket::ConnectingState) {
        m_socket->disconnectFromHost();  // 优雅断开
        // 或者 m_socket->close();  // 立即断开
    }
    // UI 状态在 disconnected 信号中重置，这里只禁用按钮避免重复点击
    ui->disconnectButton->setEnabled(false);
    ui->sendButton->setEnabled(false);
    // 可选：显示提示
}

void MainWindow::onReadyRead()
{
    QByteArray data = m_socket->readAll();
    QString msg = QString::fromUtf8(data);

    qDebug()<<"收到原始数据"<< msg <<"------------86";

    if(msg.startsWith("USERLIST|"))
    {
        QStringList users = msg.mid(9).split("," , Qt::SkipEmptyParts);
        updateUserList(users);
    }
    else if(!m_username.isEmpty())
    {
        appendMessage(msg);
    }
}

void MainWindow::onDisconnected()
{
    ui->userListWidget->clear();
    // 重置所有 UI 状态，允许重新连接
    ui->connectButton->setEnabled(true);
    ui->disconnectButton->setEnabled(false);
    ui->hostLineEdit->setEnabled(true);
    ui->portLineEdit->setEnabled(true);
    ui->nameLineEdit->setEnabled(true);
    ui->sendButton->setEnabled(false);
    appendMessage("已断开连接");
}

void MainWindow::onError(QAbstractSocket::SocketError)
{
    appendMessage("连接错误：" + m_socket->errorString());
    // 恢复界面状态
    ui->connectButton->setEnabled(true);
    ui->hostLineEdit->setEnabled(true);
    ui->portLineEdit->setEnabled(true);
    ui->nameLineEdit->setEnabled(true);
    ui->sendButton->setEnabled(false);
    ui->msgLineEdit->setEnabled(false);
}

void MainWindow::onUserListDoubleClicked(const QModelIndex &index)
{
    QString target = index.data().toString();
    if(target == m_username)
    {
        appendMessage("[系统]不能和自己聊天");
        return;
    }

    ui->stackedWidget->setCurrentIndex(1);
    m_currentPrivateTarget = target;
    ui->privateChatTitleLabel->setText(QString("正在与%1聊天").arg(target));

    //ui->privateChatTitleLabel->clear();
}

void MainWindow::on_backToGroupButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_privateMsgSendButton_clicked()
{
    QString msg = ui->privateMsgLineEdit->text().trimmed();
    if(msg.isEmpty()) return;
    if(m_currentPrivateTarget.isEmpty())
    {
        appendMessage("[错误]未选择私聊对象");
        return;
    }

    QString privateMsg = QString("PRIVATE|%1|%2").arg(m_currentPrivateTarget, msg);
    m_socket->write(privateMsg.toUtf8());
    ui->privateMsgLineEdit->clear();
}

void MainWindow::appendMessage(const QString &msg)
{
    ui->chatTextEdit->append(msg);
}

void MainWindow::updateUserList(const QStringList &users)
{
    qDebug()<<users<<"-------------131";
    ui->userListWidget->clear();
    for (const QString &user : users) {
        ui->userListWidget->addItem(user);
    }
}
