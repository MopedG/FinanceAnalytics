#pragma once

#include <QObject>
#include <QWidget>

class QChartView;
class QBarSeries;
class EntryData;
class BarChart : public QObject
{
    Q_OBJECT
public:
    BarChart(const std::vector<std::shared_ptr<EntryData>> &data);

    QChartView *chartView;

private:
    void drawBarChart(const std::vector<std::shared_ptr<EntryData>> &data);
    void drawBars(const std::vector<std::shared_ptr<EntryData>> &data, QBarSeries &series, const QStringList &categories);
};


