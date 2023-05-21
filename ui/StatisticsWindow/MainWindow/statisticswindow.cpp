#include "statisticswindow.h"
#include "ui_statisticswindow.h"
#include "EntryWindow/EntryDatahandler/entrydata.h"
#include "Repository/refactorer/refactorer.h"
#include "StatisticsWindow/Forms/MonthCard/monthcard.h"
#include "StatisticsWindow/Forms/SpendingForm/spendingform.h"
#include "StatisticsWindow/Forms/DonutChart/donutchart.h"
#include "Repository/Writer/writer.h"
#include <memory>
#include <QProcess>

StatisticsWindow::StatisticsWindow(QWidget *parent, const std::vector<std::shared_ptr<EntryData>> &data) :
    QWidget(parent),
    ui(new Ui::StatisticsWindow)
{
    ui->setupUi(this);
    this->data = data;
    initObjects(data);

}

StatisticsWindow::~StatisticsWindow()
{
    delete ui;
}

void StatisticsWindow::update(const std::vector<std::shared_ptr<EntryData>> &data)
{
    this->data = data;
    QStringList dates = Refactorer::createDateList(data);

    if(dates.size() != ui->monthLayout->count())
        updateMonthCard(dates);
    else
    {
        createDonutChart(data);
        updateSpendingForms(Refactorer::createSpendingsList(data, monthCardActive->getMonth(), monthCardActive->getYear().toInt()));
    }

}

void StatisticsWindow::updateMonthCard(const QStringList &dates)
{
    removeMonthCards();
    createMonthCards(dates, true);
}

void StatisticsWindow::updateSpendingForms(const std::vector<std::pair<QString, double>> &spendings)
{
    removeSpendingForms();
    createSpendingForms(spendings);
}

void StatisticsWindow::initObjects(const std::vector<std::shared_ptr<EntryData>> &data)
{
    createMonthCards(Refactorer::createDateList(data));
}

void StatisticsWindow::createMonthCards(const QStringList &dates, bool update)
{
    auto mostRecentDateIter = dates.rbegin();
    for (auto dateIter = dates.rbegin(); dateIter != dates.rend(); ++dateIter) {
        monthCard = new MonthCard(nullptr, *dateIter);
        StatisticsWindow::connect(monthCard, &MonthCard::monthCardActivated, this, &StatisticsWindow::on_monthCardActivated);
        ui->monthLayout->setAlignment(Qt::AlignTop);
        ui->monthLayout->addWidget(monthCard, 0, Qt::AlignTop);
        if (dateIter == mostRecentDateIter && !update || lastActiveMonthCard.isEmpty() && dateIter == mostRecentDateIter) {
            on_monthCardActivated(monthCard);
        }
        if(update)
        {
            if(monthCard->getMonth() == lastActiveMonthCard)
                on_monthCardActivated(monthCard);
        }
    }
}

void StatisticsWindow::createSpendingForms(const std::vector<std::pair<QString, double>> &spendings)
{
    double totalSpendings = 0;
    for(const auto &entry : spendings)
    {
        spendingForm = new SpendingForm(nullptr, entry.first, entry.second);
        ui->spendingsLayout->setAlignment(Qt::AlignTop);
        ui->spendingsLayout->addWidget(spendingForm, 0, Qt::AlignTop);
        totalSpendings += entry.second;
    }
    ui->titleLabel->setText(monthCardActive->getMonth() + " " + monthCardActive->getYear());
    ui->totalSpendingsLabel->setText(QString::number(totalSpendings) + " €");
}

void StatisticsWindow::createDonutChart(const std::vector<std::shared_ptr<EntryData>> &data)
{
    std::vector<std::pair<QString, double>> spendingsList =
        Refactorer::createSpendingsList(data, monthCardActive->getMonth(), monthCardActive->getYear().toInt());
    if(!ui->pieLayout->isEmpty())
        delete ui->pieLayout->takeAt(0)->widget();
    std::unique_ptr<DonutChart> donut(new DonutChart(spendingsList));
    QMargins margins(0, 0, 0, 0);
    donut->chartView->chart()->setMargins(margins);
    ui->pieLayout->addWidget(donut->chartView);
}

void StatisticsWindow::removeMonthCards()
{
    QLayoutItem *monthCardItem;
    while((monthCardItem = ui->monthLayout->takeAt(0)) != nullptr)
    {
        delete monthCardItem->widget();
        delete monthCardItem;
    }
    monthCardActive = nullptr;
}

void StatisticsWindow::removeSpendingForms()
{
    QLayoutItem *spendingFormItem;
    while((spendingFormItem = ui->spendingsLayout->takeAt(0)) != nullptr)
    {
        delete spendingFormItem->widget();
        delete spendingFormItem;
    }
}

void StatisticsWindow::on_homeButton_clicked()
{
    emit backToMain();
}

void StatisticsWindow::on_monthCardActivated(MonthCard *activeMonthCard)
{
    if(monthCardActive != nullptr)
    {
         monthCardActive->deactivate();
    }
    monthCardActive = activeMonthCard;
    monthCardActive->activate();
    lastActiveMonthCard = monthCardActive->getMonth();
    std::vector<std::pair<QString, double>> spendingsList =
            Refactorer::createSpendingsList(data, monthCardActive->getMonth(), monthCardActive->getYear().toInt());
    updateSpendingForms(spendingsList);
    createDonutChart(data);
}

void openRepoFile(const QString &path)
{
    QString explorerCommand = "explorer.exe /select,\"" + path + "\"";
    QProcess::startDetached(explorerCommand);
}


void StatisticsWindow::on_openRepoButton_clicked()
{
    openRepoFile(QString::fromStdString(Writer::getRepositoryFilePath().string()));
}

