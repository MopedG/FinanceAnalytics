#include "errormessagebox.h"
#include "ui_errormessagebox.h"

ErrorMessageBox::ErrorMessageBox(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ErrorMessageBox)
{
    ui->setupUi(this);
    setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowTitleHint | Qt::WindowCloseButtonHint);
    setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowTitleHint | Qt::WindowStaysOnTopHint);
    setWindowTitle("Bad Request Error");
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

