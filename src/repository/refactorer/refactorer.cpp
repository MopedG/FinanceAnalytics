#include "refactorer.h"
#include <map>

Refactorer::Refactorer()
{

}

std::vector<std::shared_ptr<EntryData>> Refactorer::combineEntriesByCategory(std::vector<std::shared_ptr<EntryData>> entryData)
{
    std::vector<std::shared_ptr<EntryData>> refactoredEntryData;
    std::map<QString, std::shared_ptr<EntryData>> addedEntryData;

        for (const auto& entry : entryData) {
            const QString &category = entry->getCategory();
            const QString &date = entry->getMonthYear().first + QString::number(entry->getMonthYear().second);
            const QString &key = category+date;

            if (addedEntryData.find(key) == addedEntryData.end()) {
                addedEntryData.insert(std::pair(key, entry));
            }
            else
            {
                std::shared_ptr<EntryData> existingEntry = addedEntryData.find(key)->second;
                existingEntry->setAmount(existingEntry->getAmount() + entry->getAmount());

            }
        }

        for (const auto& entry : addedEntryData) {
            refactoredEntryData.push_back(entry.second);
        }


    return refactoredEntryData;
}
