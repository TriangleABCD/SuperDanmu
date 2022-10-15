#include "danmuwidget.h"
#include "ui_danmuwidget.h"

danmuWidget::danmuWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::danmuWidget)
{
    ui->setupUi(this);

    this->setWindowTitle("弹幕");
}

danmuWidget::~danmuWidget()
{
    delete ui;
}

