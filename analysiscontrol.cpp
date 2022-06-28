#include "analysiscontrol.h"
#include "ui_analysiscontrol.h"

AnalysisControl::AnalysisControl(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AnalysisControl)
{
    ui->setupUi(this);
}

AnalysisControl::~AnalysisControl()
{
    delete ui;
}
