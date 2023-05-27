#include "donutchart.h"
#include "StatisticsWindow/Forms/DonutChart/Slice/slice.h"
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtCharts/QChartView>



DonutChart::DonutChart(const std::vector<std::pair<QString, double>> &spendings)
{
    drawDonut(spendings);
}

double calcSize(double totalSpendings, double amount);
double calcTotalAmount(const std::vector<std::pair<QString, double>> &spendings);

void DonutChart::drawDonut(const std::vector<std::pair<QString, double>> &spendings)
{
    QPieSeries *series = new QPieSeries();
    series->setHoleSize(0.54);


    int totalSpendings = calcTotalAmount(spendings);
    for (const auto &entry : spendings)
    {
        double sizePerc = calcSize(totalSpendings, entry.second);
        Slice *slice(new Slice(entry.first, sizePerc));
        slice->setPen(QPen(Qt::white, 1, Qt::SolidLine));
        if(sizePerc < 0.04)
            slice->setLabelVisible(false);
        series->append(slice);
    }

    QChart *donut = new QChart();
    donut->addSeries(series);
    donut->setAnimationOptions(QChart::SeriesAnimations);
    donut->legend()->hide();

    QColor customColor(25, 25, 25); // RGB values for custom color
    donut->setBackgroundBrush(QBrush(customColor));

    chartView = new QChartView(donut);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setStyleSheet("background-color: rgb(25,25,25);");

    QMargins margins(0, 0, 0, 0);
    chartView->chart()->setMargins(margins);
}



double calcSize(double totalSpendings, double amount){
    return amount/totalSpendings;
}

double calcTotalAmount(const std::vector<std::pair<QString, double>> &spendings){
    double totalSpendings = 0;
    for(const auto &entry : spendings)
    {
        totalSpendings += entry.second;
    }
    return totalSpendings;
}










