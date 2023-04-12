#include "entryform.h"
#include "ui_entryform.h"
#include "validator/validator.h"

int EntryForm::instances = 0;

EntryForm::EntryForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EntryForm)
{
    ui->setupUi(this);
    instances++;
    id = instances;
}

EntryForm::~EntryForm()
{
    instances--;
    delete ui;
}

void EntryForm::disableCancelEdit(bool disable)
{
    ui->deleteButton->setDisabled(disable);
    ui->editButton->setDisabled(disable);
}

void EntryForm::enableAddedToWhitelist(bool enable)
{
    addedToWhitelist = enable;
}

void EntryForm::disableFields(bool disable)
{
        ui->categoryLineEdit->setReadOnly(disable);
        ui->spendingLineEdit->setReadOnly(disable);
        ui->submitButton->setDisabled(disable);
}

void EntryForm::on_submitButton_clicked()
{
    QString categoryEntry = ui->categoryLineEdit->text();
    QString spendingEntry = ui->spendingLineEdit->text();

    if(!editPressedBefore)
        emit saveEntry(categoryEntry, spendingEntry.toDouble(), id);
    else
        emit editEntry(categoryEntry, spendingEntry.toDouble(), id, *this);
    if(Validator::checkEntry(categoryEntry, spendingEntry.toDouble()) && addedToWhitelist)
    {
        ui->spendingLineEdit->setText(spendingEntry+"€");
        disableFields();
        disableCancelEdit(false);
        if(!editPressedBefore)
        {
            emit openEntryForm();
        }
        editPressedBefore = false;
    }
    else
    {
        disableCancelEdit();
    }

}


void EntryForm::on_editButton_clicked()
{
    if(!editPressedBefore)
    {
        QString text = ui->spendingLineEdit->text();
        ui->spendingLineEdit->setText(text.left(text.length() -1));
        disableFields(false);
        disableCancelEdit();
        editPressedBefore =  true;
    }
}

void EntryForm::on_deleteButton_clicked()
{
    emit closeEntryForm(*this);
}

