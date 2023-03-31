#include "sorter.h"
#include "EntryWindow/EntryDatahandler/entrydata.h"
#include <algorithm>

std::vector<std::shared_ptr<EntryData> > Sorter::sortByDate(const std::map<int, std::shared_ptr<EntryData>> &entryData)
{
    std::vector<std::shared_ptr<EntryData>> sortedData;
    for(const auto &entry : entryData)
    {
        sortedData.emplace_back(entry.second);
    }

    std::sort(sortedData.begin(), sortedData.end(), [](const auto &a, const auto &b)
    {
        if(a->getMonthYear().second != b->getMonthYear().second)
        {
            return a->getMonthYear().second < b->getMonthYear().second;
        }
        else
            return a->monthToInt(a->getMonthYear().first) < a->monthToInt(b->getMonthYear().first);
    });
    return sortedData;
}
