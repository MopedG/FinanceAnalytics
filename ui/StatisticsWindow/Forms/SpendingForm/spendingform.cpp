#include "spendingform.h"
#include "ui_spendingform.h"

SpendingForm::SpendingForm(QWidget *parent, const QString &category, double amount) :
    QWidget(parent),
    ui(new Ui::SpendingForm)
{
    ui->setupUi(this);
    ui->category->setText(category);
    ui->amount->setText(QString::number(amount) + " €");
}

SpendingForm::~SpendingForm()
{
    delete ui;
}
