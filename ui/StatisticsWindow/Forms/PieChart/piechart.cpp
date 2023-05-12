#include "piechart.h"
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

    series->append("Investing 230€", 6);
    series->append("Essen 60€", 2);
    series->append("Shopping 128€", 4);
    series->setLabelsVisible();


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
}



void PieChart::drawPie()
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
    //slice1->setPen(QPen(Qt::darkGreen,2));
    //slice1->setBrush(Qt::green);

    QPieSlice *slice2 = series->slices().at(2);
    slice2->setLabelVisible(true);

    QList<QColor> colors = {QColor(244, 67, 54), QColor(33, 150, 243), QColor(76, 175, 80)};
    for (int i = 0; i < series->count(); i++) {
        series->slices().at(i)->setColor(colors.at(i));
    }

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Ausgaben");
    chart->legend()->hide();
    QFont font("Helvetica [Cronyx]", 22, QFont::Bold);
    chart->setTitleFont(font);
    chart->setTitleBrush(QBrush(Qt::white));


    QColor customColor(25, 25, 25); // RGB values for custom color
    chart->setBackgroundBrush(QBrush(customColor));

    chartView = new QChartView(chart);
    chartView->setStyleSheet("background-color: rgb(25,25,25);");
    chartView->setRenderHint(QPainter::Antialiasing);
}

//update function






