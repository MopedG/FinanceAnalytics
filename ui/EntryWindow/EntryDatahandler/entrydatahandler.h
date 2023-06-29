#pragma once
#include "entrydata.h"
#include <QObject>

class EntryDatahandler
{
public:
    EntryDatahandler() = default;


    std::map<int, std::shared_ptr<EntryData>> newEntryData;

    void saveEntry(const QString &category, double amount, int id); //Needs to set the dateChanged
    void editEntry(const QString &category, double amount, int id); //Needs to set the dateChanged
    void deleteEntry(int id);
    void saveDateToEntrys(const QString &month, int year);
};


