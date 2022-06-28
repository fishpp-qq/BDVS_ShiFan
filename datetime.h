#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QDateTime>
#include <QDebug>
#include <QTimer>
#include <QLabel>
#include <QVBoxLayout>
#include <QApplication>

class DateTime : public QWidget
{
    Q_OBJECT

public:
    DateTime(QWidget *parent = nullptr);
    ~DateTime();

    void timeUpdate(void);

private:
    QDateTime dateTime;
    QTimer *timer;
    QLabel *label;
};
#endif

