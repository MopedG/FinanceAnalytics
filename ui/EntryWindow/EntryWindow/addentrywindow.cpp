#include "addentrywindow.h"
#include "EntryWindow/EntryForm/entryform.h"
#include "EntryWindow/EntryController/entrycontroller.h"
#include "Repository/Refactorer/refactorer.h"
#include "Time/time.h"
#include "ui_addentrywindow.h"

AddEntryWindow::AddEntryWindow(QWidget *parent, std::vector<std::shared_ptr<EntryData>> data) :
    QWidget(parent),
    ui(new Ui::addEntryWindow)
{
    initializeClasses(Refactorer::createWhiteList(data));
    setUpInitialConnections();
    ui->setupUi(this);
    ui->yearEdit->setText(QString::number(Time::getCurrentYear()));

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

void AddEntryWindow::on_saveEntry(const QString &category, double amount, int id, EntryForm &entryForm)
{
    controller->saveEntry(category, amount, id, entryForm);
}

void AddEntryWindow::on_editEntry(const QString &category, double amount, int id, EntryForm &entryForm)
{
   controller->editEntry(category, amount, id, entryForm);
}

void AddEntryWindow::on_closeEntryForm(EntryForm &entryForm)
{
    controller->deleteEntry(entryForm.id);
    entryForm.close();
}

void AddEntryWindow::setEntryFormAttributes()
{
    ui->formLayout->setAlignment(Qt::AlignTop);
    ui->formLayout->addWidget(entryForm, 0, Qt::AlignTop);
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
    AddEntryWindow::connect(controller.get(), &EntryController::displayDialog, this, &AddEntryWindow::on_displayDialog);
    AddEntryWindow::connect(controller.get(), &EntryController::entrySuccessfull, this, &AddEntryWindow::on_entrySuccessfull);
    AddEntryWindow::connect(controller.get(), &EntryController::resetEntryForm, this, &AddEntryWindow::on_resetEntryForm);
    AddEntryWindow::connect(controller.get(), &EntryController::filePathError, this, &AddEntryWindow::filePathError);
}

void AddEntryWindow::initializeClasses(const QStringList &categoryWhiteList)
{
    controller = std::make_unique<EntryController>(categoryWhiteList);
}

bool AddEntryWindow::checkForUnsubmittedEdits()
{
    EntryForm *entryForm;
    bool unsubmittedEdits = false;
    for(int i = 0; i < ui->formLayout->count(); i++)
    {
        entryForm = qobject_cast<EntryForm*>(ui->formLayout->itemAt(i)->widget());
        unsubmittedEdits = entryForm->checkForUnsibmittedEdit();
        if(unsubmittedEdits)
            break;
    }
    return unsubmittedEdits;
}

void AddEntryWindow::on_displayDialog(std::shared_ptr<QDialog> dialog)
{
    setEnabled(false);
    dialog->exec();
    setEnabled(true);
}

void AddEntryWindow::on_resetEntryForm(EntryForm &entryForm)
{
    entryForm.reset();
}

void AddEntryWindow::on_confimAllButton_clicked()
{
    QString month = ui->monthEdit->text();
    int year = ui->yearEdit->text().toInt();
    bool success = controller->finishUpEntrys(month, year, checkForUnsubmittedEdits());
    if(success)
        emit backToMain(true);
}

void AddEntryWindow::on_homeButton_clicked()
{
    emit backToMain(false);
}

void AddEntryWindow::on_entrySuccessfull(bool successfull, EntryForm &entryForm)
{
    if(successfull)
        entryForm.operationSuccessfull(true);
     else
        entryForm.operationSuccessfull(false);
}


