#include "spendingform.h"
#include "ui_spendingform.h"

SpendingForm::SpendingForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SpendingForm)
{
    ui->setupUi(this);
}

SpendingForm::~SpendingForm()
{
    delete ui;
}
