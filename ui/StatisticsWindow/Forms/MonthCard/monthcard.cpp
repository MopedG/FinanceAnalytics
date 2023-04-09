#include "monthcard.h"
#include "ui_monthcard.h"

MonthCard::MonthCard(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MonthCard)
{
    ui->setupUi(this);
}

MonthCard::~MonthCard()
{
    delete ui;
}

void MonthCard::on_selectButton_clicked()
{
    if(buttonChecked == false)
    {
        setButtonChecked(true);

    }
    else
    {
        setButtonChecked(false);
    }

}

void MonthCard::setButtonChecked(bool check)
{
    ui->selectButton->setChecked(check);
    buttonChecked = check;
}

