#include "piechart.h"
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtCharts/QChartView>



PieChart::PieChart()
{
    QPieSeries *series = new QPieSeries();
    series->append("Shopping", .40);
    series->append("Trade Republic", .30);
    series->append("Bison", .30);

    QPieSlice *slice0 = series->slices().at(0);
    slice0->setLabelVisible(true);

    QPieSlice *slice1 = series->slices().at(1);
    slice1->setExploded();
    slice1->setLabelVisible(true);
    slice1->setPen(QPen(Qt::darkGreen,2));
    slice1->setBrush(Qt::green);

    QPieSlice *slice2 = series->slices().at(2);
    slice2->setLabelVisible(true);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Ausgaben");
    chart->legend()->hide();

    chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
}



