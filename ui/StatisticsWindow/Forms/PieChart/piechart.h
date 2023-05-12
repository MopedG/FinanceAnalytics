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

private:
    void drawDonut();
    void drawPie();
};


