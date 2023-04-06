#include "addentrywindow.h"
#include "EntryWindow/EntryForm/entryform.h"
#include "EntryWindow/EntryController/entrycontroller.h"
#include "EntryWindow/ErrorMessageBox/ErrorMessageBox.h"
#include "ui_addentrywindow.h"

#include <QMessageBox>
#include <QPixmap>

AddEntryWindow::AddEntryWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::addEntryWindow)
{
    initializeClasses();
    setUpInitialConnections();
    ui->setupUi(this);
    on_openEntryForm();
}

AddEntryWindow::~AddEntryWindow()
{
    delete ui;
}

void AddEntryWindow::on_openEntryForm()
{
    entryForm = new EntryForm(this);
    setEntryFormAttributes();
    connectEntryForm();
}

void AddEntryWindow::on_saveEntry(const QString &category, double amount, int id)
{
    bool success;
    success = controller->saveEntry(category, amount, id);
    if(success)
        entryForm->disableCancelEdit(false);
}

void AddEntryWindow::on_editEntry(const QString &category, double amount, int id)
{
    controller->editEntry(category, amount, id);
}

void AddEntryWindow::on_closeEntryForm(EntryForm &entryForm)
{
    controller->deleteEntry(entryForm.id);
    entryForm.close();
}

void AddEntryWindow::on_raiseError(const QString &errorMessage)
{
    setEnabled(false);
    displayError(errorMessage);
}

void AddEntryWindow::setEntryFormAttributes()
{
    ui->cellLayout_2->setAlignment(Qt::AlignTop);
    ui->cellLayout_2->addWidget(entryForm, 0, Qt::AlignTop);
    entryForm->setAttribute(Qt::WA_DeleteOnClose, true);
    entryForm->disableCancelEdit();
}

void AddEntryWindow::connectEntryForm()
{
    AddEntryWindow::connect(entryForm, &EntryForm::openEntryForm, this, &AddEntryWindow::on_openEntryForm);
    AddEntryWindow::connect(entryForm, &EntryForm::saveEntry, this, &AddEntryWindow::on_saveEntry);
    AddEntryWindow::connect(entryForm, &EntryForm::editEntry, this, &AddEntryWindow::on_editEntry);
    AddEntryWindow::connect(entryForm, &EntryForm::closeEntryForm, this, &AddEntryWindow::on_closeEntryForm);

}

void AddEntryWindow::setUpInitialConnections()
{
    AddEntryWindow::connect(controller.get(), &EntryController::raiseError, this, &AddEntryWindow::on_raiseError);
    AddEntryWindow::connect(error.get(), &ErrorMessageBox::enableEntryWindow, this, &AddEntryWindow::on_enableEntryWindow);
}

void AddEntryWindow::initializeClasses()
{
    controller = std::make_unique<EntryController>();
    error = std::make_unique<ErrorMessageBox>();
}

void AddEntryWindow::displayError(const QString &errorMessage)
{
    error->setErrorMessage(errorMessage);
    error->show();
}

void AddEntryWindow::on_confimAllButton_clicked()
{
    QString month = ui->monthEdit->text();
    int year = ui->yearEdit->text().toInt();
    bool success = controller->finishUpEntrys(month, year);
    if(success)
        emit backToMain();
}

void AddEntryWindow::on_enableEntryWindow()
{
    setEnabled(true);
}


void AddEntryWindow::on_homeButton_clicked()
{
    emit backToMain();
}

