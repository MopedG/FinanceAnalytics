#include "piechart.h"
#include "StatisticsWindow/Forms/PieChart/Slice/pieslice.h"
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtCharts/QChartView>



PieChart::PieChart() //needs data to create pie from it
{
    drawDonut();
}

void PieChart::drawDonut()
{
    QPieSeries *series = new QPieSeries();
    series->setHoleSize(0.50);


    series->setLabelsVisible();
    PieSlice *slice = new PieSlice("Shopping 128€", 4);
    PieSlice *slice1 = new PieSlice("Food 66€", 3);
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








