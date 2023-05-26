#include "barchart.h"
#include "EntryWindow/EntryDatahandler/entrydata.h"
#include "Validator/validator.h"
#include <QtCharts/QChart>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QChartView>
#include <QtCharts/QCategoryAxis>


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
    QBarSet *set = new QBarSet("");

    QBarSeries *series = new QBarSeries();
    QChart *chart = new QChart();
    QCategoryAxis *axisX = new QCategoryAxis();
    QValueAxis *axisY = new QValueAxis();

    QString currentYear = QString::number(Validator::getCurrentYear());

    set->append(calcTotalAmount(data, "Januar "+currentYear));
    set->append(calcTotalAmount(data, "Februar "+currentYear));
    set->append(calcTotalAmount(data, "März "+currentYear));
    set->append(calcTotalAmount(data, "April "+currentYear));
    set->append(calcTotalAmount(data, "Mai "+currentYear));
    set->append(calcTotalAmount(data, "Juni "+currentYear));
    set->append(calcTotalAmount(data, "Juli "+currentYear));
    set->append(calcTotalAmount(data, "August "+currentYear));
    set->append(calcTotalAmount(data, "September "+currentYear));
    set->append(calcTotalAmount(data, "Oktober "+currentYear));
    set->append(calcTotalAmount(data, "November "+currentYear));
    set->append(calcTotalAmount(data, "Dezember "+currentYear));

    axisX->setRange(-1,12);
    axisY->setLabelsColor(Qt::white);
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
    chart->setTitle("Gesamtausgaben");
    chart->setTitleBrush(QBrush(Qt::white));
    chart->setTitleFont(QFont("Arial", 16, QFont::Bold));
    chart->legend()->setVisible(false);
    axisX->setGridLineVisible(false);
    axisY->setGridLineVisible(false);
    axisY->setLabelFormat("%.0f");
    axisX->setLabelsColor(Qt::white);
    axisY->setLabelsFont(QFont("Arial", 12, QFont::Bold));
    axisX->setLabelsFont(QFont("Arial", 12, QFont::Bold));


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


    chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setStyleSheet("background-color: rgb(25,25,25);");
    QMargins margins(0, 0, 0, 0);
    chartView->chart()->setMargins(margins);

}



