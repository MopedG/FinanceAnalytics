#pragma once

#include "QtCharts/qchartview.h"
#include <QObject>
#include <QWidget>

class PieChart : public QObject
{
    Q_OBJECT
public:
    PieChart();

    QChartView *chartView;

};


