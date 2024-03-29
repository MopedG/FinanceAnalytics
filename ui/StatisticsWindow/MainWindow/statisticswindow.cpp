#include "statisticswindow.h"
#include "ui_statisticswindow.h"
#include "EntryWindow/EntryDatahandler/entrydata.h"
#include "Repository/refactorer/refactorer.h"
#include "Repository/repository.h"
#include "StatisticsWindow/Forms/MonthCard/monthcard.h"
#include "StatisticsWindow/Forms/SpendingForm/spendingform.h"
#include "StatisticsWindow/Forms/DonutChart/donutchart.h"
#include "StatisticsWindow/Forms/BarChart/barchart.h"
#include "EntryWindow/MessageBox/ErrorMessageBox/errormessagebox.h"
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
    createBarChart(data);
    if(dates.size() != ui->monthLayout->count())
    {
        updateMonthCard(dates);
        createDonutChart(data);
    }
    else
    {
        createDonutChart(data);
        updateSpendingForms(data);
    }

}

void StatisticsWindow::updateMonthCard(const QStringList &dates)
{
    removeMonthCards();
    createMonthCards(dates, true);
}

void StatisticsWindow::updateSpendingForms(const std::vector<std::shared_ptr<EntryData>> &data)
{
    removeSpendingForms();
    std::vector<std::shared_ptr<EntryData>> spendingsList =
        Refactorer::createSpendingsList(data, monthCardActive->getMonth(), monthCardActive->getYear().toInt());
    createSpendingForms(spendingsList);
}

void StatisticsWindow::initObjects(const std::vector<std::shared_ptr<EntryData>> &data)
{
    createMonthCards(Refactorer::createDateList(data));
    createBarChart(data);
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

void StatisticsWindow::createSpendingForms(const std::vector<std::shared_ptr<EntryData>> &data)
{
    double totalSpendings = 0;
    for(const auto &entry : data)
    {
        spendingForm = new SpendingForm(nullptr, entry->getCategory(), entry->getAmount(), entry->getDateChanged());
        ui->spendingsLayout->setAlignment(Qt::AlignTop);
        ui->spendingsLayout->addWidget(spendingForm, 0, Qt::AlignTop);
        totalSpendings += entry->getAmount();
    }
    ui->titleLabel->setText(monthCardActive->getMonth() + " " + monthCardActive->getYear());
    ui->totalSpendingsLabel->setText(QString::number(totalSpendings) + " €");
}

void StatisticsWindow::createDonutChart(const std::vector<std::shared_ptr<EntryData>> &data)
{
    std::vector<std::pair<QString, double>> spendingsList =
        Refactorer::createDonutList(data, monthCardActive->getMonth(), monthCardActive->getYear().toInt());
    if(!ui->pieLayout->isEmpty())
        delete ui->pieLayout->takeAt(0)->widget();
    std::unique_ptr<DonutChart> donut(new DonutChart(spendingsList));
    ui->pieLayout->addWidget(donut->chartView);
}

void StatisticsWindow::createBarChart(const std::vector<std::shared_ptr<EntryData>> &data)
{
    deleteBarChartIfNotEmpty();
    BarChart *barChart(new BarChart(data));
    ui->barchartLayout->addWidget(barChart->chartView);
}

void StatisticsWindow::deleteBarChartIfNotEmpty()
{
    if(!ui->barchartLayout->isEmpty())
    {
        QLayoutItem *BarChartItem = ui->barchartLayout->takeAt(0);
        delete BarChartItem->widget();
        delete BarChartItem;
    }
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
    std::vector<std::shared_ptr<EntryData>> spendingsList =
        Refactorer::createSpendingsList(data, monthCardActive->getMonth(), monthCardActive->getYear().toInt());
    updateSpendingForms(spendingsList);
    createDonutChart(data);
}

void openRepoFile(const QString &path)
{
    QString explorerCommand = "explorer.exe /select,\"" + path + "\"";
    QProcess::startDetached(explorerCommand);
}

void displayRepoWarning()
{
    std::unique_ptr<ErrorMessageBox>warningDialog(new ErrorMessageBox);
    warningDialog->setErrorMessage("Jegliche Änderungen in der Repository File sind unüberwacht und können zu einem Absturz der Applikation führen."
    "   \nUm Änderungen anzeigen zu lassen, starten sie bitte die Applikation neu.");
    warningDialog->setNewWindowTitle("Warning");
    warningDialog->exec();
}


void StatisticsWindow::on_openRepoButton_clicked()
{
    openRepoFile(QString::fromStdString(Repository::getRepositoryFilePath().string()));
    displayRepoWarning();
}

