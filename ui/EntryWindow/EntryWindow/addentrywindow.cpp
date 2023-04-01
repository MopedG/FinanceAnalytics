#include "addentrywindow.h"
#include "EntryWindow/EntryForm/entryform.h"
#include "EntryWindow/EntryController/entrycontroller.h"
#include "ui_addentrywindow.h"

#include <QMessageBox>
#include <QPixmap>

AddEntryWindow::AddEntryWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::addEntryWindow)
{
    controller = std::make_unique<EntryController>();
    AddEntryWindow::connect(controller.get(), &EntryController::raiseError, this, &AddEntryWindow::on_raiseError);
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
    setUpConnections();
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
    displayError(errorMessage);
}

void AddEntryWindow::setEntryFormAttributes()
{
    ui->cellLayout_2->setAlignment(Qt::AlignTop);
    ui->cellLayout_2->addWidget(entryForm, 0, Qt::AlignTop);
    entryForm->setAttribute(Qt::WA_DeleteOnClose, true);
    entryForm->disableCancelEdit();
}

void AddEntryWindow::setUpConnections()
{
    AddEntryWindow::connect(entryForm, &EntryForm::openEntryForm, this, &AddEntryWindow::on_openEntryForm);
    AddEntryWindow::connect(entryForm, &EntryForm::saveEntry, this, &AddEntryWindow::on_saveEntry);
    AddEntryWindow::connect(entryForm, &EntryForm::editEntry, this, &AddEntryWindow::on_editEntry);
    AddEntryWindow::connect(entryForm, &EntryForm::closeEntryForm, this, &AddEntryWindow::on_closeEntryForm);

}

void AddEntryWindow::displayError(const QString &errorMessage)
{
    QPixmap pixmap = QPixmap(":/assets/inputError.jpg");
    QMessageBox error;
    error.setIcon(QMessageBox::Information);
    error.setWindowTitle("An error has occured.");
    error.setInformativeText(errorMessage);
    error.setIconPixmap(pixmap);
    error.setStyleSheet("font-weight: bold; color:white; background-color: #3f4145");
    error.exec();
}

void AddEntryWindow::on_confimAllButton_clicked()
{
    QString month = ui->monthEdit->text();
    int year = ui->yearEdit->text().toInt();
    bool success = controller->finishUpEntrys(month, year);
    if(success)
        emit backToMain();
}

