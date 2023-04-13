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

void StatisticsWindow::initObjects(const std::vector<std::shared_ptr<EntryData>> &data)
{
    initMonthCards(Refactorer::createDateList(data));
    spendingForm = new SpendingForm();

    ui->spendingsLayout->setAlignment(Qt::AlignTop);
    ui->spendingsLayout->addWidget(spendingForm, 0, Qt::AlignTop);
}

void StatisticsWindow::initMonthCards(const QStringList &dates)
{
    auto mostRecentDateIter = dates.rbegin();
    for (auto dateIter = dates.rbegin(); dateIter != dates.rend(); ++dateIter) {
        monthCard = new MonthCard(nullptr, *dateIter);
        StatisticsWindow::connect(monthCard, &MonthCard::monthCardActivated, this, &StatisticsWindow::on_monthCardActivated);
        ui->monthLayout->setAlignment(Qt::AlignTop);
        ui->monthLayout->addWidget(monthCard, 0, Qt::AlignTop);
        if (dateIter == mostRecentDateIter) {
            on_monthCardActivated(monthCard);
        }
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
}

