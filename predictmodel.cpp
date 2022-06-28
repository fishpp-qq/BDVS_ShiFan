#include "predictmodel.h"
#include "ui_predictmodel.h"
#include <QtCharts/QLineSeries>
#include <QtCharts/QXYSeries>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QLegend>
#include <QtCharts/QAbstractAxis>
#include <QtCharts/QSplineSeries>
#include <qgridlayout.h>
#include <QDateTimeAxis>
#include <QValueAxis>

PredictModel::PredictModel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PredictModel)
{
    ui->setupUi(this);
    WindowStyle = "QWidget{border-top-left-radius:15px;border-top-right-radius:5px;}";
    this->setStyleSheet(WindowStyle);

}

PredictModel::~PredictModel()
{
    delete ui;
}
