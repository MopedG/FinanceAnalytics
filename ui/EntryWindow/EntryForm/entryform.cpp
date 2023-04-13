#include "entryform.h"
#include "ui_entryform.h"

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

void EntryForm::operationSuccessfull(bool successfull)
{
    if(successfull)
    {
        ui->spendingLineEdit->setText(ui->spendingLineEdit->text()+"€");
        currentAmount = ui->spendingLineEdit->text();
        currentCategory = ui->categoryLineEdit->text();
        disableFields();
        disableCancelEdit(false);

        if(!editPressedBefore)
        {
            emit openEntryForm();
        }
        editPressedBefore = false;
    }
}

void EntryForm::reset()
{
    ui->categoryLineEdit->setText(currentCategory);
    ui->spendingLineEdit->setText(currentAmount);
    editPressedBefore = false;
    disableCancelEdit(false);
    disableFields();
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
    {
        emit saveEntry(categoryEntry, spendingEntry.toDouble(), id, *this);
    }
    else
    {
        emit editEntry(categoryEntry, spendingEntry.toDouble(), id, *this);
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

