#include "statisticswindow.h"
#include "ui_statisticswindow.h"
#include "EntryWindow/EntryDatahandler/entrydata.h"
#include "Repository/refactorer/refactorer.h"
#include "validator/validator.h"
#include "StatisticsWindow/Forms/MonthCard/monthcard.h"
#include "StatisticsWindow/Forms/SpendingForm/spendingform.h"

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
        updateSpendingForms(Refactorer::createSpendingsList(data, monthCardActive->getMonth()));
}

void StatisticsWindow::updateMonthCard(const QStringList &dates)
{
    removeMonthCards();
    createMonthCards(dates, true);
}

void StatisticsWindow::updateSpendingForms(const std::vector<std::pair<QString, double>> spendings)
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

void StatisticsWindow::createSpendingForms(const std::vector<std::pair<QString, double>> spendings)
{
    double totalSpendings = 0;
    for(const auto &entry : spendings)
    {
        spendingForm = new SpendingForm(nullptr, entry.first, entry.second);
        ui->spendingsLayout->setAlignment(Qt::AlignTop);
        ui->spendingsLayout->addWidget(spendingForm, 0, Qt::AlignTop);
        totalSpendings += entry.second;
    }
    ui->titleLabel->setText(monthCardActive->getMonth() + " " + QString::number(Validator::getCurrentYear()));
    ui->totalSpendingsLabel->setText(QString::number(totalSpendings) + " €");
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
    updateSpendingForms(Refactorer::createSpendingsList(data, monthCardActive->getMonth()));
}

