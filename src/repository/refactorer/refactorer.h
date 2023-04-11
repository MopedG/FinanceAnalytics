#pragma once

#include <vector>
#include "EntryWindow/EntryDatahandler/entrydata.h"

class Refactorer
{
public:
    Refactorer();

    static std::vector<std::shared_ptr<EntryData>> combineEntriesByCategory(std::vector<std::shared_ptr<EntryData>> entryData);
};


