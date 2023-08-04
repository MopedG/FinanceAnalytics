#include "entrydatahandler.h"
#include "Time/time.h"

void EntryDatahandler::saveEntry(const QString &category, double amount, int id)
{
    std::shared_ptr<EntryData> data = std::make_shared<EntryData>();
    data->setCategory(category);
    data->setAmount(amount);
    data->setDateChanged(Time::getCurrentDate());
    newEntryData.insert(std::pair(id, data));
}

void EntryDatahandler::editEntry(const QString &category, double amount, int id)
{
    auto data = newEntryData.find(id);
    data->second->setAmount(amount);
    data->second->setCategory(category);
}

void EntryDatahandler::deleteEntry(int id)
{
    newEntryData.erase(id);
}

void EntryDatahandler::saveDateToEntrys(const QString &month, int year)
{
    for(const auto &entry : newEntryData)
    {
        entry.second->setMonthYear(std::pair(month, year));
    }
}
