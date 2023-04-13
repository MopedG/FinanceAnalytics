#include "statisticswindow.h"
#include "ui_statisticswindow.h"
#include "EntryWindow/EntryDatahandler/entrydata.h"
#include "Repository/refactorer/refactorer.h"
#include "StatisticsWindow/Forms/MonthCard/monthcard.h"
#include "StatisticsWindow/Forms/SpendingForm/spendingform.h"

StatisticsWindow::StatisticsWindow(QWidget *parent, const std::vector<std::shared_ptr<EntryData>> &data) :
    QWidget(parent),
    ui(new Ui::StatisticsWindow)
{
    ui->setupUi(this);
    initObjects(data);

}

StatisticsWindow::~StatisticsWindow()
{
    delete ui;
}

void StatisticsWindow::update(const std::vector<std::shared_ptr<EntryData>> &data)
{
    QStringList dates = Refactorer::createDateList(data);
    if(dates.size() != ui->monthLayout->count())
        updateMonthCard(dates);
}

void StatisticsWindow::updateMonthCard(const QStringList &dates)
{
    removeMonthCards();
    createMonthCards(dates, true);
}

void StatisticsWindow::initObjects(const std::vector<std::shared_ptr<EntryData>> &data)
{
    createMonthCards(Refactorer::createDateList(data));
    spendingForm = new SpendingForm();

    ui->spendingsLayout->setAlignment(Qt::AlignTop);
    ui->spendingsLayout->addWidget(spendingForm, 0, Qt::AlignTop);
}

void StatisticsWindow::createMonthCards(const QStringList &dates, bool update)
{
    auto mostRecentDateIter = dates.rbegin();
    for (auto dateIter = dates.rbegin(); dateIter != dates.rend(); ++dateIter) {
        monthCard = new MonthCard(nullptr, *dateIter);
        StatisticsWindow::connect(monthCard, &MonthCard::monthCardActivated, this, &StatisticsWindow::on_monthCardActivated);
        ui->monthLayout->setAlignment(Qt::AlignTop);
        ui->monthLayout->addWidget(monthCard, 0, Qt::AlignTop);
        if (dateIter == mostRecentDateIter && !update) {
            on_monthCardActivated(monthCard);
        }
        if(update)
        {
            if(monthCard->getMonth() == lastActiveMonthCard)
                on_monthCardActivated(monthCard);
        }
    }
}

void StatisticsWindow::removeMonthCards()
{
    QLayoutItem *monthCardItem;
    while ((monthCardItem = ui->monthLayout->takeAt(0)) != nullptr) {
        delete monthCardItem->widget();
        delete monthCardItem;
    }
    monthCardActive = nullptr;
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
}

