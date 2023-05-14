#include "donutchart.h"
#include "StatisticsWindow/Forms/DonutChart/Slice/slice.h"
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtCharts/QChartView>



DonutChart::DonutChart(std::vector<std::shared_ptr<EntryData>>)
{
    drawDonut();
}

void DonutChart::drawDonut()
{
    QPieSeries *series = new QPieSeries();
    series->setHoleSize(0.50);


    series->setLabelsVisible();
    Slice *slice = new Slice("Shopping 128€", 4);
    Slice *slice1 = new Slice("Food 66€", 3);
    series->append(slice);
    series->append(slice1);


    QChart *donut = new QChart();
    donut->addSeries(series);
    donut->setAnimationOptions(QChart::SeriesAnimations);
    donut->setTitle("Donut Demo");
    donut->legend()->hide();

    QColor customColor(25, 25, 25); // RGB values for custom color
    donut->setBackgroundBrush(QBrush(customColor));
    QFont font("Helvetica [Cronyx]", 22, QFont::Bold);
    donut->setTitleFont(font);
    donut->setTitleBrush(QBrush(QColorConstants::White));

    chartView = new QChartView(donut);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setStyleSheet("background-color: rgb(25,25,25);");
}








