#pragma once
#include <map>
#include <memory>

class EntryData;
class Repository
{
public:
    Repository() = default;

    std::map<int, std::shared_ptr<EntryData>> entryData;

    void fetchData();
};


