#include "whitelistmessagebox.h"
#include "ui_whitelistmessagebox.h"
#include <QDialogButtonBox>

WhiteListMessageBox::WhiteListMessageBox(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WhiteListMessageBox)
{
    ui->setupUi(this);
    //setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowTitleHint | Qt::WindowCloseButtonHint);
    //setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowTitleHint | Qt::WindowStaysOnTopHint);
    setWindowFlags(Qt::FramelessWindowHint);
    setWindowTitle("Category Whitelist");

}

WhiteListMessageBox::~WhiteListMessageBox()
{
    delete ui;
}

void WhiteListMessageBox::setMessage(const QString &message)
{
    ui->errorMessageLabel->setText(message);
}

bool WhiteListMessageBox::getStatus()
{
    return addToWhitelist;
}

void WhiteListMessageBox::on_confirmButton_clicked()
{
    addToWhitelist = true;
    emit enableEntryWindow();
    accept();
    close();
}


void WhiteListMessageBox::on_discardButton_clicked()
{
    addToWhitelist = false;
    emit enableEntryWindow();
    reject();
    close();
}
