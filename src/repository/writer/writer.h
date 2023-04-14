#pragma once
#include "EntryWindow/EntryDatahandler/entrydata.h"

#include <filesystem>

class Writer
{
public:
    Writer() = default;

    static QStringList serealizeData(const std::vector<std::shared_ptr<EntryData>> &entryData);
    static void writeData(const QStringList &serealizedData);

    static std::filesystem::path getRepositoryFilePath();
};


