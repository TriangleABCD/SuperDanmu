#ifndef DANMUWIDGET_H
#define DANMUWIDGET_H

#include <QWidget>
#include <QTcpServer>

QT_BEGIN_NAMESPACE
namespace Ui { class danmuWidget; }
QT_END_NAMESPACE

class danmuWidget : public QWidget
{
    Q_OBJECT

public:
    danmuWidget(QWidget *parent = nullptr);
    ~danmuWidget();

private:
    Ui::danmuWidget *ui;

    bool isConnected;

    QTcpServer* m_server;
    QTcpSocket* m_tcp;
};
#endif // DANMUWIDGET_H
