#include "refactorer.h"
#include "Sorter/sorter.h"
#include "Time/time.h"
#include <map>
#include <set>

bool addIfNotInList(std::map<QString, std::shared_ptr<EntryData>> &addedEntryData, const std::shared_ptr<EntryData> &entry)
{
    bool addedToList = false;
    const QString key = entry->getKey();
    if (addedEntryData.find(key) == addedEntryData.end()) {
        addedEntryData.insert(std::pair(key, entry));
        addedToList = true;
    }
    return addedToList;
}

void addIfInList(std::map<QString, std::shared_ptr<EntryData>> &addedEntryData, const std::shared_ptr<EntryData> &entry)
{
    const QString key = entry->getKey();
    std::shared_ptr<EntryData> existingEntry = addedEntryData.find(key)->second;

    existingEntry->setAmount(existingEntry->getAmount() + entry->getAmount());
    existingEntry->setDateChanged(Time::getCurrentDate());
    if(existingEntry->getAmount() <= 0)
        addedEntryData.erase(key);
}

std::vector<std::shared_ptr<EntryData>> Refactorer::combineEntriesByCategory(const std::vector<std::shared_ptr<EntryData>> &entryData)
{
    std::vector<std::shared_ptr<EntryData>> refactoredEntryData;
    std::map<QString, std::shared_ptr<EntryData>> addedEntryData;

        for (const auto& entry : entryData) {
            bool addedToList = addIfNotInList(addedEntryData, entry);
            if(!addedToList)
                addIfInList(addedEntryData, entry);
        }
        for (const auto& entry : addedEntryData) {
            refactoredEntryData.push_back(entry.second);
        }

        return refactoredEntryData;
}

QStringList Refactorer::createWhiteList(const std::vector<std::shared_ptr<EntryData>> &entryData)
{
    std::set<QString> uniqueCategorys;
    for(const auto &entry : entryData)
    {
        uniqueCategorys.insert(entry->getCategory());
    }
    QStringList whiteList(uniqueCategorys.begin(), uniqueCategorys.end());
    return whiteList;
}

QStringList Refactorer::createDateList(const std::vector<std::shared_ptr<EntryData>> &entryData)
{
    QStringList uniqueDates;
    for (const auto& entry : entryData)
    {
        QString date = entry->getMonthYear().first + " " + QString::number(entry->getMonthYear().second);
        if (!uniqueDates.contains(date))
        {
            uniqueDates.emplace_back(date);
        }
    }
    return uniqueDates;
}

std::vector<std::pair<QString, double>> Refactorer::createDonutList(const std::vector<std::shared_ptr<EntryData>> &entryData, const QString &month, int year)
{
    std::vector<std::pair<QString, double>> donutList;
    for(const auto &entry : entryData)
    {
        if(entry->getMonthYear().first == month && entry->getMonthYear().second == year)
        {
            donutList.emplace_back(std::pair(entry->getCategory(), entry->getAmount()));
        }
    }
    Sorter::sortDonutListByAmount(donutList);
    return donutList;
}

std::vector<std::shared_ptr<EntryData>> Refactorer::createSpendingsList(const std::vector<std::shared_ptr<EntryData> > &entryData, const QString &month, int year)
{
    std::vector<std::shared_ptr<EntryData>> spendingsList;

    for(const auto &entry : entryData)
    {
        if(entry->getMonthYear().first == month && entry->getMonthYear().second == year)
        {
            spendingsList.emplace_back(entry);
        }
    }
    Sorter::sortSpendingsListByAmount(spendingsList);
    return spendingsList;
}
