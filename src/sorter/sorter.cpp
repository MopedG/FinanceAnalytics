#include "sorter.h"
#include "EntryWindow/EntryDatahandler/entrydata.h"
#include <algorithm>

std::vector<std::shared_ptr<EntryData> > Sorter::sortByDate(const std::vector<std::shared_ptr<EntryData>> &entryData)
{
    std::vector<std::shared_ptr<EntryData>> sortedData;
    for(const auto &entry : entryData)
    {
        sortedData.emplace_back(entry);
    }

    std::sort(sortedData.begin(), sortedData.end(), [](const auto &a, const auto &b)
    {
        if(a->getMonthYear().second != b->getMonthYear().second)
        {
            return a->getMonthYear().second < b->getMonthYear().second;
        }
        else
            return a->monthToInt(a->getMonthYear().first) < b->monthToInt(b->getMonthYear().first);
    });
    return sortedData;
}

void Sorter::sortSpendingsListByAmount(std::vector<std::pair<QString, double> > &spendingsList)
{
    std::sort(spendingsList.begin(), spendingsList.end(), [](const auto &a, const auto &b)
    {

        return a.second > b.second;

    });
}
