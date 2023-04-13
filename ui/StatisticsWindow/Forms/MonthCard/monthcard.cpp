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
}

void MonthCard::activate()
{
    ui->selectButton->setChecked(true);
}

QString MonthCard::getMonth()
{
    QStringList dataParts = ui->dateLabel->text().split(" ");
    return dataParts[0];

}

void MonthCard::on_selectButton_clicked()
{
    emit monthCardActivated(this);
}


