#ifndef ANALYSISCONTROL_H
#define ANALYSISCONTROL_H

#include <QWidget>

namespace Ui {
class AnalysisControl;
}

class AnalysisControl : public QWidget
{
    Q_OBJECT

public:
    explicit AnalysisControl(QWidget *parent = 0);
    ~AnalysisControl();

private:
    Ui::AnalysisControl *ui;
};

#endif // ANALYSISCONTROL_H
