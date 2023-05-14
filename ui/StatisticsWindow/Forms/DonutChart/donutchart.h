#pragma once

#include "QtCharts/qchartview.h"
#include <QObject>
#include <QWidget>

class EntryData;
class DonutChart : public QObject
{
    Q_OBJECT
public:
    DonutChart(const std::vector<std::pair<QString, double>> &spendings);

    QChartView *chartView;


private:
    void drawDonut(const std::vector<std::pair<QString, double>> &spendings);
};


