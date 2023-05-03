#pragma once

#include <vector>
#include "EntryWindow/EntryDatahandler/entrydata.h"

class Refactorer
{
public:
    Refactorer();

    static std::vector<std::shared_ptr<EntryData>> combineEntriesByCategory(const std::vector<std::shared_ptr<EntryData>> &entryData);
    static QStringList createWhiteList(const std::vector<std::shared_ptr<EntryData>> &entryData);
    static QStringList createDateList(const std::vector<std::shared_ptr<EntryData>> &entryData);
    static std::vector<std::pair<QString, double>> createSpendingsList(const std::vector<std::shared_ptr<EntryData>> &entryData, const QString &month, int year);
};


