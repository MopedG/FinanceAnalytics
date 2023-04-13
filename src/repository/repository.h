#pragma once
#include <vector>
#include <memory>

class EntryData;
class Repository
{
public:
    Repository(std::vector<std::shared_ptr<EntryData>> entryData);

    std::vector<std::shared_ptr<EntryData>> entryData;

    void updateData(std::vector<std::shared_ptr<EntryData>> updatedData);
};


