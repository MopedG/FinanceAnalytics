#include "errormessagebox.h"
#include "ui_errormessagebox.h"

ErrorMessageBox::ErrorMessageBox(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ErrorMessageBox)
{
    ui->setupUi(this);
    setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowTitleHint | Qt::WindowCloseButtonHint);
    setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowTitleHint | Qt::WindowStaysOnTopHint);
    setWindowTitle("StupidUser Alert");
}

ErrorMessageBox::~ErrorMessageBox()
{
    delete ui;
}

void ErrorMessageBox::setErrorMessage(const QString &errorMessage)
{
    ui->errorMessageLabel->setText(errorMessage);
}

void ErrorMessageBox::on_confirmButton_clicked()
{
    close();
    emit enableEntryWindow();
}

