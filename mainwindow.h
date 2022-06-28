#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include "analysiscontrol.h"
#include "predictmodel.h"

#include <QtCharts/QXYSeries>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QLegend>
#include <QtCharts/QLineSeries>
#include <QtCharts/QAbstractAxis>
#include <QtCharts/QSplineSeries>
#include <qgridlayout.h>
#include <QDateTimeAxis>
#include <QValueAxis>
#include <QProcess>
#include <QWindow>

using namespace QtCharts;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void time_update();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;

    QLabel *CurrentTimeLabel;
    QChart *m_chart;
    QChart *m_chart1,*m_chart2;
    QLineSeries *m_seriesX;
    QLineSeries *m_seriesY;
    QLineSeries *m_distX;
    QLineSeries *m_distY;
    QChartView *chartView ;
    QChartView *chartView1, *chartView2;

    QValueAxis *axisX;                    //轴
    QValueAxis *axisY;
    QValueAxis *axisX1;
    QValueAxis *axisY1;

    QString WindowStyle;
    QGridLayout *BaseLayout;
    QGridLayout *LayoutView;

    int index_x,index_y = 0;
    int flow_x,flow_y;

    QProcess *process;
    QWindow *m_window;


};

#endif // MAINWINDOW_H
