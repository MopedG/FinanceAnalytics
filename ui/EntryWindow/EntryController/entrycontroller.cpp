#include "entrycontroller.h"
#include "EntryWindow/EntryForm/entryform.h"
#include "validator/validator.h"
#include "repository/datahandler/datahandler.h"
#include "EntryWindow/MessageBox/WhitelistMessageBox/whitelistmessagebox.h"
#include "EntryWindow/MessageBox/ErrorMessageBox/errormessagebox.h"


EntryController::EntryController(QStringList categoryWhiteList) : categoryWhiteList(categoryWhiteList)
{
    entryDatahandler = std::make_unique<EntryDatahandler>();
    whitelistDialog = std::make_unique<WhiteListMessageBox>();
    errorDialog = std::make_unique<ErrorMessageBox>();
}

void EntryController::saveEntry(const QString &category, double amount, int id, EntryForm &entryForm)
{
    bool entryCanBeSaved = checkEntryCorrectnes(category, amount, "Your input did not match the requirements. Please try again!");
    if(entryCanBeSaved && !Validator::categoryInWhiteList(categoryWhiteList, category))
    {
        whitelistDialog->setMessage("The category '"+category+"' is new. Press Confirm to add it to the whitelist"
                                                              " or press Discard");
        emit displayDialog(whitelistDialog);
        entryCanBeSaved = whitelistDialog->getStatus();
    }
    if(entryCanBeSaved)
    {
        categoryWhiteList.emplace_back(category);
        QString formatedCategory = firstLetterToUpper(category);
        entryDatahandler->saveEntry(formatedCategory, amount, id);
        emit entrySuccessfull(true, entryForm);
    }
    emit entrySuccessfull(false, entryForm);
}

void EntryController::editEntry(const QString &category, double amount, int id, EntryForm &entryForm)
{
    bool entryCanBeEdited = checkEntryCorrectnes(category, amount, "Your input did not match the requirements. Please try again!");
    if(entryCanBeEdited && !Validator::categoryInWhiteList(categoryWhiteList, category))
    {
        whitelistDialog->setMessage("The category '"+category+"' is new. Press Confirm to add it to the whitelist"
                                                              " or press Discard");
        emit displayDialog(whitelistDialog);
        entryCanBeEdited = whitelistDialog->getStatus();
    }
    if(entryCanBeEdited)
    {
        categoryWhiteList.emplace_back(category);
        QString formatedCategory = firstLetterToUpper(category);
        entryDatahandler->editEntry(formatedCategory, amount, id);
        emit entrySuccessfull(true, entryForm);
    }
    else
    {
        emit entrySuccessfull(false, entryForm);
        emit resetEntryForm(entryForm);
    }
}

bool EntryController::finishUpEntrys(const QString &month, int year)
{
    QString formatedMonth = firstLetterToUpper(month);
    bool dateCorrect = Validator::checkDate(formatedMonth, year);
    bool entrysEmpty = entryDatahandler->newEntryData.empty();
    if(dateCorrect && !entrysEmpty)
    {
        entryDatahandler->saveDateToEntrys(formatedMonth, year);
        Datahandler::saveEntrysToFile(entryDatahandler->newEntryData);
    }
    else if(!dateCorrect)
    {
        errorDialog->setErrorMessage("The date doesnt fit in our required format, please check and try again.");
        emit displayDialog(errorDialog);
    }
    else if(entrysEmpty){
        errorDialog->setErrorMessage("There are no entrys to be saved. Please add Entrys or return to the main menu.");
        emit displayDialog(errorDialog);
    }
    return (dateCorrect && !entrysEmpty);
}

void EntryController::deleteEntry(int id)
{
    entryDatahandler->deleteEntry(id);
}

bool EntryController::checkEntryCorrectnes(const QString &category, double amount, const QString &errorMessage)
{
    if(!Validator::checkEntry(category, amount))
    {
        errorDialog->setErrorMessage(errorMessage);
        emit displayDialog(errorDialog);
        return false;
    }
    return true;
}

void EntryController::addToCategoryWhitelist(const QString &category)
{
    categoryWhiteList.emplace_back(category);
}

QString EntryController::firstLetterToUpper(const QString &month)
{
    QString formatMonth = month;
    QString firstLetter = month.left(1);
    QString rest = month.mid(1).toLower();
    QString upperFirstLetter = firstLetter.toUpper();
    formatMonth = upperFirstLetter + rest;

    return formatMonth;
}




