#ifndef PREDICTMODEL_H
#define PREDICTMODEL_H

#include <QWidget>
#include <QMainWindow>
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

namespace Ui {
class PredictModel;
}

class PredictModel : public QWidget
{
    Q_OBJECT

public:
    explicit PredictModel(QWidget *parent = 0);
    ~PredictModel();

private:
    Ui::PredictModel *ui;

    QString WindowStyle;



};

#endif // PREDICTMODEL_H
