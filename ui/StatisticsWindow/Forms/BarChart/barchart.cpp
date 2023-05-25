#include "barchart.h"
#include <QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QChart>
#include "Repository/Refactorer/refactorer.h"
#include "EntryWindow/EntryDatahandler/entrydata.h"
#include "qbarcategoryaxis.h"

BarChart::BarChart(const std::vector<std::shared_ptr<EntryData>> &data)
{
    // Create a bar series to hold the data
    drawBarChart(data);
}

double calcTotalAmount(const std::vector<std::shared_ptr<EntryData>> &data, const QString &month)
{
    double total = 0;
    for(const auto &entry : data)
    {
        if((entry->getMonthYear().first + " " + QString::number(entry->getMonthYear().second)) == month)
        {
            total += entry->getAmount();
        }
    }
    return total;
}

void BarChart::drawBarChart(const std::vector<std::shared_ptr<EntryData>> &data)
{
    chartView = new QChartView;
    QBarSeries *series = new QBarSeries;
    QBarSet *barSet(new QBarSet("Jan"));
    QBarSet *barSet2(new QBarSet("Feb"));
    *barSet << 500;
    *barSet2 << 400;
    series->append(barSet);
    series->append(barSet2);
    // ...
    chartView->chart()->addSeries(series);
    chartView->chart()->createDefaultAxes();

    QBarCategoryAxis *axisX = new QBarCategoryAxis;
    QStringList categories;
    categories << "Jan" << "Feb" << "Mar" << "Apr" << "May" << "Jun";
    axisX->append(categories);
    axisX->setRange("Jan", "Jun");
    chartView->chart()->setAxisX(axisX, series);



    /*QBarCategoryAxis *axis = new QBarCategoryAxis;
    QStringList categories;
    categories << "Jan" << "Feb" << "Mär" << "Apr" << "Mai" << "Jun" << "Jul" << "Aug" << "Sep" << "Okt" << "Nov" << "Dez";
    axis->append(categories);*/


    /*QBarSeries *series(new QBarSeries());
    QStringList categories;
    categories << "Jan" << "Feb" << "Mär" << "Apr" << "Mai" << "Jun" << "Jul" << "Aug" << "Sep" << "Okt" << "Nov" << "Dez";
                      QBarCategoryAxis *axis(new QBarCategoryAxis());
    axis->append(categories);

    drawBars(data, *series, categories);
    series->setBarWidth(0.2);



    //series->setLabelsPosition(QCategoryAxis::AxisLabelsPositionOnValue);

    // Create the chart and set the bar series
    QChart *chart = new QChart();

    chart->addSeries(series);

    QColor customColor(25, 25, 25); // RGB values for custom color
    chart->setBackgroundBrush(QBrush(customColor));
    chart->legend()->hide();
    chart->setAnimationOptions(QChart::SeriesAnimations);




    chart->addAxis(axis, Qt::AlignBottom);
    series->attachAxis(axis);
    // Create a chart view to display the chart
    chartView = new QChartView(chart);
    chartView->setStyleSheet("background-color: transparent;");
    QMargins margins(0, 0, 0, 0);
    chartView->chart()->setMargins(margins);

    */

}

void BarChart::drawBars(const std::vector<std::shared_ptr<EntryData>> &data, QBarSeries &series, const QStringList &categories)
{
    QStringList dates = Refactorer::createDateList(data);
    // Iterate through the monthly spendings vector
    for(const auto &entry : dates)
    {
        double totalAmount = calcTotalAmount(data, entry);
        QBarSet *barSet(new QBarSet(entry));
        *barSet << totalAmount;

        series.append(barSet);
    }
}


