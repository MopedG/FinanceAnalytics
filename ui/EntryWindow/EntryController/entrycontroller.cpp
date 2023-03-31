#include "entrycontroller.h"
#include "validator/validator.h"
#include "repository/datahandler/datahandler.h"



EntryController::EntryController()
{
    entryDatahandler = std::make_unique<EntryDatahandler>();
}

bool EntryController::saveEntry(const QString &category, double amount, int id)
{
    bool entryCorrect = Validator::checkEntry(category, amount);
    if(entryCorrect)
    {
        entryDatahandler->saveEntry(category, amount, id);
    }
    else
    {
        emit raiseError("Your input did not match the requirements. Please try again!");
    }
    return entryCorrect;
}

bool EntryController::editEntry(const QString &category, double amount, int id)
{
    bool entryCorrect = Validator::checkEntry(category, amount);
    if(entryCorrect)
    {
        entryDatahandler->editEntry(category, amount, id);
    }
    else
    {
        emit raiseError("Your input did not match the requirements. Please try again!");
    }
    return entryCorrect;
}

void EntryController::finishUpEntrys(const QString &month, int year)
{
    bool dateCorrect = Validator::checkDate(month, year);
    bool entrysEmpty = entryDatahandler->newEntryData.empty();
    if(dateCorrect && !entrysEmpty)
    {
        entryDatahandler->saveDateToEntrys(month, year);
        Datahandler::saveEntrysToFile(entryDatahandler->newEntryData);
    }
    else if(!dateCorrect)
    {
        emit raiseError("The date doesnt fit in our required format, please check and try again.");
    }
    else if(entrysEmpty){
        emit raiseError("There are no entrys to be saved. Please add Entrys or return to the main menu.");
    }
}

void EntryController::deleteEntry(int id)
{
    entryDatahandler->deleteEntry(id);
}
