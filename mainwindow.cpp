#include "mainwindow.h"
#include "analysiscontrol.h"
#include "ui_mainwindow.h"
#include "datetime.h"
#include <QLabel>
#include "stdlib.h"
#include <QtCharts/QXYSeries>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QLegend>
#include <QtCharts/QLineSeries>
#include <QtCharts/QAbstractAxis>
#include <QtCharts/QSplineSeries>
#include <windows.h>

using namespace QtCharts;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    WindowStyle = "QWidget{border-top-left-radius:15px;border-top-right-radius:5px;}";
    //this->setStyleSheet(WindowStyle);

    CurrentTimeLabel = new QLabel(); // 创建QLabel控件
    ui->statusBar->addWidget(CurrentTimeLabel);

    QTimer *timer = new QTimer(this);
    timer->start(1000);

    connect(timer, SIGNAL(timeout()),this,SLOT(time_update()));

    m_seriesX = new QLineSeries();
    m_seriesX->setName(tr("X speed"));
    m_seriesY = new QLineSeries();
    m_seriesY->setName(tr("Y speed"));
    m_distX = new QLineSeries();
    m_distX->setName(tr("X distance"));
    m_distY = new QLineSeries();
    m_distY->setName(tr("Y distance"));

    axisX = new QValueAxis();
    axisY = new QValueAxis();
    axisX1 = new QValueAxis();
    axisY1 = new QValueAxis();

    axisX->setTickCount(5);                             //设置坐标轴格数
    axisX->setRange(0,100);
    axisY->setTickCount(1);
    axisY->setMin(0);                                    //设置Y轴范围
    axisY->setMax(300);

    axisX1->setTickCount(5);
    axisX1->setRange(0,100);
    axisY1->setTickCount(1);
    axisY1->setMin(0);
    axisY1->setMax(300);

    m_chart = new QChart();
    m_chart1 = new QChart();
    m_chart2 = new QChart();

    m_chart->setEnabled(true);
    m_chart1->setEnabled(true);
    m_chart2->setEnabled(true);

    chartView = new QChartView(m_chart);
    chartView1 = new QChartView(m_chart1);
    chartView2 = new QChartView(m_chart2);

    BaseLayout = new QGridLayout();
    LayoutView = new QGridLayout();

    chartView->setMinimumSize(570, 300);
    chartView1->setMinimumSize(570, 300);
    m_chart->addSeries(m_seriesX);
    m_chart->addSeries(m_seriesY);
    m_chart1->addSeries(m_distX);
    m_chart1->addSeries(m_distY);

    m_chart->addAxis(axisX,Qt::AlignBottom);               //设置坐标轴位于chart中的位置
    m_chart->addAxis(axisY,Qt::AlignLeft);
    m_chart1->addAxis(axisX1,Qt::AlignBottom);
    m_chart1->addAxis(axisY1,Qt::AlignLeft);


    m_seriesX->attachAxis(axisX);
    m_seriesX->attachAxis(axisY);
    m_distX->attachAxis(axisX1);
    m_distX->attachAxis(axisY1);

    BaseLayout->addWidget(chartView,0,0);
    //ui->widgetWaveForm->setLayout(BaseLayout);
    ui->LineView->setLayout(BaseLayout);
    LayoutView->addWidget(chartView1,0,0);
    ui->tempView->setLayout(LayoutView);

    process = new QProcess(this);
    QString path = "E:/Project_Lab/ShiFan/heatmap/heatmap-demo.exe";
    //process->start(path,QStringList()<<"");
    if(!process->waitForFinished(3000))
    {
        qDebug()<<"open exe failed\n";
    }
    STARTUPINFO si = {sizeof(si)};
    PROCESS_INFORMATION pi;
    si.dwFlags = STARTF_USESHOWWINDOW;
    si.wShowWindow = true;

    bool bRet = CreateProcess(
                NULL,(LPWSTR)path.toStdString().c_str(),
                NULL,NULL,FALSE,CREATE_NEW_CONSOLE,
                NULL, NULL, &si, &pi
                );

    Sleep(1000);
    WId wid = (WId)FindWindow(L"Qt5153QWindowlcon",L"热力图演示");
    m_window = QWindow::fromWinId(wid);
    m_window->setFlags(m_window->flags() | Qt::CustomizeWindowHint | Qt::WindowTitleHint);

    QWidget *m_widget;
    m_widget = QWidget::createWindowContainer(m_window, this->ui->heatmap);
    m_widget->setMinimumSize(1100, 400);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

    AnalysisControl *configWindow = new AnalysisControl;
    configWindow->show();
}

void MainWindow::time_update()
{
    QDateTime current_time = QDateTime::currentDateTime();
    QString timestr = current_time.toString( "yyyy年MM月dd日 hh:mm:ss"); //设置显示的格式
    CurrentTimeLabel->setText(timestr); //设置label的文本内容为时间
    ui->label_7->setText(timestr);

    qint16 flow_x,flow_y;
    qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));
    flow_x = 100*qrand()%(300-100);
    flow_x += 100;
    flow_y = 100*qrand()%(300-100);
    flow_y += 100;
    //flow_x = 100;


    m_seriesX->append(index_x++,flow_x);
    m_distX->append(index_y++,flow_y);
    qDebug()<<"flow_y"<<flow_y;
    qDebug()<<"index_y"<<index_y;

}

void MainWindow::on_pushButton_2_clicked()
{
    PredictModel *configWindow = new PredictModel;
    configWindow->show();
}
