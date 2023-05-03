#include "monthcard.h"
#include "ui_monthcard.h"

MonthCard::MonthCard(QWidget *parent,  const QString &date) :
    QWidget(parent),
    ui(new Ui::MonthCard)
{
    ui->setupUi(this);
    ui->dateLabel->setText(date);
}

MonthCard::~MonthCard()
{
    delete ui;
}

void MonthCard::deactivate()
{
    ui->selectButton->setChecked(false);
    buttonChecked = false;
}

void MonthCard::activate()
{
    ui->selectButton->setChecked(true);
    buttonChecked = true;
}

QString MonthCard::getMonth()
{
    QStringList dataParts = ui->dateLabel->text().split(" ");
    return dataParts[0];

}

QString MonthCard::getYear()
{
    QStringList dataParts = ui->dateLabel->text().split(" ");
    return dataParts[1];
}

void MonthCard::on_selectButton_clicked()
{
    if(!buttonChecked)
        emit monthCardActivated(this);
    else
        activate();
}


