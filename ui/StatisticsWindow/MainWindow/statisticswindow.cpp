#include "statisticswindow.h"
#include "ui_statisticswindow.h"
#include "StatisticsWindow/Forms/MonthCard/monthcard.h"
#include "StatisticsWindow/Forms/SpendingForm/spendingform.h"

StatisticsWindow::StatisticsWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StatisticsWindow)
{
    ui->setupUi(this);
    initObjects();
    initObjects();
    initObjects();
    initObjects();
    initObjects();
    initObjects();
    initObjects();
}

StatisticsWindow::~StatisticsWindow()
{
    delete ui;
}

void StatisticsWindow::initObjects()
{
    monthCard = new MonthCard();
    spendingForm = new SpendingForm();
    ui->monthLayout->setAlignment(Qt::AlignTop);
    ui->monthLayout->addWidget(monthCard, 0, Qt::AlignTop);
    ui->spendingsLayout->setAlignment(Qt::AlignTop);
    ui->spendingsLayout->addWidget(spendingForm, 0, Qt::AlignTop);
}

void StatisticsWindow::on_homeButton_clicked()
{
    emit backToMain();
}

