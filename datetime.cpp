#include "dateTime.h"

DateTime::DateTime(QWidget *parent)
    : QWidget(parent)
{
    //设置窗口标题和窗口大小
    this->setWindowTitle("时间更新显示例程");
    this->resize(500, 100);

    //创建label对象显示时间和日期
    label = new QLabel(this);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(label);
    this->setLayout(layout);

    //初始化时间和日期显示
    dateTime = QDateTime::currentDateTime();
    this->label->setText(dateTime.toString("yyyy-MM-dd hh:mm:ss ddd"));

    //创建定时器定时更新时间和日期
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &DateTime::timeUpdate);
    timer->start(1000);


}

DateTime::~DateTime()
{
    delete timer;
}

void DateTime::timeUpdate(void)
{
    dateTime = QDateTime::currentDateTime();
    this->label->setText(dateTime.toString("yyyy-MM-dd hh:mm:ss ddd"));
}


