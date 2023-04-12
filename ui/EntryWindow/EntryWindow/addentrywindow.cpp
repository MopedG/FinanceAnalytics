#include "addentrywindow.h"
#include "EntryWindow/EntryForm/entryform.h"
#include "EntryWindow/EntryController/entrycontroller.h"
#include "EntryWindow/MessageBox/ErrorMessageBox/ErrorMessageBox.h"
#include "EntryWindow/MessageBox/WhitelistMessageBox/whitelistmessagebox.h"
#include "Repository/Refactorer/refactorer.h"
#include "validator/validator.h"
#include "ui_addentrywindow.h"

AddEntryWindow::AddEntryWindow(QWidget *parent, std::vector<std::shared_ptr<EntryData>> data) :
    QWidget(parent),
    ui(new Ui::addEntryWindow)
{
    initializeClasses(Refactorer::createWhiteList(data));
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
    bool success = controller->checkEntryCorrectnes(category, amount, "Your input did not match the requirements. Please try again!");

    if(handleCategoryWhitelist(category, amount, *entryForm) && success)
    {
        controller->saveEntry(category, amount, id);
        entryForm->disableCancelEdit(false);
    }
    else
        entryForm->disableCancelEdit();
}

void AddEntryWindow::on_editEntry(const QString &category, double amount, int id, EntryForm &entryForm)
{
    bool success = controller->checkEntryCorrectnes(category, amount, "Your input did not match the requirements. Please try again!");
    if(handleCategoryWhitelist(category, amount, entryForm) && success)
    {
        controller->editEntry(category, amount, id);
    }
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

bool AddEntryWindow::openWhitelistDialog(const QString &message)
{
    setEnabled(false);
    return showCategoryWhitelist(message);
}

void AddEntryWindow::setEntryFormAttributes()
{
    ui->cellLayout_2->setAlignment(Qt::AlignTop);
    ui->cellLayout_2->addWidget(entryForm, 0, Qt::AlignTop);
    entryForm->setAttribute(Qt::WA_DeleteOnClose, true);
    entryForm->disableCancelEdit();
    ui->yearEdit->setText(QString::number(Validator::getCurrentYear()));
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
    AddEntryWindow::connect(whitelistMessage.get(), &WhiteListMessageBox::enableEntryWindow, this, &AddEntryWindow::on_enableEntryWindow);
}

void AddEntryWindow::initializeClasses(const QStringList &categoryWhiteList)
{
    controller = std::make_unique<EntryController>(categoryWhiteList);
    error = std::make_unique<ErrorMessageBox>();
    whitelistMessage = std::make_unique<WhiteListMessageBox>();
}

void AddEntryWindow::displayError(const QString &errorMessage)
{
    error->setErrorMessage(errorMessage);
    error->show();
}

bool AddEntryWindow::showCategoryWhitelist(const QString &message)
{
    whitelistMessage->setMessage(message);

    if(whitelistMessage->exec() == QDialog::Accepted)
        return true;
    else
        return false;
}

bool AddEntryWindow::handleCategoryWhitelist(const QString &category, const double amount, EntryForm &entryForm)
{
    bool success = false;
    if(controller->checkCategoryWhitelist(category))
    {
        entryForm.enableAddedToWhitelist(true);
        return true;
    }
    if(Validator::checkEntry(category, amount))
        success = openWhitelistDialog("The category '"+category+"' is new. Press Confirm to add it to the whitelist"
                                                              " or press Discard");
        entryForm.enableAddedToWhitelist(success);
    if(success)
    {
        controller->addToCategoryWhitelist(category);
    }
    return success;
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

