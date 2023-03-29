#include "entryform.h"
#include "ui_entryform.h"

EntryForm::EntryForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EntryForm)
{
    ui->setupUi(this);
}

EntryForm::~EntryForm()
{
    delete ui;
}

void EntryForm::disableCancelEdit()
{
    ui->cancelButton->setDisabled(true);
    ui->editButton->setDisabled(true);
}

void EntryForm::on_submitButton_clicked()
{
    emit openNewEntryForm();
}

