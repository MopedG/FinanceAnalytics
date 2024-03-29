#include "entryform.h"
#include "ui_entryform.h"
#include <iostream>

int EntryForm::instances = 0;



EntryForm::EntryForm(QWidget *parent, const QStringList &categoryWhitelist) :
    QWidget(parent),
    ui(new Ui::EntryForm)
{
    ui->setupUi(this);
    instances++;
    id = instances;
    setAutoCompletion(categoryWhitelist);
}

EntryForm::~EntryForm()
{
    instances--;
    delete ui;
}

void EntryForm::setAutoCompletion(const QStringList &categoryWhitelist)
{
    completer = std::make_unique<QCompleter>(categoryWhitelist, this);
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    completer->setCompletionMode(QCompleter::InlineCompletion);
    completer->setMaxVisibleItems(2);
    ui->categoryLineEdit->setCompleter(completer.get());
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
        this->entrySaved = true;

        if(!editPressedBefore)
        {
            emit openEntryForm();
        }
        editPressedBefore = false;
    }
}

bool EntryForm::checkForUnsibmittedEdit()
{
    if(editPressedBefore && entrySaved && ui->submitButton->isEnabled())
    {
        return true;
    }
    else
    {
        return false;
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
    QString spendingEntry = commaToDot(ui->spendingLineEdit->text());
    ui->spendingLineEdit->setText(spendingEntry); //If user entered comma, a dot should be displayed

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

QString EntryForm::commaToDot(const QString &amount)
{
    int commaIdx = amount.indexOf(',');
    if(commaIdx != -1)
    {
        QString removedComma = amount;
        removedComma[commaIdx] = '.';
        return removedComma;
    }
    else
        return amount;
}
