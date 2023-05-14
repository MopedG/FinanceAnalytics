#pragma once

#include "QtCharts/qchartview.h"
#include <QObject>
#include <QWidget>

class EntryData;
class DonutChart : public QObject
{
    Q_OBJECT
public:
    DonutChart(std::vector<std::shared_ptr<EntryData>>);

    QChartView *chartView;


private:
    void drawDonut();
};


