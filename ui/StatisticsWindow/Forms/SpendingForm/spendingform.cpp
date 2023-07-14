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
    ui->lastChanged->setText("Zul. geändert: 17.10.");
    ui->lastChanged->hide();
}

SpendingForm::~SpendingForm()
{
    delete ui;
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
    QTimer::singleShot(2500, [this]() {
        if(ui->lastChanged != nullptr)
            ui->lastChanged->hide();  // Hide the widget after 5 seconds
    });
}

