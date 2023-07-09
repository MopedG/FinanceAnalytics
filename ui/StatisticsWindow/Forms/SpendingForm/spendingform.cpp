#include "spendingform.h"
#include "ui_spendingform.h"

SpendingForm::SpendingForm(QWidget *parent, const QString &category, double amount) :
    QWidget(parent),
    ui(new Ui::SpendingForm)
{
    ui->setupUi(this);
    ui->category->setText(category);
    ui->amount->setText(QString::number(amount) + " €");
    ui->lastChanged->setText("Last Changed: 17.10.");
    ui->lastChanged->hide();
}

SpendingForm::~SpendingForm()
{
    delete ui;
}

void SpendingForm::on_category_clicked()
{
    ui->lastChanged->show();
}

