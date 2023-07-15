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
    //Testing
    QPushButton *lastChange = new QPushButton();
    lastChange->setStyleSheet("background-color: rgb(62, 62, 62);"
                              "border-bottom-left-radius: 10px;"
                              "border-bottom-std::right-radius: 10px;"
                              "color: rgb(255, 255, 255);"
                              );

    ui->lastChangedLayout->addWidget(lastChange);
    //
    ui->lastChanged->show();
    hideLastChangedAfterMilliSeconds(2500);
}

void SpendingForm::hideLastChangedAfterMilliSeconds(int milliseconds)
{
    timerHideLastChanged->start(milliseconds);
}

