#include "repository.h"


Repository::Repository(std::vector<std::shared_ptr<EntryData>> entryData) : entryData(entryData) {}

void Repository::updateData(std::vector<std::shared_ptr<EntryData>> updatedData)
{
    entryData = updatedData;
}

