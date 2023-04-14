#pragma once

#include <QObject>

class EntryData;
class Sorter
{
public:
    Sorter() = default;

    static std::vector<std::shared_ptr<EntryData>> sortByDate(const std::vector<std::shared_ptr<EntryData>> &entryData);
    static void sortSpendingsListByAmount(std::vector<std::pair<QString, double>> &spendingsList);
};


