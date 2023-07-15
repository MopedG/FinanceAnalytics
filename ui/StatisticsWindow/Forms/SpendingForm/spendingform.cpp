#include "spendingform.h"
#include "ui_spendingform.h"
#include <QTimer>

SpendingForm::SpendingForm(QWidget *parent, const QString &category, double amount) :
    QWidget(parent),
    ui(new Ui::SpendingForm)
{
    ui->setupUi(this);

    ui->category->setText(category);
    ui->amount->setText(QString::number(amount) + " €");
    setUpLastChanged("Zul. geändert: 15.07.");
}

SpendingForm::~SpendingForm()
{
    timerHideLastChanged->stop();
    timerHideLastChanged.release();
    delete ui;
}

void SpendingForm::setUpLastChanged(const QString &text)
{
    ui->lastChanged->setText(text);
    ui->lastChanged->hide();
    timerHideLastChanged = std::make_unique<QTimer>();
    connect(timerHideLastChanged.get(), &QTimer::timeout, this, [this]() {
        ui->lastChanged->hide();
    });
}

void SpendingForm::on_category_clicked()
{
    ui->lastChanged->show();
    hideLastChangedAfterMilliSeconds(2500);
}

void SpendingForm::hideLastChangedAfterMilliSeconds(int milliseconds)
{
    timerHideLastChanged->start(milliseconds);
}

