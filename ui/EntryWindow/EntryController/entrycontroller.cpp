#include "entrycontroller.h"
#include "validator/validator.h"
#include "repository/datahandler/datahandler.h"


EntryController::EntryController(QStringList categoryWhiteList) : categoryWhiteList(categoryWhiteList)
{
    entryDatahandler = std::make_unique<EntryDatahandler>();
}

void EntryController::saveEntry(const QString &category, double amount, int id)
{
    QString formatedCategory = firstLetterToUpper(category);
    entryDatahandler->saveEntry(formatedCategory, amount, id);
}

void EntryController::editEntry(const QString &category, double amount, int id)
{
    QString formatedCategory = firstLetterToUpper(category);
    entryDatahandler->editEntry(formatedCategory, amount, id);
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
        emit raiseError("The date doesnt fit in our required format, please check and try again.");
    }
    else if(entrysEmpty){
        emit raiseError("There are no entrys to be saved. Please add Entrys or return to the main menu.");
    }
    return (dateCorrect && !entrysEmpty);
}

void EntryController::deleteEntry(int id)
{
    entryDatahandler->deleteEntry(id);
}

bool EntryController::checkCategoryWhitelist(const QString &category)
{
    bool passedProcedure = Validator::categoryInWhiteList(categoryWhiteList, category);
    return passedProcedure;
}

bool EntryController::checkEntryCorrectnes(const QString &category, double amount, const QString &errorMessage)
{
    if(!Validator::checkEntry(category, amount))
    {
        emit raiseError(errorMessage);
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



