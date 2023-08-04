#include "barchart.h"
#include "EntryWindow/EntryDatahandler/entrydata.h"
#include "Time/time.h"
#include <QtCharts/QChart>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QChartView>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QLineSeries>
#include <iostream>


BarChart::BarChart(const std::vector<std::shared_ptr<EntryData>> &data)
{
    drawBarChart(data);
}

BarChart::~BarChart()
{
    std::cout << "Test \n";
}

double calcTotalAmount(const std::vector<std::shared_ptr<EntryData>> &data, const QString &month)
{
    double total = 0;
    for(const auto &entry : data)
    {
        if((entry->getMonthYear().first + QString::number(entry->getMonthYear().second)) == month)
        {
            total += entry->getAmount();
        }
    }
    return total;
}

double calcAverage(double totalAmount, int amountBars)
{
    return totalAmount/amountBars;
}

double addMonthBars(const std::vector<std::shared_ptr<EntryData>> &data, const QStringList &months, QBarSet &set)
{
    QString currentYear = QString::number(Time::getCurrentYear());
    double totalAmount = 0;
    int amountBars = 0;
    for(const auto &month : months)
    {
        double amount = calcTotalAmount(data, month+currentYear);
        (amount != 0) ? (totalAmount += amount, amountBars++) : 0;
        set.append(amount);
    }

    return calcAverage(totalAmount, amountBars);
}

void createAverageLine(double average, QBarSet &set, QChart &chart, QValueAxis *axisY)
{
    QLineSeries *lineSeries = new QLineSeries();
    lineSeries->append(0, average);
    lineSeries->append(set.count(), average);

    QPen pen(Qt::yellow);
    pen.setWidth(2);
    pen.setStyle(Qt::DashLine);
    lineSeries->setPen(pen);


    chart.addSeries(lineSeries);

    lineSeries->attachAxis(axisY);
}

void BarChart::drawBarChart(const std::vector<std::shared_ptr<EntryData>> &data)
{
    QBarSet *set = new QBarSet("");
    set->setBorderColor(Qt::transparent);
    QBarSeries *series = new QBarSeries();
    QChart *chart = new QChart();
    QCategoryAxis *axisX = new QCategoryAxis();
    QValueAxis *axisY = new QValueAxis();
    
    
    QString currentYear = QString::number(Time::getCurrentYear());
    QStringList months;
    months << "Januar"
           << "Februar"
           << "März"
           << "April"
           << "Mai"
           << "Juni"
           << "Juli"
           << "August"
           << "September"
           << "Oktober"
           << "November"
           << "Dezember";

    double average = addMonthBars(data, months, *set);

    axisX->setRange(-1,12);
    axisY->setLabelsColor(Qt::white);
    axisY->setTickCount(6);
    series->append(set);
    chart->addSeries(series);
    chart->addAxis(axisX, Qt::AlignBottom);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisX);
    series->attachAxis(axisY);
    series->setBarWidth(0.4);
    QColor customColor(25, 25, 25); // RGB values for custom color
    chart->setBackgroundBrush(QBrush(customColor));
    chart->setAnimationOptions(QChart::SeriesAnimations);

    // Set the color of the chart title text
    chart->setTitle("Gesamtausgaben " + currentYear);
    chart->setTitleBrush(QBrush(Qt::white));
    chart->setTitleFont(QFont("Arial", 18, QFont::Bold));
    chart->legend()->setVisible(false);
    axisX->setGridLineVisible(false);
    axisY->setGridLineVisible(false);
    axisY->setLabelFormat("%.0f");
    axisY->setLabelsFont(QFont("Arial", 12, QFont::Bold));
    axisX->setLabelsFont(QFont("Arial", 12, QFont::Bold));
    axisX->setLabelsColor(Qt::white);

    axisX->append("Jan", 0);
    axisX->append("Feb", 2);
    axisX->append("Mar", 2.01);
    axisX->append("Apr", 4);
    axisX->append("May", 4.01);
    axisX->append("Jun", 6);
    axisX->append("Jul", 6.01);
    axisX->append("Aug", 8);
    axisX->append("Sep", 8.01);
    axisX->append("Oct", 10);
    axisX->append("Nov", 10.01);
    axisX->append("Dec", 12);

    createAverageLine(average, *set, *chart, axisY);

    chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setStyleSheet("background-color: rgb(25,25,25);");
    QMargins margins(0, 0, 0, 0);
    chartView->chart()->setMargins(margins);

}



