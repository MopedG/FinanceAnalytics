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
    bool entryCanBeSaved = checkEntryCorrectnes(category, amount, "Der Eintrag konnte wegen falschem Input nicht gespeichert werden. "
                                                                  "Bitte versuchen sie es erneut!");
    if(entryCanBeSaved && !Validator::categoryInWhiteList(categoryWhiteList, category))
    {
        whitelistDialog->setMessage("Die Kategorie '"+category+"' ist noch nicht bekannt. Bestätige, um es der Whitelist hinzuzufügen.");
        emit displayDialog(whitelistDialog);
        entryCanBeSaved = whitelistDialog->getStatus();
    }
    if(entryCanBeSaved)
    {
        addToCategoryWhitelist(category);

        entryDatahandler->saveEntry(category, amount, id);
        emit entrySuccessfull(true, entryForm);
    }
    emit entrySuccessfull(false, entryForm);
}

void EntryController::editEntry(const QString &category, double amount, int id, EntryForm &entryForm)
{
    bool entryCanBeEdited = checkEntryCorrectnes(category, amount, "Der Eintrag konnte wegen falschem Input nicht gespeichert werden. "
                                                                   "Bitte versuchen sie es erneut!");
    if(entryCanBeEdited && !Validator::categoryInWhiteList(categoryWhiteList, category))
    {
        whitelistDialog->setMessage("Die Kategorie '"+category+"' ist noch nicht bekannt. Bestätige, um es der Whitelist hinzuzufügen.");
        emit displayDialog(whitelistDialog);
        entryCanBeEdited = whitelistDialog->getStatus();
    }
    if(entryCanBeEdited)
    {
        addToCategoryWhitelist(category);
        entryDatahandler->editEntry(category, amount, id);
        emit entrySuccessfull(true, entryForm);
    }
    else
    {
        emit entrySuccessfull(false, entryForm);
        emit resetEntryForm(entryForm);
    }
}

bool EntryController::finishUpEntrys(const QString &month, int year, bool unsubmittedEdits)
{
    QString formatedMonth = firstLetterToUpper(month);
    bool dateCorrect = Validator::checkDate(formatedMonth, year);
    bool entrysEmpty = entryDatahandler->newEntryData.empty();
    if(dateCorrect && !entrysEmpty && !unsubmittedEdits)
    {
        entryDatahandler->saveDateToEntrys(formatedMonth, year);
        bool writingDataSuccessfull = Datahandler::saveEntrysToFile(entryDatahandler->newEntryData);
        if(!writingDataSuccessfull)
        {
            errorDialog->setErrorMessage("Beim Speichern der Daten ist ein Problem aufgetreten. Bitte kontaktieren Sie den Publisher.");
            emit displayDialog(errorDialog);
            emit filePathError();
        }
    }
    else if(!dateCorrect)
    {
        errorDialog->setErrorMessage("Das Datum passt nicht in unser Format. Bitte korrigieren sie dieses.");
        emit displayDialog(errorDialog);
    }
    else if(entrysEmpty){
        errorDialog->setErrorMessage("Wir konnten keine Einträge zum Speichern finden. "
                                     "Fügen Sie Einträge hinzu oder kehren Sie zum Menü zurück!");
        emit displayDialog(errorDialog);
    }
    else if(unsubmittedEdits)
    {
        errorDialog->setErrorMessage("Sie haben ungespeicherte Änderungen, die sonst verloren gehen würden. "
                                     "Bitte bestätigen sie diese, bevor Sie auf weiter klicken.");
        emit displayDialog(errorDialog);
    }
    return (dateCorrect && !entrysEmpty && !unsubmittedEdits);
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






